#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2\imgproc\types_c.h>
#include<iostream>
using namespace std;
using namespace cv;

//Roberts算子实现
Mat roberts(Mat srcImage)
{
	Mat dstImage = srcImage.clone();
	int nRows = dstImage.rows;
	int nCols = dstImage.cols;
	for (int i = 0; i < nRows - 1; i++) {
		for (int j = 0; j < nCols - 1; j++) {
			//根据公式计算
			int t1 = (srcImage.at<uchar>(i, j) -
				srcImage.at<uchar>(i + 1, j + 1)) *
				(srcImage.at<uchar>(i, j) -
					srcImage.at<uchar>(i + 1, j + 1));
			int t2 = (srcImage.at<uchar>(i + 1, j) -
				srcImage.at<uchar>(i, j + 1)) *
				(srcImage.at<uchar>(i + 1, j) -
					srcImage.at<uchar>(i, j + 1));
			//计算g（x,y）
			dstImage.at<uchar>(i, j) = (uchar)sqrt(t1 + t2);
		}
	}
	return dstImage;
}

void main()
{
	Mat srcImage = imread("test.jpg");
	if (!srcImage.data) {
		cout << "falied to read" << endl;
		system("pause");
		return;
	}
	Mat srcGray;
	cvtColor(srcImage, srcGray, CV_BGR2GRAY);
	//高斯滤波
	GaussianBlur(srcGray, srcGray, Size(3, 3),
		0, 0, BORDER_DEFAULT);
	Mat dstImage = roberts(srcGray);
	imshow("srcImage", srcImage);
	imshow("dstImage", dstImage);
	waitKey(0);
}