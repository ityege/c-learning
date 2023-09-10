#include <opencv2/opencv.hpp>
#include <iostream>
 

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("img.png");
	Mat src2 = imread("img2.png");

	if (src.empty() || src2.empty()) {
		printf("不能加载图像！\n");
		return -1;
	}
	Mat gray, gray2, dst, dst2;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	cvtColor(src2, gray2, COLOR_BGR2GRAY);
	imshow("1--原图", gray);
	imshow("11--原图", gray2);
	equalizeHist(gray, dst);
	equalizeHist(gray2, dst2);
	imshow("2--直方图均衡化", dst);
	imshow("22--直方图均衡化", dst2);

	waitKey(0);
	return 0;
}