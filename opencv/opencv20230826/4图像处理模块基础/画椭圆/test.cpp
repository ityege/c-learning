#include <iostream>
#include <opencv2\imgproc\types_c.h> //for CV_RGB2GRAY
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	//绘制丰田车标
	Mat	image1 = Mat::zeros(900, 900, CV_8UC3);//900x900的窗口
	//绘制第一个椭圆,大椭圆
	ellipse(image1, Point(450, 450), Size(400, 250), 0, 0, 360, Scalar(0, 0, 225), 5, 8);//绘制第一个椭圆，大椭圆，颜色为红色
	ellipse(image1, Point(450, 450), Size(250, 110), 90, 0, 360, Scalar(0, 0, 225), 5, 8);//绘制第二个椭圆，竖椭圆
	ellipse(image1, Point(450, 320), Size(280, 120), 0, 0, 360, Scalar(0, 0, 225), 5, 8);//绘制第三个椭圆，小椭圆（横）
	imshow("丰田", image1);
	waitKey();
	return 0;
}
