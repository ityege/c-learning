#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;


int main()
{
	Mat img, r1, r2;
	img = imread("img.jpg", IMREAD_COLOR); 	//读取原始图像
	pyrDown(img, r1);  	//图像向下取样
	pyrUp(r1, r2);

	imshow("original", img);  	//显示图像
	imshow("PyrDown1", r1);
	imshow("PyrUp", r2);

	waitKey(0);
	destroyAllWindows(); //销毁所有窗口
}
