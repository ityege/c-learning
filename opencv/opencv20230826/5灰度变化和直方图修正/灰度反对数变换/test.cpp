#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;


//归一化
//data				进行处理的像素集合
//grayscale			目标灰度级
//rows cols type	目标图像的行，列，以及类型
Mat Normalize(vector<double> data, int grayscale, int rows, int cols, int type)
{
	double max = 0.0;
	double min = 0.0;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] > max)
			max = data[i];
		if (data[i] < min)
			min = data[i];
	}
	Mat dst;
	dst.create(rows, cols, type);
	int index = 0;
	for (int r = 0; r < dst.rows; r++)
	{
		uchar* dstRowData = dst.ptr<uchar>(r);
		for (int c = 0; c < dst.cols; c++)
		{
			dstRowData[c] = (uchar)(grayscale * ((data[index++] - min) * 1.0 / (max - min)));
		}
	}
	return dst;
}

//反对数变换
Mat NegativeLogTransform(Mat src, double parameter)
{
	vector<double> value;
	for (int r = 0; r < src.rows; r++)
	{
		uchar* srcRowData = src.ptr<uchar>(r);
		for (int c = 0; c < src.cols; c++)
		{
			//反对数变换公式为s = ((v + 1) ^ r - 1) / v
			value.push_back((pow(parameter + 1, srcRowData[c]) - 1) / parameter);
		}
	}
	//计算得出的s经过对比拉升（将像素值归一化到0-255）得到最终的图像
	return Normalize(value, 255, src.rows, src.cols, src.type());
}

int main()
{
	Mat srcImg = imread("gza.jpg", 0);//读取源图片转换为灰度图
	if (srcImg.data == NULL)
	{
		cout << "图像打开失败" << endl;
		return -1;
	}
	imshow("原图", srcImg);
	//Mat dstImg = LogTransform(srcImg,0.2);
	Mat dstImg;
	dstImg = NegativeLogTransform(srcImg, 3);
	imshow("变换后", dstImg);
	waitKey(0);
	return 0;

}
