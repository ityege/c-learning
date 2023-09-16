﻿ #include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc/types_c.h>
#include <iostream>
using namespace std;
using namespace cv;





//全局变量声明部分
Mat g_srcImage, g_dstImage, g_grayImage, g_maskImage;//定义原始图、目标图、灰度图、掩膜图
int g_nFillMode = 1;//漫水填充的模式
int g_nLowDifference = 20, g_nUpDifference = 20;//负差最大值，正差最大值
int g_nConnectivity = 4;//表示floodFill函数标识符低八位的连通值
bool g_bIsColor = true;//是否为彩色图的标识符布尔值
bool g_bUseMask = false;//是否显示掩膜窗口的布尔值
int g_nNewMaskVal = 255;//新的重新绘制的像素值

//===============【onMouse()函数】=======================
static void onMouse(int event, int x, int y, int, void*) {
	//若鼠标左键没有按下，便返回
	if (event != EVENT_LBUTTONDOWN)
		return;

	//-----------------【<1>调用floodFill函数之前的参数准备部分】-------------
	Point seed = Point(x, y);
	int LowDifference = g_nFillMode == 0 ? 0 : g_nLowDifference;
	int UpDifference = g_nFillMode == 0 ? 0 : g_nUpDifference;

	//标识符的0~7位为g_nConnectivity，8~15位为g_nNewMaskVal左移8位的值，16~23位为CV_FLOODFILL_FIXED_RANGE或者0
	int flags = g_nConnectivity + (g_nNewMaskVal << 8) + (g_nFillMode == 1 ? FLOODFILL_FIXED_RANGE : 0);

	//随机生成BGR值
	int b = (unsigned)theRNG() & 255;//随机返回一个0~255之间的值
	int g = (unsigned)theRNG() & 255;
	int r = (unsigned)theRNG() & 255;
	Rect ccomp;//定义重绘区域的最小边界矩阵区域

	Scalar newVal = g_bIsColor ? Scalar(b, g, r) : Scalar(r * 0.299 + g * 0.587 + b * 0.114);

	Mat dst = g_bIsColor ? g_dstImage : g_grayImage;//目标图的赋值
	int area;

	//---------------------【<2>正式调用floodFill函数】------------------
	if (g_bUseMask) {
		threshold(g_maskImage, g_maskImage, 1, 128, THRESH_BINARY);

		area = floodFill(dst, g_maskImage, seed, newVal, &ccomp, Scalar(LowDifference, LowDifference, LowDifference), Scalar(UpDifference, UpDifference, UpDifference), flags);

		imshow("mask", g_maskImage);
	}
	else {
		area = floodFill(dst, seed, newVal, &ccomp, Scalar(LowDifference, LowDifference, LowDifference), Scalar(UpDifference, UpDifference, UpDifference), flags);
	}
	imshow("效果图", dst);
	cout << area << " 个像素被重新绘制\n";
}

//main()函数
int main(int argc, char** argv) {
	//载入原图
	g_srcImage = imread("test.jpg", 1);
	if (!g_srcImage.data) {
		printf("读取g_srcImage错误！\n");
		return false;
	}

	g_srcImage.copyTo(g_dstImage);//复制原图到目标图
	cvtColor(g_srcImage, g_grayImage, COLOR_BGR2GRAY);//转为灰度图到g_grayImage

	g_maskImage.create(g_srcImage.rows + 2, g_srcImage.cols + 2, CV_8UC1);//用原图尺寸初始化掩膜mask

	namedWindow("效果图", WINDOW_AUTOSIZE);

	//创建Trackbar
	createTrackbar("负差最大值", "效果图", &g_nLowDifference, 255, 0);
	createTrackbar("正差最大值", "效果图", &g_nUpDifference, 255, 0);

	//鼠标回调函数
	setMouseCallback("效果图", onMouse, 0);

	//循环轮询按键
	while (1) {
		//先显示效果图
		imshow("效果图", g_bIsColor ? g_dstImage : g_grayImage);

		//获取按键键盘
		int c = waitKey(0);
		//判断ESC是否按下，按下退出
		if (c == 27) {
			cout << "程序退出........、\n";
			break;
		}

		//根据按键不同进行不同的操作
		switch ((char)c) {
			//如果键盘1被按下，效果图在灰度图和彩色图之间转换
		case '1':
			if (g_bIsColor) {//若原来为彩色图，转换为灰度图，并将掩膜mask所有元素设置为0
				cout << "键盘‘1’按下，切换彩色/灰度模式，当前操作将【彩色模式】切换为【灰度模式】" << endl;
				cvtColor(g_srcImage, g_grayImage, COLOR_BGR2GRAY);
				g_maskImage = Scalar::all(0);//将mask所有元素设置为0
				g_bIsColor = false;
			}
			else {
				cout << "键盘‘1’按下，切换彩色/灰度模式，当前操作将【灰度模式】切换为【彩色模式】" << endl;
				g_srcImage.copyTo(g_dstImage);
				g_maskImage = Scalar::all(0);
				g_bIsColor = true;
			}
		case '2':
			if (g_bUseMask) {
				destroyWindow("mask");
				g_bUseMask = false;
			}
			else {
				namedWindow("mask", 0);
				g_maskImage = Scalar::all(0);
				imshow("mask", g_maskImage);
				g_bUseMask = true;
			}
			break;
		case '3'://如果键盘3被按下，恢复原始图像
			cout << "按下键盘‘3’，恢复原始图像\n";
			g_srcImage.copyTo(g_dstImage);
			cvtColor(g_srcImage, g_grayImage, COLOR_BGR2GRAY);
			g_maskImage = Scalar::all(0);
			break;
		case '4':
			cout << "键盘‘4’被按下，使用空范围的漫水填充\n";
			g_nFillMode = 0;
			break;
		case '5':
			cout << "键盘‘5’被按下，使用渐变、固定范围的漫水填充\n";
			g_nFillMode = 1;
			break;
		case '6':
			cout << "键盘‘6’被按下，使用渐变、浮动范围的漫水填充\n";
			g_nFillMode = 2;
			break;
		case '7':
			cout << "键盘‘7’被按下，操作标识符的低八位使用4位的连接模式\n";
			g_nConnectivity = 4;
			break;
		case '8':
			cout << "键盘‘8’被按下，操作标识符的低八位使用8为的连接模式\n";
			g_nConnectivity = 8;
			break;
		}

	}

	return 0;

}