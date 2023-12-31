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
        cout << " The indexes is error: last < first. " << endl;
    }
}
void print(int elem)
{
    cout << elem << " ";
}
template <class T>
class Multiple
{ // 定义类 Multiple
private:
    T theValue;

public:
    Multiple(const T &v) : theValue(v)
    {
    }
    void operator()(T &elem) const // 添加成员函数
    {
        elem *= theValue;
    }
};
int main()
{
    vector<int> myvector;
    FillValue(myvector, 1, 10);
    for_each(myvector.begin(), myvector.end(), print);
    cout << endl;
    for_each(myvector.begin(), myvector.end(), Multiple<int>(2)); // 参见程序前的解释
    for_each(myvector.begin(), myvector.end(), print);
    cout << endl;
    return 0;
}