#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>



using namespace std;
using namespace cv;

int main()
{
	// 读取图片
	Mat srcImage = imread("djy.jpg");

	if (!srcImage.data)   //Check for invalid input
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}

	Mat dstImage1, dstImage2;
	Mat tempImage = srcImage;
	// 显示图片 
	imshow("原图", srcImage);

	// 图片的缩小
	resize(tempImage, dstImage1, Size(tempImage.cols / 2, tempImage.rows / 2), 0, 0, INTER_NEAREST);
	// 图片的放大
	resize(tempImage, dstImage2, Size(tempImage.cols * 2, tempImage.rows * 2), 0, 0, INTER_NEAREST);

	imshow("缩小图", dstImage1);
	imshow("放大图", dstImage2);

	waitKey();
	return 0;
}