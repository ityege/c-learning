#include <iostream>
#include <opencv2\imgproc\types_c.h> //for CV_RGB2GRAY
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 

using namespace std;
using namespace cv;


#define WINDOW_NAME1 "绘制图1"
#define WINDOW_NAME2 "绘制图2"
#define WINDOW_WIDTH 600    //定义窗口大小

void DrawEllipse(Mat img, double angle);
void DrawFi1ledCirc1e(Mat img, Point center);
int main()
{
    Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
    Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
    //绘制椭圆
    DrawEllipse(atomImage, 90);
    DrawEllipse(atomImage, 0);
    DrawEllipse(atomImage, 45);
    DrawEllipse(atomImage, -45);

    //绘制圆心
    DrawFi1ledCirc1e(atomImage, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));

    imshow(WINDOW_NAME1, atomImage);
    waitKey(0);
    return 0;
}
void DrawEllipse(Mat img, double angle) {
    int thickness = 2;
    int lineType = 8;
    ellipse(img, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),
        Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16), angle, 0, 360, Scalar(255, 129, 0),
        thickness, lineType);
}
void DrawFi1ledCirc1e(Mat img, Point center) {
    int thickness = -1;
    int lineType = 8;
    circle(img, center, WINDOW_WIDTH / 32, Scalar(0, 0, 255), thickness, lineType);
}