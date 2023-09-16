 #include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc/types_c.h>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
	Mat src = imread("test.jpg");
	imshow("【原始图】", src);
	Rect ccomp;
	floodFill(src, Point(50, 300), Scalar(155, 255, 55), &ccomp, Scalar(20, 20, 20), Scalar(20, 20, 20));
	imshow("【效果图】", src);
	waitKey(0);
	return 0;
}