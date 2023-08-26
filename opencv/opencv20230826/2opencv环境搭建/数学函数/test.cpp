#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	cout << "cvRound(2.5) : " << cvRound(2.5) << endl;
	cout << "cvRound(2.6) : " << cvRound(2.6) << endl;
	cout << "cvRound(2.8) : " << cvRound(2.8) << endl;

	cout << "cvFloor(2.5) : " << cvFloor(2.5) << endl;
	cout << "cvFloor(2.6) : " << cvFloor(2.6) << endl;
	cout << "cvCeil(2.5)  : " << cvCeil(2.5) << endl;
	cout << "cvCeil(2.6)  : " << cvCeil(2.6) << endl;
	return 0;
}