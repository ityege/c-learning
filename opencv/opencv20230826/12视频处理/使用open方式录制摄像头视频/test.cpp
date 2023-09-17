#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2\imgproc\types_c.h>
#include <opencv2/highgui/highgui_c.h>

using namespace cv;
using namespace std;
int main(int, char**)
{
	Mat src;
	VideoCapture cap(0);//使用默认摄像机作为视频源
	if (!cap.isOpened()) { //检查是否打开成功
		cerr << "ERROR! Unable to open camera\n";
		return -1;
	}
	//从相机上取一帧来知道帧的大小和类型
	cap >> src;
	if (src.empty()) {	// 检查是否为空
		cerr << "ERROR! blank frame grabbed\n";
		return -1;
	}
	bool isColor = (src.type() == CV_8UC3);
	//初始化VIDEOWRITER
	VideoWriter writer;
	int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');  // 选择所需的编解码器（必须在运行时可用）
	double fps = 25.0;                          // 创建的视频流的帧速率
	string filename = "./live.avi";             //输出视频文件的名称
	writer.open(filename, codec, fps, src.size(), isColor);
	// check if we succeeded
	if (!writer.isOpened()) {
		cerr << "Could not open the output video file for write\n";
		return -1;
	}
	//抓取和写入循环
	cout << "Writing videofile: " << filename << endl
		<< "Press any key to terminate" << endl;
	for (;;)
	{
		// check if we succeeded
		if (!cap.read(src)) {
			cerr << "ERROR! blank frame grabbed\n";
			break;
		}
		// 将帧编码到视频文件流中
		writer.write(src);
		// 实时显示并等待超时时间足以显示图像的键
		imshow("Live", src);
		if (waitKey(5) >= 0)
			break;
	}
	// 视频文件将在VideoWriter析构函数中自动关闭和释放
	return 0;
}