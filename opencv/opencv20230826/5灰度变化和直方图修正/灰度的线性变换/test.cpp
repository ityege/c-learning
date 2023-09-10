#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;  //所有opencv类都在命名空间cv下
using namespace std;


// 图像线性变换操作
cv::Mat linearTransform(cv::Mat srcImage, float a, int b)
{
    if (srcImage.empty()) {
        std::cout << "No data!" << std::endl;
    }
    const int nRows = srcImage.rows;
    const int nCols = srcImage.cols;
    cv::Mat resultImage =
        cv::Mat::zeros(srcImage.size(), srcImage.type());
    // 图像元素遍历
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            for (int c = 0; c < 3; c++)//如果源图像是灰度图,那么把这里改为c<1即可
            {
                // 矩阵at操作，检查下标防止越界
                resultImage.at<Vec3b>(i, j)[c] = saturate_cast<uchar>(a * (srcImage.at<Vec3b>(i, j)[c]) + b);
            }
        }
    }
    return resultImage;
}
int main()
{
    // 图像获取及验证
    cv::Mat srcImage = cv::imread("lakeWater.jpg");
    if (!srcImage.data)
        return -1;
    cv::imshow("原图", srcImage);
    //cv::waitKey(0);
    // 线性变换
    float a = 1.2;
    int b = 50;
    cv::Mat new_image = linearTransform(srcImage, a, b);
    cv::imshow("效果图", new_image);
    cv::waitKey(0);
    return 0;
}
