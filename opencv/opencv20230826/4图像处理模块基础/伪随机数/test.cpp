#include <iostream>
#include <opencv2/core.hpp>

int main()
{
	cv::RNG rng;
	int N1 = rng();
	printf("N=0x%x\n", N1);
}

