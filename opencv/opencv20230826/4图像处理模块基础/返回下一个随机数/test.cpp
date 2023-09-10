#include <opencv2/opencv.hpp>
using namespace cv;
#include<iostream>
using namespace std;

int main()
{
	RNG rng(time(NULL));
	int N = rng.next();                    //返回下一个随机整数，即N1.next();
	int Ni = rng.operator ()();            //和rng.next( )等价
	int Nj = rng.operator ()(100);         //返回[0,100)范围内的随机数

	//返回下一个指定类型的随机数
	unsigned char uch = rng.operator uchar();         //返回下一个无符号字符数
	char ch = rng.operator schar();         //返回下一个有符号字符数
	int n = rng.operator int();           //返回下一个整型数

	float f = rng.operator float();         //返回下一个浮点数
	double df = rng.operator double();        //返回下一个double型数

	cout << "N=" << N << ",Ni=" << Ni << ",Nj=" << Nj << endl;
	printf("uch=0x%x,ch=0x%x,n=0x%x,f=%f,df=%.2lf\n", uch, ch, n, f, df);
}