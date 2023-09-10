#include <opencv2/opencv.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
int jh(char imgfn[])
{
	Mat temp = imread(imgfn, 0);
	if (temp.empty())
	{
		printf("open %s failed.", imgfn);
		return -1;
	}
	
	imshow("原图", temp);
	//equalizeHist(temp, temp);
	int Total = temp.total();
	//统计各像素数量
	vector<int>nk(256, 0);

	//执行第一个步骤
	/*这个for循环统计每种灰度对应的像素数量，比如灰度是0的像素数量，灰度是255的像素数量，把每个nk计算出来 */
	for (int i = 0; i < temp.total(); ++i)
		nk[temp.data[i]]++;  //temp.data[i]表示第i个像素的灰度值，范围是0~255
	//++表示每个灰度值

		//执行第二个步骤
	for (int i = 1; i < 256; ++i) //这个for执行完毕后，nk[i]相当于公式中的累积分布函数sk，k和i是一个意思
		nk[i] += nk[i - 1];

	//第三步，重新建立映射关系
	vector<int>均衡后像素值(256, 0);
	for (int i = 0; i < 256; ++i) {
		均衡后像素值[i] = (double(nk[i]) / Total) * 255;
	}
	for (int i = 0; i < temp.total(); ++i)
		temp.data[i] = 均衡后像素值[temp.data[i]];

	imshow("均衡后", temp);
	waitKey(-1); //按键后再继续
}
int main()
{
	jh((char*)"img.png");
	jh((char*)"img2.png");
}
