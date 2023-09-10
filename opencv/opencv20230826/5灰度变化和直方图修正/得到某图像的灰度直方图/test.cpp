#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2\imgproc\types_c.h> //for CV_RGB2GRAY
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;

//绘制灰度直方图
int main(int    argc, char* argv[])
{
	Mat src, gray;
	if (argc == 1)
		src = imread("gza.jpg");  //读取工程目录下的gza.jpg图片
	else if (argc == 2)
		src = imread(argv[1]);

	if (src.empty()) //判断原图是否加载成功
	{
		cout << "图像加载失败" << endl;
		return -1;
	}
	cvtColor(src, gray, CV_RGB2GRAY);   //转换为灰度图
	int bins = 256;
	int hist_size[] = { bins };
	float range[] = { 0, 256 };
	const float* ranges[] = { range };
	MatND hist;
	int channels[] = { 0 };
	//计算出灰度直方图
	calcHist(&gray, 1, channels, Mat(), // do not use mask
		hist, 1, hist_size, ranges,
		true, // the histogram is uniform
		false);
	//画出直方图
	double max_val;
	minMaxLoc(hist, 0, &max_val, 0, 0);  //定位矩阵中最小值、最大值的位置
	int scale = 2;
	int hist_height = 256;
	Mat hist_img = Mat::zeros(hist_height, bins * scale, CV_8UC3); //创建一个全0的特殊矩阵
	for (int i = 0; i < bins; i++)
	{
		float bin_val = hist.at<float>(i);
		int intensity = cvRound(bin_val * hist_height / max_val);  //要绘制的高度
		rectangle(hist_img, Point(i * scale, hist_height - 1),  //画矩形
			Point((i + 1) * scale - 1, hist_height - intensity),
			CV_RGB(255, 255, 255));
	}
	//显示原图和直方图
	imshow("原图片", src);
	imshow("灰度直方图", hist_img);
	waitKey(10000000000);
	return 0;
}
