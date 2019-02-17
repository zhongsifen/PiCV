// _PiDL.cpp

#include "_PiDL.hpp"

namespace PiDL
{
dlib::frontal_face_detector _fd;
dlib::shape_predictor _sp;
dlib_anet::anet_type _net;

Image_DL _frame_dl;
Gray_DL _gray_dl;
Face_DL _face_dl;
Chip_DL _chip_dl;

} // namespace PiDL

bool PiDL::dlInit()
{
    _fd = dlib::get_frontal_face_detector();
    dlib::deserialize(_DAT_SP) >> _sp;
    dlib::deserialize(_DAT_NET) >> _net;

    return true;
}

bool PiDL::dlFace(Gray &gray, Face &face);
bool PiDL::dlLandmark(Gray &gray, cv::Rect &r, Landmark &landmark);
bool PiDL::dlChip(Image &image, cv::Rect &r, Chip &chip);
bool PiDL::dlDesc(Chip &chip, Desc &desc);
bool PiDL::dlDesc(Image &image, cv::Rect &r, Chip &chip, Desc &desc);
