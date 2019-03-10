// _PiDL.hpp

#ifndef _PiDL_hpp
#define _PiDL_hpp

#include "PiDL.hpp"

namespace PiDL {
    bool dlInit();
    bool dlGray(Image & image, GrayImage & gray);
    bool dlFace(GrayImage & gray, FaceImage & face);
    bool dlShape(GrayImage &gray, FaceImage &face, ShapeImage &shape);
    bool dlChip(Image &image, ShapeImage &shape, ChipImage &chip);
    bool dlDesc(ChipImage &chip, DescImage &desc);
    // bool dlDesc(Image &image, cv::Rect &r, Chip &chip, Desc &desc);

    bool descr(cv::Mat &cvimg, dlib::matrix<rgb_pixel> &chip, dlib::matrix<float, 0, 1> &descr);
}

#endif // _PiDL_hpp