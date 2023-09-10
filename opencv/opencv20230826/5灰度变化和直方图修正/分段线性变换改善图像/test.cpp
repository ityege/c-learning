#include <opencv2/opencv.hpp>  //头文件
#include <iostream>



using namespace cv;  //包含cv命名空间
using namespace std;

int main(int argc, char** argv)
{
	Mat srcImage, dstImage;

	//设置变量,遵循的公式为dstImage=alpha*srcImage+beta(即y=ax+b)
	float alpha = 2.0;
	float beta = 0;

	//读入一幅图片,并对图像进行分段线性变换
	//载入图像,转为灰度图

	srcImage = imread("img.jpg", 0);//在程序中打开一幅图片,灰度图格式,加上表示读入灰度图
	if (!srcImage.data)
	{
		printf("could not load image...\n");
		return -1;
	}
	char input_title[] = "input image";
	char output_title[] = "output image";
	namedWindow(input_title, WINDOW_AUTOSIZE);
	namedWindow(output_title, WINDOW_AUTOSIZE);

	//显示载入的图片
	imshow(input_title, srcImage);

	dstImage = srcImage.clone();//dstImage与srcImage尺寸一样,内容也一样

	//对dst进行分段线性变换,遵循的公式为dstImage=alpha*srcImage+beta(即y=ax+b)
	//怕被刷屏,所以此处就不输出srcImage\dstImage的像素值了
	for (int r = 0; r < srcImage.rows; r++)
	{
		for (int c = 0; c < srcImage.cols; c++) {
			uchar temp = srcImage.at<uchar>(r, c);
			if (temp < 50)
			{
				dstImage.at<uchar>(r, c) = saturate_cast<uchar>(temp * 0.5);
			}
			else if (50 <= temp && temp < 150)
			{
				dstImage.at<uchar>(r, c) = saturate_cast<uchar>(temp * 3.6 - 310);
			}
			else
			{
				dstImage.at<uchar>(r, c) = saturate_cast<uchar>(temp * 0.238 + 194);
			}
		}
	}


	imshow(output_title, dstImage);//显示效果图
	imwrite("img_new.jpg", dstImage);//将结果图保存下来


	waitKey(0);//等待任意按键按下
	return 0;
}
