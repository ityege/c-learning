#include <opencv2/opencv.hpp>
using namespace cv;
#include<iostream>
using namespace std;

#define FALSE 0
#define TRUE 1

int main()
{
	RNG rng(time(NULL));
	//产生[1,1000)均匀分布的int随机数填充fillM
	Mat_<int> fillM(3, 3);
	rng.fill(fillM, RNG::UNIFORM, 1, 1000);
	cout << "filM = " << fillM << endl << endl;

	Mat fillM1(3, 3, CV_8U);
	rng.fill(fillM1, RNG::UNIFORM, 1, 1000, TRUE);
	cout << "filM1 = " << fillM1 << endl << endl;

	Mat fillM2(3, 3, CV_8U);
	rng.fill(fillM2, RNG::UNIFORM, 1, 1000, FALSE);
	cout << "filM2 = " << fillM2 << endl << endl;
	//fillM1产生的数据都在[0,，255)内，且小于255；
	//fillM2产生的数据虽然也在同样范围内，但是由于用了截断操作，所以很多数据都是255,	

	//产生均值为1，标准差为3的随机double数填进fillN
	Mat_<double>fillN(3, 3);
	rng.fill(fillN, RNG::NORMAL, 1, 3);
	cout << "filN = " << fillN << endl << endl;
}
