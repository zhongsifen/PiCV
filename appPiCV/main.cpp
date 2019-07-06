#include "PiCV/PiCV.hpp"

char * path = nullptr; //{ (char*)"/Users/zhongsifen/Data/48.3gp" };
int main() {
	PiCV::cv_setup(path);
	PiCV::cv_run();
	
	return 0;
}
