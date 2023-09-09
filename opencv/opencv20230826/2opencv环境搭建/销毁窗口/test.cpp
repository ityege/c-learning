
#include <opencv2/highgui/highgui_c.h>
#include <opencv2\opencv.hpp>

using namespace cv;
#include<iostream>
using namespace std;

 
int main(){
	//图像源输入
	vector<Mat>srcImage(3);
	char szName[50] = "";
	for (int i = 0; i < srcImage.size(); i++) 
	{
		sprintf_s(szName, "%d.jpg", i+1);
		srcImage[i] = imread(szName);
		if (srcImage[i].empty()){ //判断当前vector读入的正确性	
			cout << "read "<< szName<<" error" << endl;
			return -1;
		}
		//调用 单窗口显示图像
		namedWindow(szName, WINDOW_AUTOSIZE);
		imshow(szName, srcImage[i]);//在“窗口1”这个窗口输出图片。
		waitKey(5000);//等待5秒，程序自动退出。改为0，不自动退出。
		destroyWindow(szName);
	}
	//destroyAllWindows();
	cout << "所有的窗口已经销毁了" << endl;
	waitKey(0);
	
	return 0;
}