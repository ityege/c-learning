﻿#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;
int main()
{
	// 载入原图
	Mat image = imread("img.png");
	//创建窗口
	namedWindow("中值滤波【原图】");
	namedWindow("中值滤波【效果图】");
	//显示原图
	imshow("中值滤波【原图】", image);
	//进行中值滤波操作
	Mat out;
	medianBlur(image, out, 7);//输入，输出，7通道
	//显示效果图
	imshow("中值滤波【效果图】", out);
	waitKey(0);
}
