#include <opencv2/highgui/highgui_c.h>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	int op = 1;

	printf("extract hline(1),vline(2),letter(3):");
	scanf_s("%d", &op);
	Mat src, dst;
	if (op == 3) src = imread("test2.jpg");
	else src = imread("test.jpg");
	if (!src.data)
	{
		cout << "could not load the image..." << endl;
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	char OUTPUT_WIN[] = "result image";
	namedWindow(OUTPUT_WIN, CV_WINDOW_AUTOSIZE);

	//转换为灰度图像
	Mat gray_src;
	cvtColor(src, gray_src, CV_BGR2GRAY);
	imshow("gray image", gray_src);
	//转换为二值图像 自适应阈值进行转换  注意 : 灰度图像取反，设置背景为黑色,目标为白色
	Mat binImg;
	adaptiveThreshold(~gray_src, binImg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
	imshow("binary image", binImg);

	//设置膨胀腐蚀结构元素形状 -- 水平线和垂直线
	Mat hline = getStructuringElement(MORPH_RECT, Size(src.cols / 16, 1));  //水平线
	Mat vline = getStructuringElement(MORPH_RECT, Size(1, src.rows / 16));  //垂直线

	if (op == 1)//提取水平线： 开操作（先腐蚀后膨胀）
	{
		Mat temp;
		erode(binImg, temp, hline);
		dilate(temp, dst, hline);
		bitwise_not(dst, dst);  //颜色翻转与原图一致

		//提取完后滤波一下可以使图像更圆滑
		blur(dst, dst, Size(3, 3), Point(-1, -1));
		imshow(OUTPUT_WIN, dst);

	}
	else if (op == 2)
	{
		//提取垂直线, 开操作可以调用：morphologyEx()函数
		Mat temp1;
		erode(binImg, temp1, vline);
		dilate(temp1, dst, vline);
		bitwise_not(dst, dst);
		morphologyEx(binImg, dst, CV_MOP_OPEN, vline);//膨胀操作API
		bitwise_not(dst, dst);

		//提取完后滤波一下可以使图像更圆滑
		blur(dst, dst, Size(3, 3), Point(-1, -1));
		imshow(OUTPUT_WIN, dst);
	}
	else if (op == 3)
	{
		//定义一个 矩形结构元素,去干扰线
		Mat kernel = getStructuringElement(MORPH_RECT, Size(7, 7));
		morphologyEx(binImg, dst, CV_MOP_OPEN, kernel);
		bitwise_not(dst, dst);
		imshow(OUTPUT_WIN, dst);
	}


	waitKey(0);
	return 0;
}