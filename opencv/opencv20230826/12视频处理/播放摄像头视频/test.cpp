#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2\imgproc\types_c.h>
#include <opencv2/highgui/highgui_c.h>

using namespace cv;
using namespace std;

int main()
{
	//打开摄像头
	VideoCapture capture(0, CAP_DSHOW);
	if (!capture.isOpened())
	{
		puts("open failed");
		return -1;
	}
	Mat frame;
	while (capture.read(frame))
	{
		imshow("video-demo", frame);
		if (waitKey(30) >= 0)//延时30ms,按下任何键退出
			break;
	}
	return 0;
}
