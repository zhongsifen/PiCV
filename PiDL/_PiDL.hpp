// _PiDL.hpp

#ifndef _PiDL_hpp
#define _PiDL_hpp

#include "PiDL.hpp"

namespace PiDL {
    bool dlInit();
    bool dlGray(Image_DL & image, Gray_DL & gray);
    bool dlFace(Gray_DL & gray, Face_DL & face);
    bool dlShape(Gray_DL &gray, Face_DL &face, Shape_DL &shape);
    bool dlLandmark(Shape_DL &shape, Landmark_DL &landmark);
    bool dlChip(Image_DL &image, Shape_DL &shape, Chip_DL &chip);
    bool dlDesc(Chip &chip, Desc &desc);
    bool dlDesc(Image &image, cv::Rect &r, Chip &chip, Desc &desc);

    bool descr(cv::Mat &cvimg, dlib::matrix<rgb_pixel> &chip, dlib::matrix<float, 0, 1> &descr);
}

#endif // _PiDL_hpp