#include <iostream>
#include <opencv2\imgproc\types_c.h> //for CV_RGB2GRAY
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	//绘制奥迪Audi车标
	Mat image2 = Mat::zeros(500, 850, CV_8UC3);//生成一个500*850的Mat矩阵
	//画一个实心圆
	circle(image2, Point(447, 63), 63, (0, 0, 255), -1);
	//开始绘制奥迪图标
	//绘制第一个圆,半径为100,圆心为(200,300),颜色为紫色
	circle(image2, Point(200, 300), 100, Scalar(225, 0, 225), 7, 8);
	//绘制第二个圆,半径为100,圆心为(350,300),颜色为紫色
	circle(image2, Point(350, 300), 100, Scalar(225, 0, 225), 7, 8);
	//绘制第三个圆, 半径为100, 圆心为(500, 300), 颜色为紫色
	circle(image2, Point(500, 300), 100, Scalar(225, 0, 225), 7, 8);
	//绘制第四个圆, 半径为100, 圆心为(650, 300), 颜色为紫色
	circle(image2, Point(650, 300), 100, Scalar(225, 0, 225), 7, 8);
	imshow("奥迪车标", image2);
	waitKey();
	return 0;
}
