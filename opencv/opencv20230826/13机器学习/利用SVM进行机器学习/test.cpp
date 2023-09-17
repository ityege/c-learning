#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/ml/ml.hpp"
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace cv::ml;



int main(int, char**)
{
	// Data for visual representation
	int width = 512, height = 512;
	Mat image = Mat::zeros(height, width, CV_8UC3);

	// 设置训练数据
	//! [setup1]
	int labels[4] = { 1, -1, -1, -1 };
	float trainingData[4][2] = { {501, 10}, {255, 10}, {501, 255}, {10, 501} };
	//! [setup1]
	//! [setup2]
	Mat trainingDataMat(4, 2, CV_32FC1, trainingData);
	Mat labelsMat(4, 1, CV_32SC1, labels);
	//! [setup2]


	// 训练 SVM
	//! [init]
	Ptr<SVM> svm = SVM::create();
	svm->setType(SVM::C_SVC);
	svm->setKernel(SVM::LINEAR);
	svm->setDegree(1.0);
	svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6));
	//! [init]
	//! [train]
	svm->train(trainingDataMat, ROW_SAMPLE, labelsMat);
	//! [train]

	// 显示支持向量机给出的决策区域
	//! [show]
	Vec3b green(0, 255, 0), blue(255, 0, 0);
	for (int i = 0; i < image.rows; ++i)
		for (int j = 0; j < image.cols; ++j)
		{
			Mat sampleMat = (Mat_<float>(1, 2) << j, i);
			float response = svm->predict(sampleMat);

			if (response == 1)
				image.at<Vec3b>(i, j) = green;
			else if (response == -1)
				image.at<Vec3b>(i, j) = blue;
		}
	//! [show]

	// 显示训练数据
	//! [show_data]
	int thickness = -1;
	int lineType = 8;
	circle(image, Point(501, 10), 5, Scalar(0, 0, 0), thickness, lineType);
	circle(image, Point(255, 10), 5, Scalar(255, 255, 255), thickness, lineType);
	circle(image, Point(501, 255), 5, Scalar(255, 255, 255), thickness, lineType);
	circle(image, Point(10, 501), 5, Scalar(255, 255, 255), thickness, lineType);
	//! [show_data]

	// 显示支持矩阵
	//! [show_vectors]
	thickness = 2;
	lineType = 8;
	Mat sv = svm->getSupportVectors();

	for (int i = 0; i < sv.rows; ++i)
	{
		const float* v = sv.ptr<float>(i);
		circle(image, Point((int)v[0], (int)v[1]), 6, CV_RGB(255, 0, 0), thickness, lineType);
	}
	//! [show_vectors]

	imwrite("result.png", image);        // save the image

	imshow("SVM Simple Example", image); // show it to the user
	waitKey(0);
}