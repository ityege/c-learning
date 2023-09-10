#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2\imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	string text = "Funny text inside the box";
	//int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;     //手写风格字体
	int fontFace = FONT_HERSHEY_SCRIPT_COMPLEX;
	double fontScale = 2;       //字体缩放比
	int thickness = 3;

	Mat img(600, 800, CV_8UC3, Scalar::all(0));

	int baseline = 0;

	Size textSize = getTextSize(text, fontFace, fontScale, thickness, &baseline);
	baseline += thickness;
	//center the text
	Point textOrg((img.cols - textSize.width) / 2, (img.rows - textSize.height) / 2);
	//draw the box
	rectangle(img, textOrg + Point(0, baseline), textOrg + Point(textSize.width, -textSize.height), Scalar(0, 0, 255));
	line(img, textOrg + Point(0, thickness), textOrg + Point(textSize.width, thickness), Scalar(0, 0, 255));
	putText(img, text, textOrg, fontFace, fontScale, Scalar::all(255), thickness, 8);
	imshow("text", img);
	waitKey(0);
	return 0;
}