// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "opencv2/imgcodecs.hpp"
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;

#pragma comment(lib, "opencv_world450d.lib")  //引用引入库 

int main()
{
    Mat r3(Size(3, 3), CV_8UC3);
	cout << "矩阵像素行数="<<r3.rows <<",矩阵像素列数="<<r3.cols << endl;
	cout << "矩阵维数=" << r3.dims << endl;
}

 