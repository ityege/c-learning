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
int main()
{
    vector<int> myvector;
    FillValue(myvector, -3, 12);
    for_each(myvector.begin(), myvector.end(), print);
    cout << endl;
    vector<int>::iterator pos1;
    pos1 = find(myvector.begin(), myvector.end(), 5);
    vector<int>::iterator pos2;
    pos2 = find_if(myvector.begin(), myvector.end(), bind(greater<int>(), placeholders::_1, 3));
    cout << " 第一个等于 5 的元素的位置 :" << distance(myvector.begin(), pos1) + 1 << endl;
    cout << " 第一个大于 3 的元素的位置 :" << distance(myvector.begin(), pos2) + 1 << endl;
    return 0;
}