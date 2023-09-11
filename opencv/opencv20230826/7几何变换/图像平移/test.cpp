#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>


//平移操作，图像大小不变
cv::Mat imageTranslation1(cv::Mat& srcImage, int x0ffset, int y0ffset)
{
	int nRows = srcImage.rows;
	int nCols = srcImage.cols;
	cv::Mat resultImage(srcImage.size(), srcImage.type());
	//遍历图像
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			//映射变换
			int x = j - x0ffset;
			int y = i - y0ffset;
			//边界判断
			if (x >= 0 && y >= 0 && x < nCols && y < nRows)
			{
				//将行y列x的srcImage上的图像元素值复制到目标图像(i,j)位置上
				resultImage.at<cv::Vec3b>(i, j) = srcImage.ptr<cv::Vec3b>(y)[x];
			}
		}
	}
	return resultImage;
}
//平移操作，图形大小改变
cv::Mat imageTranslation2(cv::Mat& srcImage, int x0ffset, int y0ffset)
{
	//设置平移尺寸
	//这里是区分,先对目标图像的行进行扩展,扩展到原来图像的行列范围,再加上偏移量绝对值
	int nRows = srcImage.rows + abs(y0ffset);
	int nCols = srcImage.cols + abs(x0ffset);
	cv::Mat resultImage(nRows, nCols, srcImage.type());
	//图像遍历
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			int x = j - x0ffset;
			int y = i - y0ffset;
			//边界判断
			if (x >= 0 && y >= 0 && x < nCols && y < nRows)
			{
				resultImage.at<cv::Vec3b>(i, j) = srcImage.ptr<cv::Vec3b>(y)[x];
			}
		}
	}
	return resultImage;
}

int main()
{
	//读取图像
	cv::Mat srcImage = cv::imread("img.jpg");
	if (srcImage.empty())
	{
		return -1;
	}

	//显示原图像
	cv::imshow("原图像", srcImage);
	int x0ffset = 50;
	int y0ffset = 80;
	//图像左平移,不改变大小(相对于原图像,目标图像左移了)
	cv::Mat resultImage1 = imageTranslation1(srcImage, x0ffset, y0ffset);
	cv::imshow("resultImage1", resultImage1);
	//图像左平移改变大小
	cv::Mat resultImage2 = imageTranslation2(srcImage, x0ffset, y0ffset);
	cv::imshow("resultImage2", resultImage2);
	//图像右平移,不改变大小
	x0ffset = -50;
	y0ffset = -80;
	cv::Mat resultImage3 = imageTranslation1(srcImage, x0ffset, y0ffset);
	cv::imshow("resultImage3", resultImage3);
	cv::waitKey(0);
	return 0;
}