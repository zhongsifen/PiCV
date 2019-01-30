#include "PiDL/PiDL.hpp"

char * video_path = { (char*)"/Users/zhongsifen/Data/48.3gp" };
int main() {
	PiDL::setup(video_path);
	PiDL::run();
	PiDL::quit();
	
	return 0;
}
