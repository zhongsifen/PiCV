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
#include "dlib_anet.hpp"
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/opencv.h>
#include <opencv2/core.hpp>

namespace PiDL {
	typedef dlib::matrix<dlib::rgb_pixel> Image;
	typedef dlib::matrix<unsigned char> Gray;
	typedef dlib::rectangle Face;
	typedef dlib::full_object_detection Shape;
	typedef dlib::matrix<dlib::rgb_pixel> Chip;
	typedef dlib::matrix<float, 0, 1> Desc;

	typedef struct
	{
		Face face;
		Shape shape;
		Chip chip;
		Desc desc;
	} Feat;

	void fdl(Image & image_d, PiCV::Image & image);
	void fdl(Gray &gray_d, PiCV::Gray &gray);
	void fdl(Face &face_dl, PiCV::Face &face);
	void fdl(Shape &shape_dl, PiCV::Landmark &landmark);
	void fdl(Desc &desc_dl, PiCV::Desc &desc);
	
	void fdl(Feat &feat_dl, PiCV::Feat &feat);

	void tdl(PiCV::Image &image, Image &image_d);
	void tdl(PiCV::Gray &gray, Gray &gray_d);


	extern "C"
	{
		bool setup();
		bool runFace(PiCV::Image &frame, PiCV::Face &face);
		bool runLandmark(PiCV::Image &frame, PiCV::Landmark &landmark);
		bool runChip(PiCV::Image &frame, PiCV::Chip &chip);
		bool runDesc(PiCV::Image &frame, PiCV::Desc &desc);

		bool runFeat(void* image, void* feat);
	}
}; // namespace PiDL

#endif /* PiDL_hpp */
