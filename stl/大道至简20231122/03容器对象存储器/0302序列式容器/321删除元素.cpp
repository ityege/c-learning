#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void OutToScreen(int &Ele) // 输出元素至屏幕
{
    cout << Ele << ", ";
}
int main()
{
    vector<int> myvt;
    for (int i = 0; i < 10; i++)
        myvt.push_back(i);
    for_each(myvt.begin(), myvt.end(), OutToScreen); // 输出 vector 型容器中的元素
    cout << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    while (!myvt.empty()) // 判断向量是否为空
    {
        myvt.pop_back();                                 // 弹出向量
        for_each(myvt.begin(), myvt.end(), OutToScreen); // 输出向量中的元素
        cout << endl;
    }
    myvt.clear(); // 清空 vector 型容器
    for (int j = 0; j < 10; j++)
        myvt.push_back(j);
    for_each(myvt.begin(), myvt.end(), OutToScreen); // 输出
    cout << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    while (!myvt.empty()) // 判断 vector 型容器是否为空
    {
        myvt.erase(myvt.begin());                        // 删除开始第一个元素
        for_each(myvt.begin(), myvt.end(), OutToScreen); // 输出 vector 型容器中的元素
        cout << endl;
    }
    return 0;
}