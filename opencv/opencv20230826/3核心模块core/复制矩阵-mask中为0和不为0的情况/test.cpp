#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;


int main()
{
	Mat image, mask;
	Rect r1(10, 10, 60, 100);
	Mat img2;
	image = imread("520.jpg");
	mask = Mat::zeros(image.size(), CV_8UC1);
	mask(r1).setTo(255);
	image.copyTo(img2, mask);
	imshow("原图像", image);
	imshow("复制后的目标图像", img2);
	imshow("mask", mask);
	waitKey();

	return 0;
}
