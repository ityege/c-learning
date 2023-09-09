#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;



void colorReduce(const Mat& image, Mat& outImage, int div = 64)
{
	outImage.create(image.size(), image.type());
	// 获得迭代器  
	MatConstIterator_<Vec3b> it_in = image.begin<Vec3b>();
	MatConstIterator_<Vec3b> itend_in = image.end<Vec3b>();
	MatIterator_<Vec3b> it_out = outImage.begin<Vec3b>();
	MatIterator_<Vec3b> itend_out = outImage.end<Vec3b>();
	while (it_in != itend_in)
	{
		(*it_out)[0] = (*it_in)[0] / div * div + div / 2;
		(*it_out)[1] = (*it_in)[1] / div * div + div / 2;
		(*it_out)[2] = (*it_in)[2] / div * div + div / 2;
		it_in++;
		it_out++;
	}
}
int main()
{
	Mat A, B;    //仅仅创建了矩阵头
	A = imread("520.jpg", 1);
	imshow("原图", A);
	colorReduce(A, B);
	imshow("效果图", B);
	imwrite("after520.jpg", B);
	waitKey(0);
}
