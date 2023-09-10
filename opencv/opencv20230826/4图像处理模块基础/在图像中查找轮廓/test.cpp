#include <opencv2/opencv.hpp>
using namespace cv;
#include<iostream>
using namespace std;


#include <opencv2/highgui/highgui_c.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>
int main(int argc, char* argv[])
{
	int op;
	printf("enter 1--4:");
	scanf_s("%d", &op);

	Mat imageSource = imread("test.jpg", 0);
	imshow("Source Image", imageSource);
	Mat image;

	GaussianBlur(imageSource, image, Size(3, 3), 0);
	Canny(image, image, 100, 250);
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	if (op == 1)
		findContours(image, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
	else if (op == 2)
		findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE, Point());
	else if (op == 3)
		findContours(image, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE, Point());
	else if (op == 4)
		findContours(image, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point());

	Mat imageContours = Mat::zeros(image.size(), CV_8UC1);
	Mat Contours = Mat::zeros(image.size(), CV_8UC1);  //绘制  
	for (int i = 0; i < contours.size(); i++)
	{
		//contours[i]代表的是第i个轮廓，contours[i].size()代表的是第i个轮廓上所有的像素点数  
		for (int j = 0; j < contours[i].size(); j++)
		{
			//绘制出contours向量内所有的像素点  
			Point P = Point(contours[i][j].x, contours[i][j].y);
			Contours.at<uchar>(P) = 255;
		}

		//输出hierarchy向量内容  
		char ch[256];
		sprintf_s(ch, "%d", i);
		string str = ch;
		cout << "向量hierarchy的第" << str << " 个元素内容为：" << endl << hierarchy[i] << endl << endl;

		//绘制轮廓  
		drawContours(imageContours, contours, i, Scalar(255), 1, 8, hierarchy);
	}
	imshow("Contours Image", imageContours); //轮廓  
	imshow("Point of Contours", Contours);   //向量contours内保存的所有轮廓点集  
	waitKey(0);
	return 0;
}