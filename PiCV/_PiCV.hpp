//
//  _PiCV.hpp
//  PiCV
//
//  Created by SIFEN ZHONG on 12/21/18.
//

#ifndef _PiCV_h
#define _PiCV_h

#include "PiCV.hpp"

namespace PiCV {
	bool toGray(Image & image, Gray & gray);
	bool toEEM(Landmark & landmark, EEM & eem);
	bool toChipTri(Image & image, Landmark & landmark, EEM & tri, cv::Size & box, Chip & chip);
	bool toMeasure(Desc & d1, Desc & d2, float & measure);
	
	void showFace(cv::Mat & img, Face & face);
	void showLandmark(cv::Mat & img, Landmark & landmark);
	void showEEM(cv::Mat & img, EEM & eem);
}

#endif /* _PiCV_h */
