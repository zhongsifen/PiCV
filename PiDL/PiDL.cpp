//
//  PiDL.cpp
//  Mien
//
//  Created by SIFEN ZHONG on 12/10/2017.
//  Copyright © 2017 ___ZHONGSIFEN___. All rights reserved.
//

#include "PiDL.hpp"
#include "dlib_cv.hpp"
#include <opencv2/opencv.hpp>

//#include <dlib/gui_widgets.h>

namespace PiDL {
	dlib::frontal_face_detector _fd;
	dlib::shape_predictor _sp;
	dlib_anet::anet_type _net;

	cv::VideoCapture _capt;
} // namespace PiDL

bool PiDL::setup(char video_path[])
{
		if (video_path == nullptr)
		{
			_capt.open(0);
		}
		else
		{
			_capt.open(video_path);
		}
		if (!_capt.isOpened())
			return false;
		// cv::Size sz((int)capt.get(cv::CAP_PROP_FRAME_WIDTH),
		// 			(int)capt.get(cv::CAP_PROP_FRAME_HEIGHT));

		_fd = dlib::get_frontal_face_detector();
		dlib::deserialize(_DAT_SP) >> _sp;
		dlib::deserialize(_DAT_NET) >> _net;

		return true;
}

bool PiDL::quit()
{
	return true;
}

bool PiDL::run()
{
	cv::Mat frame;
	for (;;)
	{
		_capt.read(frame);
		if (frame.empty())
			break;

		////////////////////////////////// Show frame /////////////////////////////////////////////
		cv::imshow("PiCV", frame);
		int key = cv::waitKey(5);
		if (key == 27)
			break;
	}
	
	return true;
}

bool PiDL::runFace(Image & frame, Face & face)
{
	for (;;) {
		_capt.read(frame);		if (frame.empty()) break;
		Gray gray;
		toGray(frame, gray);
		doFace(gray, face);

		cv::Mat s = frame.clone();
		showFace(s, face);
		cv::imshow("PiCV", s);
		int key = cv::waitKey(5);		if (key == 27) break;
	}
	return true;
}

bool PiDL::doFace(Gray & gray, Face & face)
{
	std::vector<std::pair<double, dlib::rectangle>> dets;
	_fd(dlib::cv_image<uint8_t>(gray), dets);

	int n = (int)dets.size();	if (n < 1) return false;
	int i = 0;
	double p = dets[i].first;
	for (int k = 1; k < n; k++) {
		double q = dets[k].first;
		if (p < q) {
			p = q;
			i = k;
		}
	}

	dlib_cv::fdlib(dets[i].second, face);

	return true;
}

bool PiDL::doLandmark(Gray & gray, cv::Rect & r, Landmark & landmark)
{
	dlib::cv_image<uint8_t> gray_d(gray);
	dlib::rectangle r_d;
	dlib_cv::tdlib(r, r_d);
	dlib::full_object_detection shape = _sp(gray_d, r_d);
	int n = shape.num_parts();
	if (n < 1) return false;
	landmark.resize(n);
	for (int i = 0; i < n; i++) {
		dlib_cv::fdlib(shape.part(i), landmark[i]);
	}

	return true;
}

bool PiDL::doChip(Image & image, cv::Rect & r, Chip & chip)
{
	Image_D image_d;
	tdlib(image, image_d);
	dlib::rectangle r_d;
	dlib_cv::tdlib(r, r_d);
	dlib::full_object_detection shape = _sp(image_d, r_d);
	int n = shape.num_parts();	if (n < 1) return false;
	Chip_D chip_d;
	extract_image_chip(image_d, get_face_chip_details(shape, 150, 0.25), chip_d);
	fdlib(chip_d, chip);

	return true;
}

bool PiDL::doDesc(Chip & chip, Desc & desc)
{
	Chip_D chip_d;
	tdlib(chip, chip_d);
	std::vector<Chip_D> chips(1, chip_d);
	desc = dlib::toMat(_net(chips)[0]);

	return true;
}

bool PiDL::doDesc(Image & image, cv::Rect & r, Chip & chip, Desc & desc)
{
	Image_D image_d;
	tdlib(image, image_d);
	Gray gray;
	PiCV::toGray(image, gray);
	Gray_D gray_d;
	tdlib(gray, gray_d);
	dlib::rectangle r_d;
	dlib_cv::tdlib(r, r_d);
	dlib::full_object_detection shape = _sp(gray_d, r_d);
	int n = shape.num_parts();
	if (n < 1) return false;
	Chip_D chip_d;
	extract_image_chip(image_d, get_face_chip_details(shape, 150, 0.25), chip_d);
	chip = dlib::toMat(chip_d);
	std::vector<Chip_D> chips(1, chip_d);
	desc = dlib::toMat(_net(chips)[0]);

	return true;
}

void PiDL::fdlib(Image_D & image_d, Image & image)
{
	cv::Mat image_r(num_rows(image_d), num_columns(image_d), CV_8UC3, image_data(image_d), width_step(image_d));
	cv::cvtColor(image_r, image, cv::COLOR_RGB2BGR);
}

void PiDL::fdlib(Gray_D & gray_d, Gray & gray)
{
	cv::Mat gray_r(num_rows(gray_d), num_columns(gray_d), CV_8UC3, image_data(gray_d), width_step(gray_d));
	gray = gray_r.clone();
}

void PiDL::tdlib(Image & image, Image_D & image_d)
{
	ImageCV_D imagecv_d(image);
	dlib::assign_image(image_d, imagecv_d);
}

void PiDL::tdlib(Gray & gray, Gray_D & gray_d)
{
	ImageCV_D graycv_d(gray);
	dlib::assign_image(gray_d, graycv_d);
}
