#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2\imgproc\types_c.h>
#include <opencv2/highgui/highgui_c.h>

using namespace cv;
using namespace std;

void main()
{
	VideoCapture capture(0);
	VideoWriter writer;//定义一个无参数的VideoWriter对象
	int codec = writer.fourcc('M', 'J', 'P', 'G');
	Mat frame;
	capture >> frame;
	writer = cv::VideoWriter("test.avi", codec, 10, Size(frame.cols, frame.rows));  // size必须为你的图像的分辨率
	//实例化后赋值
	if (writer.isOpened())
	{
		while (capture.isOpened())
		{
			capture >> frame;
			writer << frame;

			imshow("video", frame);
			if (cvWaitKey(20) == 27)//每隔20微妙录制一帧,按ESC键退出
				break;

		}
	}
}