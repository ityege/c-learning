#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;


Mat colorReduce_2(Mat img, int div)
{
	Mat image;
	image = img.clone();
	//img.copyTo(image);
	int nl = image.rows;
	int nc = image.cols * image.channels();
	for (int j = 0; j < nl; j++)
	{
		uchar* data = image.ptr<uchar>(j);
		for (int i = 0; i < nc; i++)
			data[i] = data[i] - data[i] % div + div / 2;
	}
	return image;
}

int main()
{
	Mat img = imread("520.jpg");
	Mat img2 = colorReduce_2(img, 64);
	imshow("reduce520", img2);
	imshow("520", img);
	waitKey(0);
}