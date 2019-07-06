#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>

namespace PiCV {
// const int _nfp =  68;	// number of feature points
// const int _ndv = 128;	// number of description values

typedef cv::Mat Image;
typedef cv::Mat_<uint8_t> Gray;
typedef cv::Rect Face;
typedef std::vector<cv::Point> Landmark;
typedef std::vector<cv::Point2f> EEM;
typedef cv::Mat Chip;
typedef std::vector<float> Desc;

typedef struct {
	Face face;
	Landmark landmark;
	Chip chip;
	Desc desc;
}
Feat;


extern "C"
{
	bool setupVideo(char video_path[]);
	bool readVideo(Image &image);
	bool showImage(Image &image);
	bool showChip(Chip &chip);
	bool drawFace(Image &frame, Face &face);
	bool drawLandmark(Image &frame, Landmark &landmark);
	bool showFeat(Image &image, Feat &feat);

	bool link(void* mat, uint8_t *data, int32_t *rows, int32_t *cols, int32_t *channels);
	bool copy(void* mat, uint8_t *data, int32_t *rows, int32_t *cols, int32_t *channels);

	bool cv_setup(char video_path[] = nullptr);
	bool cv_read(Image *image = nullptr);
	bool cv_run();
}

}
