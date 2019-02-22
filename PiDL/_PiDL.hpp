// _PiDL.hpp

#ifndef _PiDL_hpp
#define _PiDL_hpp

#include "PiDL.hpp"

namespace PiDL {
    bool dlInit();
    bool dlGray(Image_DL & image, Gray_DL & gray);
    bool dlFace(Gray_DL & gray, Face_DL & face);
    bool dlLandmark(Gray_DL & gray, Face_DL & face, Landmark_DL & landmark);
    bool dlChip(Image &image, cv::Rect &r, Chip &chip);
    bool dlDesc(Chip &chip, Desc &desc);
    bool dlDesc(Image &image, cv::Rect &r, Chip &chip, Desc &desc);
}

#endif // _PiDL_hpp