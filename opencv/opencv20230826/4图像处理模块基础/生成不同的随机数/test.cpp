#include <opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	RNG rng((unsigned)time(NULL));
	int N1 = rng;
	cout << hex << "N1=0x" << N1 << endl;

	//产生均匀分布的随机数 uniform
	//总是得到double类型的数据0,因为会调用uniform(int,int),只会取整数
	double a = rng.uniform(0, 1);
	//产生[0,1)范围内均匀分布的double类型的数据
	double b = rng.uniform((double)0, (double)1);
	//产生[0,1)范围内均匀分布的float类型的数据,注意会自动转换为double了
	double c = rng.uniform(0.f, 1.f);
	//产生[0,1)范围内均匀分布的double类型数据
	double d = rng.uniform(0., 1.);
	//产生高斯分布的随机数gaussian
	double g = rng.gaussian(2);//产生符合均值为0,标准差为2的高斯分布随机数
	cout << "a=" << a << ",b=" << b << ",c=" << c << ",d=" << d << ",g=" << g << endl;
	
}