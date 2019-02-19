// _PiDL.cpp

#include "_PiDL.hpp"
#include "dlib_cv.hpp"

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

bool PiDL::setup()
{
    bool ret = true;
    ret = dlInit();     if (!ret) return false;

    return true;
}

bool PiDL::runFace(Image & frame, Face & face)
{
    bool ret = true;
    tdl(frame, _frame_dl);
    ret = dlGray(_frame_dl, _gray_dl);  if (!ret) return false;
    ret = dlFace(_gray_dl, _face_dl);   if (!ret) return false;
    fdl(_face_dl, face);

    return true;
}

bool PiDL::dlInit()
{
    _fd = dlib::get_frontal_face_detector();
    dlib::deserialize(_DAT_SP) >> _sp;
    dlib::deserialize(_DAT_NET) >> _net;

    return true;
}

bool PiDL::dlGray(Image_DL & image, Gray_DL & gray)
{
    dlib::assign_image<Gray_DL, Image_DL>(gray, image);
    return true;
}

bool PiDL::dlFace(Gray_DL & gray, Face_DL & face)
{
    std::vector<std::pair<double, dlib::rectangle>> dets;
    _fd(gray, dets);

    int n = (int)dets.size();   if (n < 1) return false;
    int i = 0;
    double p = dets[0].first;
    for (int k = 1; k < n; k++)
    {
        double q = dets[k].first;
        if (p < q)
        {
            p = q;
            i = k;
        }
    }

    face = dets[i].second;

    return true;
}

bool PiDL::dlLandmark(Gray &gray, cv::Rect &r, Landmark &landmark);
bool PiDL::dlChip(Image &image, cv::Rect &r, Chip &chip);
bool PiDL::dlDesc(Chip &chip, Desc &desc);
bool PiDL::dlDesc(Image &image, cv::Rect &r, Chip &chip, Desc &desc);

void PiDL::fdl(Image_DL &image_dl, Image &image)
{
    cv::Mat image_r(num_rows(image_dl), num_columns(image_dl), CV_8UC3, image_data(image_dl), width_step(image_dl));
    cv::cvtColor(image_r, image, cv::COLOR_RGB2BGR);
}

void PiDL::fdl(Gray_DL &gray_dl, Gray &gray)
{
    cv::Mat gray_r(num_rows(gray_dl), num_columns(gray_dl), CV_8UC3, image_data(gray_dl), width_step(gray_dl));
    gray = gray_r.clone();
}

void PiDL::fdl(Face_DL &face_dl, Face &face)
{
    face.x = (int)face_dl.left();
    face.y = (int)face_dl.top();
    face.width = (int)(face_dl.right() - face_dl.left() + 1);
    face.height = (int)(face_dl.bottom() - face_dl.top() + 1);
}

void PiDL::tdl(Image &image, Image_DL &image_dl)
{
    ImageCV_DL imagecv_dl(image);
    dlib::assign_image(image_dl, imagecv_dl);
}

void PiDL::tdl(Gray &gray, Gray_DL &gray_dl)
{
    ImageCV_DL graycv_dl(gray);
    dlib::assign_image(gray_dl, graycv_dl);
}
