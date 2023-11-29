#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <class T>
void FillValue(T &vect, int first, int last)
{
    if (last >= first)
    {
        for (int i = first; i <= last; ++i)
            vect.insert(vect.end(), i);
    }
    else
    {
        cout << "The indexes is error: last < first. " << endl;
    }
}
void print(int elem)
{
    cout << elem << " ";
}
class SUM
{ // 定义 SUM 类
private:
    long sum_D;

public:
    SUM() : sum_D(0)
    {
    }
    void operator()(int elem) // 实现求和功能
    {
        sum_D += elem;
    }
    operator double()
    { // 返回求得的总和
        return static_cast<double>(sum_D);
    }
};
int main()
{
    vector<int> myvector;
    FillValue(myvector, 1, 10);                        // 给向量 myvector 赋值
    for_each(myvector.begin(), myvector.end(), print); // 输出向量 myvector 中的元素
    cout << endl;
    double sum = for_each(myvector.begin(), myvector.end(), SUM()); // 求和， 返回结果为 double 类型数值
    cout << "The Sum: " << sum << endl;
    return 0;
}