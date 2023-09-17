#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2\imgproc\types_c.h>
#include <opencv2/highgui/highgui_c.h>

#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;

void play(const char* filename)
{
	Mat frame;
	VideoCapture capture(filename);
	if (!capture.isOpened())
	{
		printf("open %s failed", filename);
		return;
	}
	//获取整个帧数
	long totalFrameNumber = capture.get(CAP_PROP_FRAME_COUNT);
	printf("整个视频共%d帧\n", totalFrameNumber);
	while (1) {
		capture >> frame;
		if (frame.empty()) { //播放完退出
			printf("播放完成\n");
			break;
		}
		imshow("读取视频", frame);//显示帧
		waitKey(20);

	}
}
int main() {
	play("test.avi");
	play("test.mp4");
}
