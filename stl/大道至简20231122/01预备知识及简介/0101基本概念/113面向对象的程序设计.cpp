#include <iostream>  //包含输入/输出流功能的头文件
#include <cmath>     //包含数学函数库的头文件
#include <stdio.h>   //包含标准输入/输出的头文件
using namespace std; // 使用命名空间 std
class Calculator     // 声明类 Calculator
{
public:                                     // 将下述定义为公共成员
    Calculator();                           // 构造函数
    ~Calculator();                          // 析构函数
    float x;                                // 成员变量 x
    float y;                                // 成员变量 y
    float Adder(float x, float y);          // 加法运算
    float Substration(float x, float y);    // 减法运算
    float Multiplication(float x, float y); // 乘法运算
    float Division(float x, float y);       // 除法运算
    float CPow(float x, float y);           // 乘方运算
    float CSqrt(float x);                   // 开方运算
};                                          // 类声明结束
Calculator::Calculator()                    // 定义构造函数
{
    x = 0;
    y = 0;
}
Calculator::~Calculator() // 定义析构函数
{
}
float Calculator::Adder(float x, float y) // 定义实现加法运算的成员函数
{
    float He = 0;
    He = x + y;
    return He;
}
float Calculator::Substration(float x, float y) // 定义实现减法运算的成员函数
{
    float Cha = 0;
    Cha = x - y;
    return Cha;
}
float Calculator::Multiplication(float x, float y) // 定义实现乘法运算的成员函数
{
    float Ji = 0;
    Ji = x * y;
    return Ji;
}
float Calculator::Division(float x, float y) // 定义实现除法运算的成员函数
{
    float Shang = 0;
    if (y == 0.0)
        return -1;
    Shang = x / y;
    return Shang;
}
float Calculator::CPow(float x, float y) // 定义实现乘方运算的成员函数
{
    float ChengFang = 0;
    ChengFang = pow(x, y);
    return ChengFang;
}
float Calculator::CSqrt(float x) // 定义实现开平方运算的成员函数
{
    float sqrtC = 0.0;
    sqrtC = sqrt(x);
    return sqrtC;
}
int main() // 程序入口，main()函数
{
    float x = 0;
    float y = 0;
    cout << "请输入 x:";
    cin >> x; // 输入数据 x
    cout << endl;
    cout << "请输入 y:";
    cin >> y; // 输入数据 y
    cout << endl;
    Calculator my; // 定义类的对象
    float He = my.Adder(x, y);
    cout << "两数之和：" << He << endl;
    float Cha = my.Substration(x, y);
    cout << "两数之差：" << Cha << endl;
    float Ji = my.Multiplication(x, y);
    cout << "两数之积：" << Ji << endl;
    float Shang = my.Division(x, y);
    cout << "两数之商：" << Shang << endl;
    float Pow = my.CPow(x, y);
    cout << "x 的 y 次方：" << Pow << endl;
    float KaiFang = my.CSqrt(x);
    cout << "x 的平方根：" << KaiFang << endl;
    cout << "任意键程序退出";
    getchar();
    return 0;
}