﻿#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image, image_3c;
	image.create(Size(256, 256), CV_8UC1);
	image_3c.create(Size(256, 256), CV_8UC3);   //3通道的图像
	image.setTo(0);
	image_3c.setTo(0);

	image.at<uchar>(10, 200) = 255;
	image_3c.at<uchar>(10, 200) = 255;
	double maxVal = 0;
	Point maxLoc;
	minMaxLoc(image, NULL, &maxVal, NULL, &maxLoc);
	cout << "单通道图像最大值： " << maxVal << endl;
	double min_3c, max_3c;

	minMaxLoc(image_3c, &min_3c, &max_3c, NULL, NULL);
	cout << "3通道图像最大值: " << max_3c << endl;

	imshow("image", image);
	imshow("image_3c", image_3c);
	waitKey(0);
	return 0;
}