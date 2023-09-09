#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;


void colorReduce(Mat& image, int div = 64)
{
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			image.at<Vec3b>(i, j)[0] = image.at<Vec3b>(i, j)[0] / div * div + div / 2;
			image.at<Vec3b>(i, j)[1] = image.at<Vec3b>(i, j)[1] / div * div + div / 2;
			image.at<Vec3b>(i, j)[2] = image.at<Vec3b>(i, j)[2] / div * div + div / 2;
		}
	}
}
int main()
{
	Mat A;    //仅仅创建了矩阵头
	A = imread("520.jpg", 1);
	imshow("原图", A);
	colorReduce(A);
	imshow("效果图", A);
	waitKey(0);

}


