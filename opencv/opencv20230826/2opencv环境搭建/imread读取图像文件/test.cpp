#include <iostream>
#include<opencv2\opencv.hpp>
using namespace std;
using namespace cv;
int main(int argc, char* argv[])
{
	Mat img;
	//string imgpath = "d:\\我的图片\\p1.jpg"; //-- 1 --双右斜线法，路径中含有中文
	//string imgpath = "d://test//p1.jpg";  //-- 2 --双左斜线法
	// string imgpath = "d:/test/p1.jpg"; //-- 3 --单左斜线法
	// string imgpath = "d:/test//test2\\test3//test4//p1.jpg";//-- 4 --以上三种混合法
	string imgpath = "p1.jpg";////-- 5 --相对路径法,放工程目录下
	//string imgpath = argv[1];//-- 6 --命令行参数法
	img = imread(imgpath, 1);
	if (img.data == NULL) //或img.empty()
	  puts("load failed");
	else imshow("img", img);

	waitKey(0);
	return 0;
}
 