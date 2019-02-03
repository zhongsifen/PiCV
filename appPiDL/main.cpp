#include "PiDL/PiDL.hpp"

char * video_path = nullptr; //{ (char*)"/Users/zhongsifen/Data/48.3gp" };
int main() {
	PiCV::Image frame;
	PiCV::Face face;
	PiCV::setupVideo(video_path);
	PiDL::runFace(frame, face);
	PiDL::quit();
	
	return 0;
}
