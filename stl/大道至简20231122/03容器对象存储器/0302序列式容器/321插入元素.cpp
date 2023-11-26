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
    vector<int> myvt; // 定义vector 容器型对象
    for (int i = 0; i < 10; i++)
        myvt.push_back(i);                           // 初始化容器的元素
    myvt.insert(myvt.begin(), -1);                   // 在向量起始位置之前插入元素 -1
    for_each(myvt.begin(), myvt.end(), OutToScreen); // 将向量中的元素输出
    cout << endl;
    myvt.insert(myvt.end(), -2); // 在向量末尾之前插入 -2
    for_each(myvt.begin(), myvt.end(), OutToScreen);
    cout << endl;
    vector<int> vt2; // 定义新的数值序列
    vt2.push_back(-8);
    vt2.push_back(-9);
    myvt.insert(myvt.end(), vt2.begin(), vt2.end()); // 插入多个数值
    for_each(myvt.begin(), myvt.end(), OutToScreen);
    cout << endl;
    myvt.insert(myvt.begin(), 3, 0); // 插入多个相同的数值
    for_each(myvt.begin(), myvt.end(), OutToScreen);
    cout << endl;
    return 0;
}