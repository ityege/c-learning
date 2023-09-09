#include <iostream>
#include "opencv2/imgcodecs.hpp"
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;


int main()
{
	Mat r1 = (Mat_<double>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	cout << "r1 total matrix:\n" << r1 << endl;

	Mat r2; 
	if (r2.data == NULL) cout << "r2.data==NULL\n";
	cout <<"r2="<< r2 << endl;

	Mat r3(Size(3, 3), CV_8UC3);
	cout << "r3=\n";
	cout << r3;

	return 0;
}