#include "PiDL/PiDL.hpp"
using namespace PiDL;

char * video_path = nullptr; //{ (char*)"/Users/zhongsifen/Data/48.3gp" };
int main() {
	bool ret = true;

	PiCV::Image frame;
	PiCV::Face face;
	PiCV::Landmark landmark;
	PiCV::Chip chip;

	PiCV::setupVideo(video_path);
	PiDL::setup();
	for (;;) {
		ret = readVideoFrame(frame);			if (!ret) continue;
		ret = runFace(frame, face);				if (!ret) continue;
		ret = runLandmark(frame, landmark);		if (!ret) continue;
		ret = runChip(frame, chip);				if (!ret) continue;
		ret = drawFace(frame, face);			if (!ret) continue;
		ret = drawLandmark(frame, landmark);	if (!ret) continue;
		ret = showFrame(frame);					if (!ret) break;
		ret = showChip(chip);
	}

	return 0;
}
