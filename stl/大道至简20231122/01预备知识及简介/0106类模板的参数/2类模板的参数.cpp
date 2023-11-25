#include <iostream>
using namespace std;
template <typename T>
T doubleV(T Val) // 模板函数 double(T Val)
{
    return Val * 2;
};
template <typename T1, typename T2>
class TwoThing
{ // 模板类
    T1 th1;
    T2 th2;
    T1 th3;

public:
    TwoThing(T1 tt1, T2 tt2)
    {
        th1 = tt1;
        th2 = tt2;
        th3 = doubleV<T1>(tt1);
    }
    void show() // 输出
    {
        cout << th1 << " , " << th2 << " , " << th3 << endl;
    }
};
int main()
{

    int m = 123;
    double n = 456.789;
    TwoThing<int, double> my(m, n); // 定义模板对象
    my.show();
    return 0;
}