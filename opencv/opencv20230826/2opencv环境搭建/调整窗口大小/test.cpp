
#include "pch.h"
#include <opencv2/highgui/highgui_c.h>
#include <opencv2\opencv.hpp>
#pragma comment(lib, "opencv_world450d.lib")  //引用引入库 
using namespace cv;
#include<iostream>
using namespace std;
 
int main(){
	vector<Mat>srcImage(1);
	char szName[50] = "";
	int  width = 240, height = 120;
	
	sprintf_s(szName, "%d.jpg", 1);
	srcImage[0] = imread(szName);
	if (srcImage[0].empty()) {  
		cout << "read " << szName << " error" << endl;
		return -1;
	}
	namedWindow(szName, WINDOW_NORMAL);
	imshow(szName, srcImage[0]);
	resizeWindow(szName, width, height);
 
	waitKey(0);
	system("pause");

	return 0;
}