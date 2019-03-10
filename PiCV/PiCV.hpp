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
	Chip chip;
	Desc desc;
}
Feat;

bool toGray(Image &image, Gray &gray);
bool toEEM(Landmark &landmark, EEM &eem);
bool toChipTri(Image &image, Landmark &landmark, EEM &tri, cv::Size &box, Chip &chip);
bool toMeasure(Desc &d1, Desc &d2, float &measure);

void showFace(cv::Mat &img, Face &face);
void showLandmark(cv::Mat &img, Landmark &landmark);
void showEEM(cv::Mat &img, EEM &eem);

extern "C"
{
	bool setupVideo(char video_path[]);
	bool readVideoFrame(Image &frame);
	bool getVideoFrame(Image &frame);
	bool showFrame(Image &frame);
	bool showChip(Chip &chip);
	bool drawFace(Image &frame, Face &face);
	bool drawLandmark(Image &frame, Landmark &landmark);

	bool setup();
	bool run();
}

}
