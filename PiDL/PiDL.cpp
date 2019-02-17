//
//  PiDL.cpp
//  Mien
//
//  Created by SIFEN ZHONG on 12/10/2017.
//  Copyright © 2017 ___ZHONGSIFEN___. All rights reserved.
//

#include "PiDL.hpp"
#include "dlib_cv.hpp"

namespace PiDL {
extern dlib::frontal_face_detector _fd;
extern dlib::shape_predictor _sp;
extern dlib_anet::anet_type _net;

Image _frame;
Gray _gray;
Face _face;

Stage _stage = NONE;
} // namespace PiDL

bool PiDL::setup()
{
	bool ret = true;
	ret = doInit();		if (ret == false) return false;

	return true;
}

bool PiDL::runFace(Image & frame, Face & face)
{
	bool ret = true;
	ret = toGray(_frame, _gray);	if (!ret) return false;
	ret = doFace(_gray, _face);		if (!ret) return false;
	frame = _frame;
	face = _face;

	return true;
}

bool PiDL::doInit() {
	_fd = dlib::get_frontal_face_detector();
	dlib::deserialize(_DAT_SP) >> _sp;
	dlib::deserialize(_DAT_NET) >> _net;

	_stage = INIT;
	return true;
}

bool PiDL::doFace(Gray & gray, Face & face)
{
	if (_stage < INIT) return false;

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

	_stage = FACE;
	return true;
}

bool PiDL::doLandmark(Gray & gray, cv::Rect & r, Landmark & landmark)
{
	dlib::cv_image<uint8_t> gray_dl(gray);
	dlib::rectangle r_dl;
	dlib_cv::tdlib(r, r_dl);
	dlib::full_object_detection shape = _sp(gray_dl, r_dl);
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
	Image_DL image_dl;
	tdlib(image, image_dl);
	dlib::rectangle r_dl;
	dlib_cv::tdlib(r, r_dl);
	dlib::full_object_detection shape = _sp(image_dl, r_dl);
	int n = shape.num_parts();	if (n < 1) return false;
	Chip_DL chip_dl;
	extract_image_chip(image_dl, get_face_chip_details(shape, 150, 0.25), chip_dl);
	fdlib(chip_dl, chip);

	return true;
}

bool PiDL::doDesc(Chip & chip, Desc & desc)
{
	Chip_DL chip_dl;
	tdlib(chip, chip_dl);
	std::vector<Chip_DL> chips(1, chip_dl);
	desc = dlib::toMat(_net(chips)[0]);

	return true;
}

bool PiDL::doDesc(Image & image, cv::Rect & r, Chip & chip, Desc & desc)
{
	Image_DL image_dl;
	tdlib(image, image_dl);
	Gray gray;
	PiCV::toGray(image, gray);
	Gray_DL gray_dl;
	tdlib(gray, gray_dl);
	dlib::rectangle r_dl;
	dlib_cv::tdlib(r, r_dl);
	dlib::full_object_detection shape = _sp(gray_dl, r_dl);
	int n = shape.num_parts();
	if (n < 1) return false;
	Chip_DL chip_dl;
	extract_image_chip(image_dl, get_face_chip_details(shape, 150, 0.25), chip_dl);
	chip = dlib::toMat(chip_dl);
	std::vector<Chip_DL> chips(1, chip_dl);
	desc = dlib::toMat(_net(chips)[0]);

	return true;
}

void PiDL::fdlib(Image_DL & image_dl, Image & image)
{
	cv::Mat image_r(num_rows(image_dl), num_columns(image_dl), CV_8UC3, image_data(image_dl), width_step(image_dl));
	cv::cvtColor(image_r, image, cv::COLOR_RGB2BGR);
}

void PiDL::fdlib(Gray_DL & gray_dl, Gray & gray)
{
	cv::Mat gray_r(num_rows(gray_dl), num_columns(gray_dl), CV_8UC3, image_data(gray_dl), width_step(gray_dl));
	gray = gray_r.clone();
}

void PiDL::tdlib(Image & image, Image_DL & image_dl)
{
	ImageCV_DL imagecv_dl(image);
	dlib::assign_image(image_dl, imagecv_dl);
}

void PiDL::tdlib(Gray & gray, Gray_DL & gray_dl)
{
	ImageCV_DL graycv_dl(gray);
	dlib::assign_image(gray_dl, graycv_dl);
}
