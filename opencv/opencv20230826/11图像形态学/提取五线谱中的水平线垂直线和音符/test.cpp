#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
void show_wait_destroy(const char* winname, cv::Mat img);//一直显示图像,直到用户按键后结束
using namespace std;
using namespace cv;
int main(int argc, char** argv)
{
#ifdef _DEBUG //调试版本的使用,用一个固定文件,这样方便一点
	Mat src = imread("test.jpg", IMREAD_COLOR);
#else  //正式版本,可以支撑命令行输入文件
	CommandLineParser parser(argc, argv, "{@input | notes.png | input image}");
	Mat src = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR);
#endif
	if (src.empty())
	{
		cout << "Could not open or find the image!\n" << endl;
		cout << "Usage: " << argv[0] << " <Input image>" << endl;
		return -1;
	}
	// 显示原图
	imshow("src", src);
	// 如果不是灰度图,将源图像转换为灰度图
	Mat gray;
	if (src.channels() == 3)
	{
		cvtColor(src, gray, COLOR_BGR2GRAY);
	}
	else
	{
		gray = src;
	}

	show_wait_destroy("gray", gray);//显示灰度图,知道用户起案件结束
	//利用函数adaptiveThreshold对灰度图像进行二值化
	Mat bw;
	adaptiveThreshold(~gray, bw, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);

	show_wait_destroy("binary", bw);//显示二值图像,直到用户按键结束
	//创建用于提取水平线和垂直线的图像
	Mat horizontal = bw.clone();
	Mat vertical = bw.clone();

	int horizontal_size = horizontal.cols / 30;//指定水平轴上的大小
	//通过形态学操作创建用于提取水平向的结构元素
	Mat horizontalStructure = getStructuringElement(MORPH_RECT, Size(horizontal_size, 1));
	//应用形态学操作
	erode(horizontal, horizontal, horizontalStructure, Point(-1, -1));//先腐蚀
	dilate(horizontal, horizontal, horizontalStructure, Point(-1, -1));//后膨胀

	show_wait_destroy("horizontal", horizontal);//显示提取的水平线

	int vertical_size = vertical.rows / 30;//指定垂直轴上的大小
	//通过形态学操作创建用于提取垂直向的结构元素
	Mat verticalStructure = getStructuringElement(MORPH_RECT, Size(1, vertical_size));
	//应用形态学操作
	erode(vertical, vertical, verticalStructure, Point(-1, -1));//先腐蚀
	dilate(vertical, vertical, verticalStructure, Point(-1, -1));//后膨胀
	//显示提取的垂直线
	show_wait_destroy("vertical", vertical);
	// 反向垂直图像
	bitwise_not(vertical, vertical);
	show_wait_destroy("vertical_bit", vertical);
	//更具逻辑提取液边缘和平滑图像
	//1.提取边缘
	//2.dilate(edges)
	//3.vertical.copyTo(smooth)
	//4.blur smooth image
	//5.smooth.copyTo(vertical, edges)
	//Step 1
	Mat edges;
	adaptiveThreshold(vertical, edges, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, -2);
	show_wait_destroy("edges", edges);
	//Step 2
	Mat kernel = Mat::ones(2, 2, CV_8UC1);
	dilate(edges, edges, kernel);
	show_wait_destroy("dilate", edges);
	//Step 3
	Mat smooth;
	vertical.copyTo(smooth);
	//Step 4
	blur(smooth, smooth, Size(2, 2));
	//Step 5
	smooth.copyTo(vertical, edges);
	//显示最终结果
	show_wait_destroy("smooth - final", vertical);
	return 0;
}
void show_wait_destroy(const char* winname, cv::Mat img) {//改函数显示图像
	imshow(winname, img);
	moveWindow(winname, 500, 0);
	waitKey(0);
	destroyWindow(winname);
}