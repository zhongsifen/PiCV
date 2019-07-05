#include "PiDL/PiDL.hpp"

char * video_path = nullptr; //{ (char*)"/Users/zhongsifen/Data/48.3gp" };
int main() {
	bool ret = true;

	PiCV::Image frame;
	PiCV::Feat feat;

	PiCV::setupVideo(video_path);
	PiDL::setup();
	for (;;) {
		ret = PiCV::readVideo(frame);			if (!ret) continue;
		ret = PiDL::runFeat(&frame, &feat);			if (!ret) continue;
		ret = PiCV::showFeat(frame, feat);			if (!ret) break;
	}

	return 0;
}
