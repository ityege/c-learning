#include "pch.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//#pragma comment(lib, "opencv_world450d.lib")


int main(void)
{
	double alpha = 0.5; double beta; double input;
	Mat src1, src2, dst;

	/// Ask the user enter alpha
	cout << " 线性混合 " << endl;
	cout << "* 输入第一副图片的权重alpha [0.0-1.0]: ";
	cin >> input;

	// We use the alpha provided by the user if it is between 0 and 1
	if (input >= 0 && input <= 1)
		alpha = input;
 

	/// Read images ( both have to be of the same size and type )
	src1 = imread("p1.jpg");
	src2 = imread("成本华.jpg");
 
	if (src1.empty()) { cout << "Error loading src1" << endl; return -1; }
	if (src2.empty()) { cout << "Error loading src2" << endl; return -1; }

	beta = (1.0 - alpha);
	addWeighted(src1, alpha, src2, beta, 0.0, dst);//将图1与图2线性混合
  
	imshow("混合后的图片",dst);
 
	waitKey(0);
 
	return 0;
}