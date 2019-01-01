//
//  _PiCV.cpp
//  PiCV
//
//  Created by SIFEN ZHONG on 12/21/18.
//

#include "_PiCV.hpp"

bool PiCV::toGray(Image & image, Gray & gray)
{
	cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
	
	return true;
}

bool PiCV::toEEM(Landmark & landmark, EEM & eem)
{
	eem.resize(3);
	if (landmark.size() == 5) {
		cv::Point2f e1(landmark[0]);
		cv::Point2f e2(landmark[1]);
		cv::Point2f m1(landmark[3]);
		cv::Point2f m2(landmark[4]);
		
		eem[0] = e1;
		eem[1] = e2;
		eem[2] = (m1 + m2) / 2;
	}
	else if (landmark.size() == 68) {
		cv::Point2f e1f(landmark[36]);
		cv::Point2f e1n(landmark[39]);
		cv::Point2f e2f(landmark[45]);
		cv::Point2f e2n(landmark[42]);
		cv::Point2f m1(landmark[48]);
		cv::Point2f m2(landmark[54]);
		
		eem[0] = (e1f + e1n) / 2;
		eem[1] = (e2f + e2n) / 2;
		eem[2] = (m1 + m2) / 2;
	}
	else {
		return false;
	}
	
	return true;
}

bool PiCV::toChipTri(Image & image, Landmark & landmark, EEM & tri, cv::Size & box, Chip & chip)
{
	EEM eem;
	toEEM(landmark, eem);
	cv::Mat aff = cv::getAffineTransform(eem, tri);
	cv::warpAffine(image, chip, aff, box);
	
	return true;
}

//bool PiCV::toChipTri(Image & image, EEM & eem, EEM & tri, cv::Size & box, Chip & chip)
//{
//	cv::Mat aff = cv::getAffineTransform(eem, tri);
//	cv::warpAffine(image, chip, aff, box);
//
//	return true;
//}

bool PiCV::toMeasure(Desc & d1, Desc & d2, float & measure)
{
	float* data1 = (float*)d1.data;
	float* data2 = (float*)d2.data;
	int n = _ndv;	// d1.rows;
	float s = 0.0F;
	for (int i = 0; i < n; i++) {
		float r = data1[i] - data2[i];
		s += r * r;
	}
	s /= (float)n;
	s = sqrt(s);
	
	return s;
}


void PiCV::showFace(cv::Mat & img, Face & face)
{
	cv::rectangle(img, face, cv::Scalar(0x00, 0xFF, 0x00));
}

void PiCV::showLandmark(cv::Mat & img, Landmark & landmark)
{
	for (int k = 0; k < landmark.size(); k++) {
		cv::circle(img, landmark[k], 2, cv::Scalar(0x00, 0x00, 0xFF));
	}
}

void PiCV::showEEM(cv::Mat & img, EEM & eem) {
	for (int k = 0; k < eem.size(); k++) {
		cv::circle(img, eem[k], 2, cv::Scalar(0xFF, 0xFF, 0x00));
	}
}
