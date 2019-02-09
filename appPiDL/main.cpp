#include "PiDL/PiDL.hpp"

char * video_path = nullptr; //{ (char*)"/Users/zhongsifen/Data/48.3gp" };
int main() {
	bool ret = true;

	PiCV::Image frame;
	PiCV::Face face;
	PiCV::setupVideo(video_path);
	PiDL::setup();
	for (;;) {
		ret = readVideoFrame();			if (!ret) break;
		ret = getVideoFrame(frame);		if (!ret) break;
		ret = showVideoFrame(frame);	if (!ret) break;
	}
	// PiDL::runFace(frame, face);

	return 0;
}
