// _PiDL.hpp
// typedef dlib::matrix<dlib::rgb_pixel> Image_D;
// typedef dlib::matrix<unsigned char> Gray_D;
// typedef dlib::matrix<dlib::rgb_pixel> Chip_D;
// typedef dlib::matrix<float, 0, 1> Desc_D;
// typedef dlib::cv_image<dlib::bgr_pixel> ImageCV_D;

#ifndef _PiDL_hpp
#define _PiDL_hpp

#include "PiDL.hpp"

namespace PiDL {
    bool dlInit();
    bool dlGray(Image_DL & image, Gray_DL & gray);
    bool dlFace(Gray_DL &gray, Face_DL &face);
    bool dlLandmark(Gray &gray, cv::Rect &r, Landmark &landmark);
    bool dlChip(Image &image, cv::Rect &r, Chip &chip);
    bool dlDesc(Chip &chip, Desc &desc);
    bool dlDesc(Image &image, cv::Rect &r, Chip &chip, Desc &desc);
}

#endif // _PiDL_hpp