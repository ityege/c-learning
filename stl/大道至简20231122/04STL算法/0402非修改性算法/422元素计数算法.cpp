#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <class T>
void FillValue(T &vect, int first, int last) // 赋值
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
void print(int elem) // 输出到屏幕
{
    cout << elem << " ";
}
bool isEven(int elem) // 是否是偶数
{
    return elem % 2 == 0;
}
int main()
{
    vector<int> myvector;                              // 定义向量
    FillValue(myvector, 1, 10);                        // 给向量赋值
    for_each(myvector.begin(), myvector.end(), print); // 输出到屏幕
    cout << endl;
    int ct = count(myvector.begin(), myvector.end(), 4);           // 统计等于 4 的元素个数
    int ctif = count_if(myvector.begin(), myvector.end(), isEven); // 统计偶数的个数
    int ctg = count_if(myvector.begin(), myvector.end(), bind(greater<int>(), placeholders::_1, 2));
    // 统计大于 2 的元素个数
    cout << "Number of the element equals to 4: " << ct << endl;
    cout << "Number of the elements being Even: " << ctif << endl;
    cout << "Number of the elements being larger than 2: " << ctg << endl;
    cout << endl;
    return 0;
}