#include "pch.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp" 
using namespace cv;  //所有opencv类都在命名空间cv下

//#pragma comment(lib, "opencv_world450d.lib")  //引用引入库opencv_world450d.lib
int main(void)
{
	Mat img = imread("test.jpg");// 读入当前工程目录下的一张图片（游戏原画）
	namedWindow("游戏原画");// 创建一个名为 "游戏原画"窗口
	imshow("游戏原画", img);// 在窗口中显示游戏原画
	waitKey(6000);// 等待6000 ms后窗口自动关闭
	return 0;
}
