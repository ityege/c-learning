#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;


int main()
{
	Mat mymat = cv::Mat::ones(cv::Size(3, 2), CV_8UC3);//定义2行3列3通道矩阵,实际矩阵公有9列
	uchar* pdata = (uchar*)mymat.data;

	for (int i = 0; i < mymat.rows; i++)
	{
		for (int j = 0; j < mymat.cols * mymat.channels(); j++)
			cout << (int)pdata[j] << "   ";
		cout << endl;
	}
}


