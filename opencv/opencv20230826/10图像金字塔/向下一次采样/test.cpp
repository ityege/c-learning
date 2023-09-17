#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
 

int main()
{
	Mat img, dst;
	//读取原始图像
	img = imread("img.jpg", IMREAD_COLOR);

	//图像向下取样
	pyrDown(img, dst);
	//显示图像
	imshow("original", img);
	imshow("PyrDown", dst);
	waitKey(0);
	destroyAllWindows();
}