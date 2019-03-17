#include "PiCV.hpp"

namespace PiCV
{
cv::VideoCapture _capt;
} // namespace PiCV

bool PiCV::setupVideo(char video_path[]) {
	if (video_path == nullptr) _capt.open(0);
	else _capt.open(video_path);

	return _capt.isOpened();
}

bool PiCV::readVideo(Image &image)
{
	_capt.read(image); if (image.empty()) return false;

	return true;
}

bool PiCV::showImage(Image &frame)
{
	cv::imshow("PiCV", frame);
	if (cv::waitKey(1) == 27) return false;

	return true;
}

bool PiCV::showChip(Image &frame)
{
	cv::imshow("PiCV: Chip", frame);
	if (cv::waitKey(1) == 27) return false;

	return true;
}

bool PiCV::showFeat(Image &image, Feat &feat)
{
	bool ret = true;

	ret = showChip(feat.chip);	if (!ret) return false;
	drawFace(image, feat.face);
	drawLandmark(image, feat.landmark);
	showImage(image);	if (!ret) return false;

	return true;
}

bool PiCV::drawFace(Image &frame, Face &face)
{
	cv::rectangle(frame, face, cv::Scalar(0x00, 0xFF, 0x00));

	return true;
}

bool PiCV::drawLandmark(Image &frame, Landmark &landmark)
{
	int n = landmark.size();	if (n<1) return false;
	for (int i=0; i<n; i++) {
		cv::circle(frame, landmark[i], 4, cv::Scalar(0xF0, 0xF0, 0xF0));
	}

	return true;
}

bool PiCV::run()
{
	bool ret = true;
	Image frame;
	for (;;) {
		ret = readVideo(frame);	if (!ret) break;
		ret = showImage(frame);			if (!ret) break;
	}

	return true;
}
