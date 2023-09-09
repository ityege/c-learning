#include <iostream>
#include "opencv2/imgcodecs.hpp"
using namespace cv;  //所有OpenCV类都在命名空间cv下
using namespace std;


int main(void)
{
	Mat r1; //构造无参数矩阵
	Mat	r2(2, 2, CV_8UC1);  //构造两行两列，深度是8位比特的单通道矩阵
	Mat r3(Size(3, 2), CV_8UC3); //构造行数是2，列数是3*通道数，深度是8位比特的3通道矩阵
 //构造4行4列像素，深度是8位比特的2通道矩阵，且每个像素的通道初始值是1和3
	Mat r4(4, 4, CV_8UC2, Scalar(1, 3));
	//构造5行3列像素矩阵，深度是8位比特的3通道矩阵，且每个像素的通道初始值是4,5,6
	Mat r5(Size(3, 5), CV_8UC3, Scalar(4, 5, 6));
	//将r5赋值给r6，公用数据对象
	Mat r6(r5);
	//通过数组初始化矩阵维数
	int sz[2] = { 3, 3 };
	cv::Mat r7(2, sz, CV_8UC1, cv::Scalar::all(1));
	//通过数组初始化矩阵数据
	int a[2][3] = { 1, 2, 3, 4, 5, 6 };
	Mat r8(2, 3, CV_32S, a);   //float 对应的是CV_32F，double对应的是CV_64F，默认为单通道
	cout << r1 << endl << r2 << endl << r3 << endl << r4 << endl << r5 << endl << r6 << endl << r7 << endl << r8;
}
