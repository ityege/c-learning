#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#define w 400
using namespace cv;

void scalar_demo1() {

	Mat blue_m(256, 256, CV_8UC3, Scalar(255, 0, 0));
	Mat green_m(256, 256, CV_8UC3, Scalar(0, 255, 0));
	Mat red_m(256, 256, CV_8UC3, Scalar(0, 0, 255));

	imshow("Blue", blue_m);
	waitKey(1000);

	imshow("Green", green_m);
	waitKey(1000);

	imshow("Red", red_m);
	waitKey(1000);

}

void scalar_demo2() {
	cv::Scalar scalar(125);
	cv::Mat mat(2, 3, CV_8UC1, scalar);
	std::cout << mat << std::endl;


	cv::Scalar scalar1(0, 255);
	cv::Mat mat1(4, 4, CV_32FC2, scalar1);
	std::cout << mat1 << std::endl;

	cv::Scalar scalar2(0, 255, 255);
	cv::Mat mat2(4, 4, CV_32FC3, scalar2);
	std::cout << mat2 << std::endl;

	cv::Scalar scalar3(0, 255, 255, 0);
	cv::Mat mat3(4, 4, CV_32FC4, scalar3);
	std::cout << mat3 << std::endl;
}

int main(void) {
	scalar_demo1();

	scalar_demo2();


	return 0;
}
