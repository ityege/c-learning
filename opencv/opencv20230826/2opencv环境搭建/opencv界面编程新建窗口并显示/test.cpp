#include "pch.h"
#include <opencv2/highgui/highgui_c.h>
#include <opencv2\opencv.hpp>

using namespace cv;
 
int main()
{
	Mat img;
	img = imread("test.jpg",1);//参数1：图片路径。参数2:显示原图
	namedWindow("窗口1", WINDOW_AUTOSIZE);//WINDOW_AUTOSIZE 时，表示窗口大小自动适应图片大小，并且不可手动更改
	imshow("窗口1",img);//在“窗口1”这个窗口输出图片。
	waitKey(5000);//等待5秒，程序自动退出。改为0，不自动退出。
	return 0;
}