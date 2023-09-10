#include <opencv2/opencv.hpp>
using namespace cv;
#include<iostream>
using namespace std;


#include <opencv2/highgui/highgui_c.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
int main(int argc, char** argv)
{
	Mat src, dst;
	int borderType = BORDER_CONSTANT;
	const char* window_name = "copyMakeBorder Demo";
	RNG rng(12345);
	int top, bottom, left, right;
	const char* imageName = argc >= 2 ? argv[1] : "test.jpg";
	// Loads an image 加载图片
	src = imread(samples::findFile(imageName), IMREAD_COLOR); // Load an image
	// Check if image is loaded fine
	if (src.empty()) {
		printf(" Error opening image\n");
		printf(" Program Arguments: [image_name -- default lena.jpg] \n");
		return -1;
	}
	// Brief how-to for this program
	printf("\n \t copyMakeBorder Demo: \n");
	printf("\t -------------------- \n");
	printf(" ** Press 'c' to set the border to a random constant value \n");
	printf(" ** Press 'r' to set the border to be replicated \n");
	printf(" ** Press 'ESC' to exit the program \n");
	namedWindow(window_name, WINDOW_AUTOSIZE);
	// Initialize arguments for the filter
	//初始化筛选器的参数
	top = (int)(0.05 * src.rows);
	bottom = top;
	left = (int)(0.05 * src.cols);
	right = left;
	for (;;)
	{
		Scalar value(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		copyMakeBorder(src, dst, top, bottom, left, right, borderType, value);
		imshow(window_name, dst);
		char c = (char)waitKey(500);
		if (c == 27)//esc退出
		{
			break;
		}
		else if (c == 'c')
		{
			borderType = BORDER_CONSTANT;
		}
		else if (c == 'r')
		{
			borderType = BORDER_REPLICATE;
		}
	}
	return 0;
}