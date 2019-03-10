#include "PiDL/PiDL.hpp"

char * video_path = nullptr; //{ (char*)"/Users/zhongsifen/Data/48.3gp" };
int main() {
	bool ret = true;

	PiCV::Image frame;
	PiCV::Face face;
	PiCV::Landmark landmark;
	PiCV::Chip chip;
	PiCV::Desc desc;

	PiCV::setupVideo(video_path);
	PiDL::setup();
	for (;;) {
		ret = PiCV::readVideoFrame(frame);			if (!ret) continue;
		ret = PiDL::runFace(frame, face);			if (!ret) continue;
		ret = PiDL::runLandmark(frame, landmark);	if (!ret) continue;
		ret = PiDL::runChip(frame, chip);			if (!ret) continue;
		ret = PiDL::runDesc(frame, desc);
		ret = PiCV::drawFace(frame, face);			if (!ret) continue;
		ret = PiCV::drawLandmark(frame, landmark);	if (!ret) continue;
		ret = PiCV::showFrame(frame);				if (!ret) break;
		ret = PiCV::showChip(chip);
	}

	return 0;
}
