#include <opencv2/core/core.hpp>              
#include <opencv2/highgui/highgui.hpp>              
#include <opencv2/imgproc/imgproc.hpp>                
#include <opencv2\imgproc\types_c.h>

using namespace cv;
int main()
{
	Mat img = imread("test.jpg");
	Mat dst1;
	Mat dst2;
	Mat dst3;
	cv::cvtColor(img, img, COLOR_RGB2GRAY);//进行，灰度处理
	medianBlur(img, img, 5);//中值滤波
	threshold(img, dst1, 127, 255, THRESH_BINARY);//阈值分割
	adaptiveThreshold(img, dst2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);//自动阈值分割,邻域均值
	adaptiveThreshold(img, dst3, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);//自动阈值分割，高斯邻域
	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	imshow("img", img);
	waitKey(0);
}
