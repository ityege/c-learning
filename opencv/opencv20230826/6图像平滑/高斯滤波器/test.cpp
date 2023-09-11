#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src, dst;
	src = imread("lena.png");
	if (!src.data)
	{
		printf("could not load image3...\n");
		return -1;
	}
	//定义窗口名称
	char input_title[] = "输入图片";
	char output_title[] = "均值滤波";
	//新建窗口
	namedWindow(input_title, WINDOW_AUTOSIZE);
	namedWindow(output_title, WINDOW_AUTOSIZE);

	imshow(input_title, src);//原图显示
	//均值滤波操作
	blur(src, dst, Size(15, 15), Point(-1, -1));//均值滤波，Size里面都要奇数，正数。内核内数值分别表示宽，高。Point（-1，-1）表示锚点，一般取-1，表示锚点在核中心。
	imshow(output_title, dst);

	Mat gblur;
	//高斯滤波操作
	GaussianBlur(src, gblur, Size(15, 15), 11, 11);//高斯滤波
	imshow("高斯滤波", gblur);
	waitKey(0);
	return 0;
}
