#include <iostream>
#include <opencv2\imgproc\types_c.h> //for CV_RGB2GRAY
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 

using namespace std;
using namespace cv;

int main()
{
	Mat	image3 = Mat::zeros(120, 120, CV_8UC3);//生成全零矩阵
	Rect rec1 = Rect(10, 30, 60, 20);//定义矩形对象,左上角坐标是(10,30),宽度是60,高度是20
	Rect rec2 = Rect(30, 10, 20, 60);//定义矩形对昂,左上角坐标是(30,10),宽度是60,高度是20
	rectangle(image3, rec1, Scalar(0, 0, 255), -1, 8, 0);//在images上画横矩形
	rectangle(image3, rec2, Scalar(0, 0, 255), -1, 8, 0);//在images上花竖矩形
	rectangle(image3, Point(10, 30), Point(70, 50), Scalar(0, 255, 255), 2, 8, 0);//黄色矩形镶边
	rectangle(image3, Point(30, 10), Point(50, 70), Scalar(0, 255, 255), 2, 8, 0);//黄色矩形镶边
	rectangle(image3, Point(30, 30), Point(50, 50), Scalar(0, 0, 255), 3, 8);//红色正方形覆盖(中央)
	imshow("红十字", image3);
	waitKey();
	return 0;
}