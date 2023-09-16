 #include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc/types_c.h>
#include <iostream>
using namespace std;
using namespace cv;

void main()
{
	Mat src = imread("test.jpg");
	Rect rect(84, 84, 406, 318);//左上坐标（X,Y）和长宽
	Mat result, bg, fg;

	grabCut(src, result, rect, bg, fg, 1, GC_INIT_WITH_RECT);
	imshow("grab", result);
	/*threshold(result, result, 2, 255, CV_THRESH_BINARY);
	imshow("threshold", result);*/

	compare(result, GC_PR_FGD, result, CMP_EQ);//result和GC_PR_FGD对应像素相等时，目标图像该像素值置为255
	imshow("result", result);
	Mat foreground(src.size(), CV_8UC3, Scalar(255, 255, 255));
	src.copyTo(foreground, result);//copyTo有两种形式，此形式表示result为mask
	imshow("foreground", foreground);
	waitKey(0);
}