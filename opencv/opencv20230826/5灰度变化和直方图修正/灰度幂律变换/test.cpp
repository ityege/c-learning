#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;



int main()
{
	Mat src;
	src = imread("ball.jpg");
	if (src.empty()) //检验是否成功导入数据；
	{
		cout << "not open successed!" << endl;
		return -1;
	}
	namedWindow("input", 0);
	imshow("input", src); // 显示输入的图像src;
	cvtColor(src, src, COLOR_RGB2GRAY);
	Mat grayimg;
	grayimg.create(src.size(), src.type()); //创建一个大小类型相同的图像矩阵序列，也可以用clone()函数；
	int height = src.rows;
	int width = src.cols;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			int gray = src.at< uchar>(i, j);
			grayimg.at< uchar>(i, j) = pow(gray, 0.5);//将灰度值开方；
		}
	normalize(grayimg, grayimg, 0, 255, NORM_MINMAX);//归一化，将数据归一到0-255之间；
	imshow("output", grayimg);//显示图像grayimg；
	waitKey(0);
	return 0;
}
