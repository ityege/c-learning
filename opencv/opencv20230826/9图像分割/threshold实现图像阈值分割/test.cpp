#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;

 
void f1(char* image)
{
	cv::Mat gray = imread(image, IMREAD_GRAYSCALE);

	cv::imshow("original", gray);
	// 全局二值化
	int th = 100;
	cv::Mat threshold1, threshold2, threshold3, threshold4, threshold5, threshold6, threshold7, threshold8;
	cv::threshold(gray, threshold1, th, 255, THRESH_BINARY);
	cv::threshold(gray, threshold2, th, 255, THRESH_BINARY_INV);
	cv::threshold(gray, threshold3, th, 255, THRESH_TRUNC);
	cv::threshold(gray, threshold4, th, 255, THRESH_TOZERO);
	cv::threshold(gray, threshold5, th, 255, THRESH_TOZERO_INV);
	//cv::threshold(gray, threshold6, th, 255, THRESH_MASK);
	cv::threshold(gray, threshold7, th, 255, THRESH_OTSU);
	cv::threshold(gray, threshold8, th, 255, THRESH_TRIANGLE);
	cv::imshow("THRESH_BINARY", threshold1);
	cv::imshow("THRESH_BINARY_INV", threshold2);
	cv::imshow("THRESH_TRUNC", threshold3);
	cv::imshow("THRESH_TOZERO", threshold4);
	cv::imshow("THRESH_TOZERO_INV", threshold5);
	//cv::imshow("THRESH_MASK", threshold6);
	cv::imshow("THRESH_OTSU", threshold7);
	cv::imshow("THRESH_TRIANGLE", threshold8);
}

void f2(char* image)
{
	cv::Mat gray = imread(image, IMREAD_GRAYSCALE);

	cv::namedWindow("original");
	cv::imshow("original", gray);

	string windowstring = "result 0";
	string imagestring = "result 0.jpg";
	cv::Mat result;
	enum thresholdtype { THRESH_BINARY, THRESH_BINARY_INV, THRESH_TRUNC, THRESH_TOZERO, THRESH_TOZERO_INV };

	for (int thresh = 0; thresh < 5; thresh++)
	{
		// 0: 二进制阈值,1: 反二进制阈值,2: 截断阈值,3: 0阈值,4: 反0阈值
		threshold(gray, result, 150, 255, thresholdtype(thresh));//改变参数实现不同的threshold
		cv::namedWindow(windowstring);
		cv::imshow(windowstring, result);//显示输出结果
		cv::imwrite(imagestring, result);
		windowstring[7]++;
		imagestring[7]++;
	}
}
int main(void)
{
	f1((char*)"kt.jpg");
	f2((char*)"threshold.jpg");

	waitKey(0); //等待按键响应后退出，0改为5000就是5秒后自动退出。
	return 0;
}
