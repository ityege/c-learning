#include <opencv2/highgui/highgui_c.h>
#include <opencv2\opencv.hpp>
 
using namespace cv;
#include<iostream>
using namespace std;
void showManyImages(const vector<Mat>&srcImages, Size imageSize){
	int nNumImages = srcImages.size();
	Size nSizeWindows;
	if (nNumImages > 12){
		cout << "no more tha 12 images" << endl;
		return;
	}
	//根据图片序列数量来确定分割小窗口的形态
	switch (nNumImages){
	case 1:nSizeWindows = Size(1, 1); break;
	case 2:nSizeWindows = Size(2, 1); break;
	case 3:
	case 4:nSizeWindows = Size(2, 2); break;
	case 5:
	case 6:nSizeWindows = Size(3, 2); break;
	case 7:
	case 8:nSizeWindows = Size(4, 2); break;
	case 9:nSizeWindows = Size(3, 3); break;
	default:nSizeWindows = Size(4, 3);
	}
	//设置小图像尺寸，间隙，边界
	int nShowImageSize = 200;
	int nSplitLineSize = 15;
	int nAroundLineSize = 50;
	//创建输出图像，图像大小根据输入源来确定
	const int imagesHeight = nShowImageSize*nSizeWindows.width + nAroundLineSize +(nSizeWindows.width - 1)*nSplitLineSize;
	const int imagesWidth = nShowImageSize*nSizeWindows.height + nAroundLineSize +(nSizeWindows.height - 1)*nSplitLineSize;
	cout << imagesWidth << "  " << imagesHeight << endl;
	Mat showWindowsImages(imagesWidth, imagesHeight, CV_8UC3, Scalar(0, 0, 0));
	//提取对应小图像的左上角坐标x，y
	int posX = (showWindowsImages.cols - (nShowImageSize*nSizeWindows.width +(nSizeWindows.width - 1)*nSplitLineSize)) / 2;
	int posY = (showWindowsImages.rows - (nShowImageSize*nSizeWindows.height +(nSizeWindows.height - 1)*nSplitLineSize)) / 2;
	cout << posX << "  " << posY << endl;
	int tempPosX = posX;
	int tempPosY = posY;
	//将每一幅小图像整合成一幅大图像
	for (int i = 0; i < nNumImages; i++){
		//小图像坐标转换
		if ((i%nSizeWindows.width == 0) && (tempPosX != posX)){
			tempPosX = posX;;
			tempPosY += (nSplitLineSize + nShowImageSize);
		}
		//利用Rect区域将小图像置于大图像的相应区域
		Mat tempImage = showWindowsImages(Rect(tempPosX, tempPosY, nShowImageSize, nShowImageSize));
		resize(srcImages[i], tempImage,Size(nShowImageSize, nShowImageSize));//利用resize函数实现图像缩放
		tempPosX += (nSplitLineSize + nShowImageSize);
	}//for
	imshow("单窗口显示多图片", showWindowsImages);
}
 
int main(){
	//图像源输入
	vector<Mat>srcImage(9);
	srcImage[0] = imread("1.jpg");
	srcImage[1] = imread("1.jpg");
	srcImage[2] = imread("1.jpg");
	srcImage[3] = imread("2.jpg");
	srcImage[4] = imread("2.jpg");
	srcImage[5] = imread("2.jpg");
	srcImage[6] = imread("3.jpg");
	srcImage[7] = imread("3.jpg");
	srcImage[8] = imread("3.jpg");
	//判断当前vector读入的正确性
	for (int i = 0; i < srcImage.size(); i++){
		if (srcImage[i].empty()){
			cout << "read error" << endl;
			return -1;
		}
	}
	//调用 单窗口显示图像
	showManyImages(srcImage, Size(147, 118));
	waitKey(0);
	
	return 0;
}