// ctypes.cpp

#include "ctypes.hpp"
#include "PiCV.hpp"

bool PiCV::lnk(void *image, uint8_t *data, int32_t *rows, int32_t *cols, int32_t *channels)
{
    cv::Mat* mat = (cv::Mat*)image;
    data = mat->data;
    *rows = mat->rows;
    *cols = mat->cols;
    *channels = mat->channels();

    return true;
}

bool PiCV::cpy(void *image, uint8_t *data, int32_t *rows, int32_t *cols, int32_t *channels)
{
    cv::Mat *mat = (cv::Mat *)image;
    data = mat->data;
    *rows = mat->rows;
    *cols = mat->cols;
    *channels = mat->channels();

    return true;
}
