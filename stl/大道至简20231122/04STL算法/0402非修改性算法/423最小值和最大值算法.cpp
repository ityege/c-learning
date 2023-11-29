#include <functional>
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
bool AbsLess(int elem1, int elem2) // 使用绝对值进行比较
{
    return abs(elem1) < abs(elem2);
}
int main()
{
    vector<int> myvector;
    FillValue(myvector, -3, 12);                       // 给向量赋值
    for_each(myvector.begin(), myvector.end(), print); // 输出向量型容器中的元素
    cout << endl;
    cout << " minimum: " << *min_element(myvector.begin(), myvector.end()) << endl;
    // 获得最小值
    cout << " maximum: " << *max_element(myvector.begin(), myvector.end()) << endl; // 获得最大值
    cout << " minimum of absolute value: " << *min_element(myvector.begin(), myvector.end(), AbsLess)
         << endl; // 获得向量型容器中绝对值最小的元素
    cout << " maximum of absolute value: " << *max_element(myvector.begin(), myvector.end(), AbsLess)
         << endl; // 获得向量型容器中绝对值最大的元素
    return 0;
}