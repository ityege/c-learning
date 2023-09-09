#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <opencv2/opencv.hpp>
#include <time.h>
using namespace std;
using namespace cv;


int writeYaml()
{
	//初始化
	FileStorage fs("test.yaml", FileStorage::WRITE);
	//开始文件写入
	fs << "frameCount" << 5;
	time_t rawtime;
	time(&rawtime);
	fs << "calibrationDate" << asctime(localtime(&rawtime));
	Mat cameraMatrix = (Mat_<double>(3, 3) << 1000, 0, 320, 0, 1000, 240, 0, 0, 1);
	Mat disCoeffs = (Mat_<double>(5, 1) << 0.1, 0.01, -0.001, 0, 0);
	fs << "cameraMatrix" << cameraMatrix << "disCoeffs" << disCoeffs;
	fs << "features" << "[";
	for (int i = 0; i < 3; i++)
	{
		int x = rand() % 640;
		int y = rand() % 480;
		uchar lbp = rand() % 256;
		fs << "{:" << "x" << x << "y" << y << "lbp" << "[:";
		for (int j = 0; j < 8; j++)
		{
			fs << ((lbp >> j) & 1);
		}
		fs << "]" << "}";
	}
	fs << "]";
	fs.release();
	printf("文件读写完毕，请在工程目录下查看生成的文件。\n");

	return 0;
}


int readYaml()
{
	// 改变console字体颜色
	system("color 6F");
	//初始化
	FileStorage fs2("test.yaml", FileStorage::READ);
	// 第一种方法 对FileNote操作
	int frameCount = (int)fs2["frameCount"];
	std::string date;
	//第二种方法:使用 FileNote运算符
	fs2["calibrationDate"] >> date;
	Mat cameraMatrix2, disCoeffs2;
	fs2["cameraMatrix"] >> cameraMatrix2;
	fs2["disCoeffs"] >> disCoeffs2;
	cout << "framCount: " << frameCount << endl
		<< "calibration date: " << date << endl
		<< "camera matrix: " << cameraMatrix2 << endl
		<< "distortion coeffs: " << disCoeffs2 << endl;
	FileNode features = fs2["features"];
	FileNodeIterator it = features.begin(), it_end = features.end();
	int idx = 0;
	std::vector<uchar> lbpval;
	//使用FileNoteIterator 遍历序列
	for (; it != it_end; ++it, ++idx)
	{
		cout << "feature #" << idx << ": ";
		cout << "x=" << (int)(*it)["x"] << ", y =" << (int)(*it)["y"] << ", lbp: (";
		(*it)["lbp"] >> lbpval;
		for (int i = 0; i < (int)lbpval.size(); i++)
		{
			cout << " " << (int)lbpval[i];
		}
		cout << ")" << endl;
	}
	fs2.release();
	printf("\n文件读取完毕，请输入任意键结束程序~");
	getchar();
	return 0;
}

int main()
{
	writeYaml();
	puts("YAML文件读取内容如下：");
	readYaml();
}
