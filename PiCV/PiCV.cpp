#include "_PiCV.hpp"

bool PiCV::setupVideo(char video_path[]) {
	if (video_path == nullptr) _capt.open(0);
	else _capt.open(video_path);

	return _capt.isOpened();
}

bool PiCV::readVideoFrame() {
	_capt.read(_frame); if (_frame.empty()) return false;

	return true;
}

bool PiCV::showVideoFrame() {
	cv::imshow("PiCV", _frame);
	if (cv::waitKey(5) == 27) return false;

	return true;
}

bool PiCV::getVideoFrame(cv::Mat & frame) { 
	frame = _frame;

	return true;
}

bool PiCV::run()
{
	bool ret = true;

	for (;;) {
		ret = readVideoFrame();	if (ret == false) return false;
		ret = showVideoFrame();	if (ret == false) return false;
	}

	return true;
}
