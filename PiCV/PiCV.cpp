#include "PiCV.hpp"

void PiCV::run(char * path) {
	cv::VideoCapture capt;
	if (path == nullptr) {
		capt.open(0);
	}
	else {
		capt.open(path);
	}
	if (!capt.isOpened()) return;
	cv::Size sz((int)capt.get(cv::CAP_PROP_FRAME_WIDTH),
				(int)capt.get(cv::CAP_PROP_FRAME_HEIGHT));

	cv::Mat frame;
	for(;;)	{
		capt.read(frame); if (frame.empty()) break;

//		++frameNum;
//		cout << "Frame: " << frameNum << "# ";

		////////////////////////////////// Show frame /////////////////////////////////////////////
		cv::imshow("PiCV", frame);
		int key = cv::waitKey(5);
		if (key == 27) break;
	}



	printf("5: PiCV\n");
}
