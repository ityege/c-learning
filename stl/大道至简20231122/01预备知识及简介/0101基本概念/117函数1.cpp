#include <iostream>
#include <cmath>
using namespace std;
double pow2(float x); // 函数 pow2()的声明
double pow3(float y); // 函数 pow3()的声明
double pow2(float x)  // 函数 pow2()的定义
{
    double z = 0;
    z = x * x;
    return z;
}
double pow3(float *y) // 函数 pow3()的定义
{
    double z = 0;
    z = (*y) * (*y) * (*y);
    return z;
}
int main()
{
    double A = 10;
    float B = 20;
    double C = 0;
    double D = 0;
    C = pow2(A);
    cout << "A: " << A << " ; Pow2(A): " << C << endl;
    D = pow3(&B);
    cout << "B: " << B << " ; Pow3(B): " << D << endl;
    cin.get();
    return 0;
}