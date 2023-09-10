#include <iostream>
#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;

void grayImageShow(cv::Mat& input, cv::Mat& output)
{
	for (int i = 0; i < input.rows; ++i)
		for (int j = 0; j < input.cols; ++j)
			output.at<uchar>(i, j) = cv::saturate_cast<uchar>(0.114 * input.at<cv::Vec3b>(i, j)[0] + 0.587 * input.at<cv::Vec3b>(i, j)[1] + 0.2989 * input.at<cv::Vec3b>(i, j)[2]);
	cv::imshow("由经验公式得到的灰度图像", output);
}

int main(void)
{
	cv::Mat src, gray, dst;

	gray = cv::imread("Lena.jpg", cv::IMREAD_GRAYSCALE);//由imread()得到的灰度图像
	src = cv::imread("Lena.jpg");
	dst.create(src.rows, src.cols, CV_8UC1);

	cv::imshow("scr", src);
	cv::imshow("由imread得到的灰度图像", gray);
	grayImageShow(src, dst);//由经验公式得到的灰度图像
	waitKey(-1); //按键后再继续

	return 0;
}