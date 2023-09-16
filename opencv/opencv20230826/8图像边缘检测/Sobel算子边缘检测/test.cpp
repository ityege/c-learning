#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int main()
{
	//读取图像，黑白图像边缘检测结果较为明显
	Mat img = imread("test.jpg", IMREAD_ANYCOLOR);
	if (img.empty())
	{
		cout << "请确认图像文件名称是否正确" << endl;
		return -1;
	}
	Mat resultX, resultY, resultXY;
	Sobel(img, resultX, CV_16S, 2, 0, 1);//X方向一阶边缘
	convertScaleAbs(resultX, resultX);
	Sobel(img, resultY, CV_16S, 0, 1, 3);//Y方向一阶边缘
	convertScaleAbs(resultY, resultY);
	resultXY = resultX + resultY;//整幅图像的一阶边缘
	//显示图像
	imshow("原图像", img);
	imshow("resultX", resultX);
	imshow("resultY", resultY);
	imshow("resultXY", resultXY);
	waitKey(0);
	return 0;
}