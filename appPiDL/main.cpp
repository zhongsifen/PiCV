#include "PiDL/PiDL.hpp"
using namespace PiDL;

char * video_path = nullptr; //{ (char*)"/Users/zhongsifen/Data/48.3gp" };
int main() {
	bool ret = true;

	PiCV::Image frame;
	PiCV::Face face;
	PiCV::Landmark landmark;
	PiCV::setupVideo(video_path);
	PiDL::setup();
	for (;;) {
		ret = readVideoFrame(frame);			if (!ret) break;
		ret = runFace(frame, face);
		ret = runLandmark(frame, landmark);
		ret = drawFace(frame, face);
		ret = drawLandmark(frame, landmark);
		ret = showFrame(frame);	if (!ret) break;
	}

	return 0;
}
