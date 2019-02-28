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

namespace PiDL {
	typedef dlib::matrix<dlib::rgb_pixel> Image_DL;
	typedef dlib::matrix<unsigned char> Gray_DL;
	typedef dlib::rectangle Face_DL;
	typedef dlib::full_object_detection Shape_DL;
	typedef dlib::matrix<dlib::rgb_pixel> Chip_DL;
	typedef dlib::matrix<float, 0, 1> Desc_DL;

	typedef dlib::cv_image<dlib::bgr_pixel> ImageCV_DL;

	void fdl(Image_DL & image_d, Image & image);
	void fdl(Gray_DL & gray_d, Gray & gray);
	void fdl(Face_DL & face_dl, Face & face);
	void fdl(Shape_DL &shape_dl, Landmark &landmark);
	void fdl(Desc_DL &desc_dl, Desc &desc);
	
	void tdl(Image & image, Image_DL & image_d);
	void tdl(Gray & gray, Gray_DL & gray_d);
	
	typedef enum {
		NONE,
		INIT,
		FACE,
		LANDMARK,
		CHIP,
	} 
	Stage;

	bool doInit();
	bool doFace(Gray &gray, Face &face);
	bool doLandmark(Gray &gray, cv::Rect &r, Landmark &landmark);
	bool doChip(Image &image, cv::Rect &r, Chip &chip);
	bool doDesc(Chip &chip, Desc &desc);
	bool doDesc(Image &image, cv::Rect &r, Chip &chip, Desc &desc);

	extern "C"
	{
		bool setup();
		bool runFace(Image & frame, Face & face);
		bool runLandmark(Image & frame, Landmark &landmark);
		bool runChip(Image & frame, Chip & chip);
		bool runDesc(Image & frame, Desc & desc);
	}
}; // namespace PiDL

#endif /* PiDL_hpp */
