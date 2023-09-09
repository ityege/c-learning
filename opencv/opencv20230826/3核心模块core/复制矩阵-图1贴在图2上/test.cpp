#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;


int main()
{
	Mat Image1 = imread("520.jpg");
	Mat Image2 = imread("2.jpg");
	imshow("图1原始图", Image1);
	imshow("图2原始图", Image2);
	Mat imagedst = Image1(Rect(0, 0, Image2.cols, Image2.rows));
	Mat mask = imread("2.jpg", 0);
	imshow("mask", mask);
	//进行复制
	Image2.copyTo(imagedst, mask);
	imshow("效果图为", Image1);
	waitKey(0);
	return 0;
}
