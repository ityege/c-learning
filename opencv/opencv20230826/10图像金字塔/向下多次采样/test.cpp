#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;


int main()
{
	Mat img, r1, r2, r3;
	img = imread("img.jpg", IMREAD_COLOR); 	//读取原始图像
	pyrDown(img, r1);  	//图像向下取样
	pyrDown(r1, r2);
	pyrDown(r2, r3);

	imshow("original", img);  	//显示图像
	imshow("PyrDown1", r1);
	imshow("PyrDown2", r2);
	imshow("PyrDown3", r3);

	waitKey(0);
	destroyAllWindows(); //销毁所有窗口
}
