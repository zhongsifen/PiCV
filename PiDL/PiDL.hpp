//
//  PiDL.hpp
//  PiCV
//
//  Created by SIFEN ZHONG on 4/10/2017.
//  Copyright © 2017 ___ZHONGSIFEN___. All rights reserved.
//

#ifndef PiDL_hpp
#define PiDL_hpp

#include "PiCV/PiCV.hpp"
using namespace PiCV;
#include "PiDLConfig.hpp"
#include <opencv2/opencv.hpp>
#include "dlib_anet.hpp"
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/opencv.h>

namespace PiDLModel {
	const std::string _MODELDAT(PiDLConfig::_M + "model/");
	const std::string _DAT_SP( _MODELDAT + "shape_predictor_68_face_landmarks.dat");
	const std::string _DAT_NET(_MODELDAT + "dlib_face_recognition_resnet_model_v1.dat");
}

class PiDL {
public:
	typedef dlib::matrix<dlib::rgb_pixel> Image_D;
	typedef dlib::matrix<unsigned char> Gray_D;
	typedef dlib::matrix<dlib::rgb_pixel> Chip_D;
	typedef dlib::matrix<float, 0, 1> Desc_D;
	typedef dlib::cv_image<dlib::bgr_pixel> ImageCV_D;

protected:
	dlib::frontal_face_detector _fd;
	dlib::shape_predictor _sp;
	dlib_anet::anet_type _net;

public:
	PiDL();
	~PiDL();

	bool doFace(Gray& gray, Face& face);
	bool doLandmark(Gray & gray, cv::Rect & r, Landmark & landmark);
	bool doChip(Image & image, cv::Rect & r, Chip & chip);
	bool doDesc(Chip & chip, Desc & desc);
	bool doDesc(Image & image, cv::Rect & r, Chip & chip, Desc & desc);
	
	static bool toGray(Image & image, Gray & gray);
	static bool toEEM(Landmark & landmark, EEM & eem);
	static bool toChipTri(Image & image, Landmark & landmark, EEM & tri, cv::Size & box, Chip & chip);
	static bool toMeasure(Desc & d1, Desc & d2, float & measure);

	static void fdlib(Image_D & image_d, Image & image);
	static void fdlib(Gray_D & gray_d, Gray & gray);
	static void tdlib(Image & image, Image_D & image_d);
	static void tdlib(Gray & gray, Gray_D & gray_d);
};

#endif /* PiDL_hpp */
