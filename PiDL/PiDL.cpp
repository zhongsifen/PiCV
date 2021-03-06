// _PiDL.cpp

#include "_PiDL.hpp"
#include "dlib_cv.hpp"

namespace PiDL
{
dlib::frontal_face_detector _fd;
dlib::shape_predictor _sp;
dlib_anet::anet_type _net;

Image _image;
Gray _gray_dl;
Face _face_dl;
Shape _shape_dl;
Chip _chip_dl;
Desc _desc_dl;

enum {
	NONE,
	INIT,
	FACE,
	LANDMARK,
	CHIP,
}
_stage;

} // namespace PiDL

bool PiDL::setup()
{
    bool ret = true;
    ret = dlInit();     if (!ret) return false;

    return true;
}

bool PiDL::runFace(PiCV::Image &frame, PiCV::Face &face)
{
    bool ret = true;
    tdl(frame, _image);
    ret = dlGray(_image, _gray_dl);  if (!ret) return false;
    ret = dlFace(_gray_dl, _face_dl);   if (!ret) return false;
    fdl(_face_dl, face);

    return true;
}

bool PiDL::runLandmark(PiCV::Image &frame, PiCV::Landmark &landmark)
{
    bool ret = true;
    tdl(frame, _image);
    ret = dlGray(_image, _gray_dl);  if (!ret) return false;
    ret = dlFace(_gray_dl, _face_dl);   if (!ret) return false;
    ret = dlShape(_gray_dl, _face_dl, _shape_dl); if (!ret) return false;
    fdl(_shape_dl, landmark);
 
    return true;
}

bool PiDL::runChip(PiCV::Image &frame, PiCV::Chip &chip)
{
    bool ret = true;
    tdl(frame, _image);
    ret = dlGray(_image, _gray_dl);  if (!ret) return false;
    ret = dlFace(_gray_dl, _face_dl);   if (!ret) return false;
    ret = dlShape(_gray_dl, _face_dl, _shape_dl); if (!ret) return false;
    ret = dlChip(_image, _shape_dl, _chip_dl); if (!ret) return false;
    fdl(_chip_dl, chip);

    return true;
}

bool PiDL::runDesc(PiCV::Image &frame, PiCV::Desc &desc)
{
    bool ret = true;
    tdl(frame, _image);
    ret = dlGray(_image, _gray_dl);  if (!ret) return false;
    ret = dlFace(_gray_dl, _face_dl);   if (!ret) return false;
    ret = dlShape(_gray_dl, _face_dl, _shape_dl); if (!ret) return false;
    ret = dlChip(_image, _shape_dl, _chip_dl); if (!ret) return false;
    ret = dlDesc(_chip_dl, _desc_dl);
    fdl(_desc_dl, desc);

    return true;
}

bool PiDL::runFeat(void *p_image, void *p_feat)
{
    PiCV::Image *cv_image = (PiCV::Image*)p_image;
    PiCV::Feat *cv_feat = (PiCV::Feat*)p_feat;
    Image image;
    Feat feat;
    tdl(*cv_image, image);
    dlFeat(image, feat);
    fdl(feat, *cv_feat);

    return true;
}

bool PiDL::dlInit()
{
    _fd = dlib::get_frontal_face_detector();
    dlib::deserialize(_DAT_SP) >> _sp;
    dlib::deserialize(_DAT_NET) >> _net;
    _stage = INIT;

    return true;
}

bool PiDL::dlFeat(Image & image, Feat & feat)
{
    Gray gray;
 
    dlGray(image, gray);
    dlFace(gray, feat.face);
    dlShape(gray, feat.face, feat.shape);
    dlChip(image, feat.shape, feat.chip);
    dlDesc(feat.chip, feat.desc);

    return true;
}

bool PiDL::dlGray(Image & image, Gray & gray)
{
    dlib::assign_image<Gray, Image>(gray, image);
    return true;
}

bool PiDL::dlFace(Gray & gray, Face & face)
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

bool PiDL::dlShape(Gray &gray, Face &face, Shape &shape)
{
    dlib::full_object_detection fo = _sp(gray, face);
    int n = fo.num_parts();     if (n < 1) return false;
    shape = fo;

    return true;
}

bool PiDL::dlChip(Image &image,  Shape &shape, Chip &chip)
{
    if (shape.num_parts() < 1) return false;
    dlib::extract_image_chip(image, dlib::get_face_chip_details(shape, 150, 0.25), chip);

    return true;
}

bool PiDL::dlDesc(Chip &chip, Desc &desc)
{
    std::vector<Chip> chips(1, chip);
    std::vector<Desc> descs(1);

    descs = _net(chips);

    desc = descs[0];

    return true;
}

void PiDL::fdl(Image &image_dl, PiCV::Image &image)
{
    cv::Mat image_r(num_rows(image_dl), num_columns(image_dl), CV_8UC3, image_data(image_dl), width_step(image_dl));
    cv::cvtColor(image_r, image, cv::COLOR_RGB2BGR);
}

void PiDL::fdl(Gray &gray_dl, PiCV::Gray &gray)
{
    cv::Mat gray_r(num_rows(gray_dl), num_columns(gray_dl), CV_8UC3, image_data(gray_dl), width_step(gray_dl));
    gray = gray_r.clone();
}

void PiDL::fdl(Face &face_dl, PiCV::Face &face)
{
    face.x = (int)face_dl.left();
    face.y = (int)face_dl.top();
    face.width = (int)(face_dl.right() - face_dl.left() + 1);
    face.height = (int)(face_dl.bottom() - face_dl.top() + 1);
}

void PiDL::fdl(Shape &shape_dl, PiCV::Landmark &landmark)
{
    int n = shape_dl.num_parts();
    landmark.resize(n);
    for (int i=0; i<n; i++) {
        landmark[i].x = shape_dl.part(i).x();
        landmark[i].y = shape_dl.part(i).y();
    }
}

void PiDL::fdl(Desc &desc_dl, PiCV::Desc &desc)
{
    int n = desc_dl.nr();
    desc.resize(n);
    for (int i=0; i<n; i++) {
        desc[i] = desc_dl(i);
    }
}

void PiDL::fdl(Feat &feat_dl, PiCV::Feat &feat)
{
    fdl(feat_dl.face, feat.face);
    fdl(feat_dl.shape, feat.landmark);
    fdl(feat_dl.chip, feat.chip);
    fdl(feat_dl.desc, feat.desc);
}

void PiDL::tdl(PiCV::Image &image, Image &image_dl)
{
    dlib::cv_image<dlib::bgr_pixel> imagecv_dl(image);
    dlib::assign_image(image_dl, imagecv_dl);
}

void PiDL::tdl(PiCV::Gray &gray, Gray &gray_dl)
{
    dlib::cv_image<dlib::bgr_pixel> graycv_dl(gray);
    dlib::assign_image(gray_dl, graycv_dl);
}
