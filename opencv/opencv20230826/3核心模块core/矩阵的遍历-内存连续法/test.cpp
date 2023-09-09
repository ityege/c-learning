#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;


int main()
{
	Mat mymat = cv::Mat::ones(cv::Size(3, 2), CV_8UC3);//定义2行3列3通道矩阵,实际矩阵公有9列
	int nr = mymat.rows;
	int nc = mymat.rows * mymat.channels();
	if (mymat.isContinuous())//判断矩阵存储是否内存连续
	{
		nr = 1;//如果连续,就可以当成一行
		nc = nc * mymat.rows;//当成一行后总列数
	}

	for (int i = 0; i < nr; i++)
	{
		uchar* pdata = mymat.ptr<uchar>(i);//每一行图像的指针
		for (int j = 0; j < nc; j++)
			cout << (int)pdata[j] << "  ";
		cout << endl;
	}
}


