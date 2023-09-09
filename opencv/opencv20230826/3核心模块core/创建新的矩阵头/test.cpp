#include <iostream>
#include "opencv2/imgcodecs.hpp"
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;


int main()
{
	int i,j;
	Mat r1 = (Mat_<double>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	cout << "r1 total matrix:\n" << r1 << endl;

	Mat r2;
	for (i = 0; i < r1.rows; i++)
	{
		r2 = r1.row(i);
		if (r1.data == r2.data)
			cout << "when i=" << i << ",r1.data==r2.data\n";
		cout << "r1.row("<<i<<"):\n" << r2 << endl;
	}

	Mat r3;
	for (j = 0; j < r1.cols; j++)
	{
		r3 = r1.col(j);
		if (r1.data == r3.data)
			cout << "when j=" << j << ",r1.data==r3.data\n";

		cout << "r1.col(" << j << "):\n" << r3 << endl;
	}

	Mat r4 = r1.rowRange(1, 2);
	cout << "r1.rowRange(1, 2):\n" << r4 << endl;
	cout << "r1.colRange(1, 3):\n" << r1.colRange(1, 3) << endl;
}