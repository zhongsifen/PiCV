#include "_PiCV.hpp"

bool PiCV::setupVideo(char video_path[]) {
	if (video_path == nullptr) _capt.open(0);
	else _capt.open(video_path);

	return _capt.isOpened();
}

bool PiCV::readVideoFrame(Image & frame)
{
	_capt.read(_frame); if (_frame.empty()) return false;
	frame = _frame;

	return true;
}

bool PiCV::getVideoFrame(Image & frame) { 
	frame = _frame;

	return true;
}

bool PiCV::showFrame(Image &frame)
{
	cv::imshow("PiCV", frame);
	if (cv::waitKey(5) == 27)
		return false;

	return true;
}

bool PiCV::drawFace(Image &frame, Face &face)
{
	cv::rectangle(frame, face, cv::Scalar(0x00, 0xFF, 0x00));

	return true;
}

bool PiCV::run()
{
	bool ret = true;
	Image frame;
	for (;;) {
		ret = readVideoFrame(frame);	if (!ret) break;
		ret = showFrame(frame);			if (!ret) break;
	}

	return true;
}
