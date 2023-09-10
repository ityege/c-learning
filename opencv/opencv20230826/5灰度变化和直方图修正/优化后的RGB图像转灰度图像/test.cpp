#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

bool rgb2gray(unsigned char* src, unsigned char* dest, int width, int height)
{
	int r, g, b;
	for (int i = 0; i < width * height; ++i)
	{
		r = *src++; // load red
		g = *src++; // load green
		b = *src++; // load blue
		// build weighted average:
		*dest++ = (r * 76 + g * 150 + b * 30) >> 8;
	}
	return true;
}


int main()
{
	Mat src, gray, dst;
	src = cv::imread("Lena.jpg");
	dst.create(src.rows, src.cols, CV_8UC1);

	cv::imshow("scr", src);
	rgb2gray(src.data, dst.data, src.cols, src.rows);//由经验公式得到的灰度图像
	cv::imshow("由优化后的基于经验公式得到的灰度图像", dst);
	waitKey(-1); //按键后再继续
}

