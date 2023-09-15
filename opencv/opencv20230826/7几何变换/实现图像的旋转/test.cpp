#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;


// 图像旋转
void Rotate(const Mat& srcImage, Mat& destImage, double angle)//angle表示要旋转的角度
{
	Point2f center(srcImage.cols / 2, srcImage.rows / 2);//中心
	Mat M = getRotationMatrix2D(center, angle, 1);//计算旋转的仿射变换矩阵 
	//现在把旋转应用到仿射变换得输出
	warpAffine(srcImage, destImage, M, Size(srcImage.cols, srcImage.rows));
	//仿射变换  
	circle(destImage, center, 2, Scalar(255, 0, 0));
}

int main()
{
	//读入图像，并判断图像是否读入正确
	cv::Mat srcImage = imread("img.png");
	if (!srcImage.data)
	{
		puts("打开图像文件失败");
		return -1;
	}
	imshow("srcImage", srcImage);//源图像也绘制出来作为参照
	//将图片按比例缩放至宽为250像素的大小
	Mat destImage;
	double angle = 9.9;//角度
	Rotate(srcImage, destImage, angle);
	//最后把仿射变换和旋转得结果绘制在窗口中
	imshow("dst", destImage);
	waitKey(0);
	return 0;
}
