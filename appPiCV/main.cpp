#include "PiCV/PiCV.hpp"

char * path = nullptr; //{ (char*)"/Users/zhongsifen/Data/48.3gp" };
int main() {
	PiCV::setupVideo(path);
	PiCV::run();
	
	return 0;
}
