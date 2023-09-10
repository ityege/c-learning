﻿#include <opencv2/opencv.hpp>  //头文件
#include <iostream>



using namespace cv;  //包含cv命名空间
using namespace std;

/**
matInput:输入图像
matOutput:输出图像
fStart:分段区间起点
fEnd:分段区间终点
fSout:映射区间起点
fEout:映射区间终点

注:支持单通道8为灰度图像
*/
void dividedLinearStrength(cv::Mat& matInput, cv::Mat& matOutput, float fStart, float fEnd,
	float fSout, float fEout)
{
	//计算直线参数
	//L1
	float fK1 = fSout / fStart;
	//L2
	float fK2 = (fEout - fSout) / (fEnd - fStart);
	float fC2 = fSout - fK2 * fStart;
	//L3
	float fK3 = (255.0f - fEout) / (255.0f - fEnd);
	float fC3 = 255.0f - fK3 * 255.0f;

	//建立查询表
	std::vector<unsigned char> loolUpTable(256);
	for (size_t m = 0; m < 256; m++)
	{
		if (m < fStart)
		{
			loolUpTable[m] = static_cast<unsigned char>(m * fK1);
		}
		else if (m > fEnd)
		{
			loolUpTable[m] = static_cast<unsigned char>(m * fK3 + fC3);
		}
		else
		{
			loolUpTable[m] = static_cast<unsigned char>(m * fK2 + fC2);
		}
	}

	//构建输出图像
	matOutput = cv::Mat::zeros(matInput.rows, matInput.cols, matInput.type());
	//灰度映射
	for (size_t r = 0; r < matInput.rows; r++)
	{
		unsigned char* pInput = matInput.data + r * matInput.step[0];
		unsigned char* pOutput = matOutput.data + r * matOutput.step[0];
		for (size_t c = 0; c < matInput.cols; c++)
		{
			//查表gamma变换
			pOutput[c] = loolUpTable[pInput[c]];
		}
	}
}
int main()
{
	cv::Mat matSrc = cv::imread("img.jpg", cv::IMREAD_GRAYSCALE);
	cv::imshow("原始图", matSrc);
	cv::Mat matDLS;
	dividedLinearStrength(matSrc, matDLS, 72, 200, 5, 240);
	cv::imshow("分段线性拉伸", matDLS);
	cv::waitKey(0);
	return 0;
}
