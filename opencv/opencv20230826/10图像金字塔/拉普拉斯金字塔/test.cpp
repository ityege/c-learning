#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/highgui/highgui_c.h>
using namespace std;
using namespace cv;


//拉普拉斯 边缘计算
void TLaplacian()
{
	Mat img1, img2, gray_img, edge_img;

	const char* win1 = "window1";
	const char* win2 = "window2";
	const char* win3 = "window3";
	const char* win4 = "window4";

	namedWindow(win1, CV_WINDOW_AUTOSIZE);
	namedWindow(win2, CV_WINDOW_AUTOSIZE);
	namedWindow(win3, CV_WINDOW_AUTOSIZE);
	namedWindow(win4, CV_WINDOW_AUTOSIZE);

	img1 = imread("img.jpg");//读取图片
	if (img1.empty())
	{
		cout << "could not found image" << endl;
		return;
	}

	//高斯模糊，去掉噪点
	GaussianBlur(img1, img2, Size(3, 3), 0, 0);
	//转为灰度图
	cvtColor(img2, gray_img, CV_BGR2GRAY);
	//拉普拉斯
	Laplacian(gray_img, edge_img, CV_16S, 3);
	convertScaleAbs(edge_img, edge_img);

	threshold(edge_img, edge_img, 2, 255, THRESH_OTSU | THRESH_BINARY);

	imshow(win1, img1);
	imshow(win2, img2);
	imshow(win3, gray_img);
	imshow(win4, edge_img);
}

int main()
{
	TLaplacian();

	waitKey(0);
	return 0;
}