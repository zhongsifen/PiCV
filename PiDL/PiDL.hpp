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
#include "PiDLConfig.hpp"
#include <opencv2/opencv.hpp>
#include "dlib_anet.hpp"
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/opencv.h>

namespace PiDL {
	typedef dlib::matrix<dlib::rgb_pixel> Image;
	typedef dlib::matrix<unsigned char> GrayImage;
	typedef dlib::rectangle FaceImage;
	typedef dlib::full_object_detection ShapeImage;
	typedef dlib::matrix<dlib::rgb_pixel> ChipImage;
	typedef dlib::matrix<float, 0, 1> DescImage;

	// typedef dlib::cv_image<dlib::bgr_pixel> ImageCVImage;

	void fdl(Image & image_d, PiCV::Image & image);
	void fdl(GrayImage &gray_d, PiCV::Gray &gray);
	void fdl(FaceImage &face_dl, PiCV::Face &face);
	void fdl(ShapeImage &shape_dl, PiCV::Landmark &landmark);
	void fdl(DescImage &desc_dl, PiCV::Desc &desc);

	void tdl(PiCV::Image &image, Image &image_d);
	void tdl(PiCV::Gray &gray, GrayImage &gray_d);

	// typedef enum {
	// 	NONE,
	// 	INIT,
	// 	FACE,
	// 	LANDMARK,
	// 	CHIP,
	// } 
	// Stage;

	// bool doInit();
	// bool doFace(Gray &gray, Face &face);
	// bool doLandmark(Gray &gray, cv::Rect &r, Landmark &landmark);
	// bool doChip(Image &image, cv::Rect &r, Chip &chip);
	// bool doDesc(Chip &chip, Desc &desc);
	// bool doDesc(Image &image, cv::Rect &r, Chip &chip, Desc &desc);

	extern "C"
	{
		bool setup();
		bool runFace(PiCV::Image &frame, PiCV::Face &face);
		bool runLandmark(PiCV::Image &frame, PiCV::Landmark &landmark);
		bool runChip(PiCV::Image &frame, PiCV::Chip &chip);
		bool runDesc(PiCV::Image &frame, PiCV::Desc &desc);
	}
}; // namespace PiDL

#endif /* PiDL_hpp */
