#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void print(int &Ele)
{
    cout << Ele << " ";
}
int main()
{
    list<int> L1, L2, L3;
    list<int>::iterator I1, I2, I3;
    L1.push_back(1);
    L1.push_back(5);
    L2.push_back(2);
    L2.push_back(3);
    L3.push_back(7);
    L3.push_back(8);
    cout << " L1 : ";
    for_each(L1.begin(), L1.end(), print); // 输出 L1 中的内容
    cout << endl;
    cout << " L2 : ";
    for_each(L2.begin(), L2.end(), print); // 输出 L2 中的内容
    cout << endl;
    cout << " L3 : ";
    for_each(L3.begin(), L3.end(), print); // 输出 L3 中的内容
    cout << endl;
    cout << " L1 merges L2 and L3 :";
    L1.merge(L2);                          // 合并 L1 和 L2
    L1.merge(L3);                          // 合并 L1 和 L3
    for_each(L1.begin(), L1.end(), print); // 可知， 在 list 合并之后， 所有元素自动按从小到大排序
    cout << endl;
    L1.sort(greater<int>()); // 降序排序
    cout << "L1 : ";
    for_each(L1.begin(), L1.end(), print); // 所有元素输出 （降序）
    cout << endl;
    L1.sort(); // 默认按从小到大排序
    cout << " L1 : ";
    for_each(L1.begin(), L1.end(), print); // 所有元素自动按从大到小排序
    cout << endl;
    return 0;
}