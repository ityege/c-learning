#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
void Out(double &Ele)
{
    cout.width(5);
    cout.precision(1);
    cout << std::fixed << Ele << " ";
}
int main()
{
    deque<double> D1, D2;
    for (int i = 0; i < 10; i++) // 初始化容器
    {
        D1.push_front(90 + i / 10.0);
    }
    cout << " All the element of 双端序列 D1:" << endl;
    for_each(D1.begin(), D1.end(), Out); // 输出容器 D1 中的内容
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        D2.push_front(80 + i / 10.0);
    }
    cout << " All the element of 双端序列 D2:" << endl;
    for_each(D2.begin(), D2.end(), Out); // 输出容器 D2 中的内容
    cout << endl;
    D1.swap(D2); // 交换容器 D1 和 D2 中的内容
    cout << " D1 swap D2 :" << endl;
    cout << " All the element of 双端序列 D1:" << endl;
    for_each(D1.begin(), D1.end(), Out); // 输出 D1 中的所有元素
    cout << endl;
    cout << " All the element of 双端序列 D2:" << endl;
    for_each(D2.begin(), D2.end(), Out); // 输出 D2 中的所有元素
    cout << endl;
    D1.insert(D1.begin(), -1.0); // 插入 3 个元素
    D1.insert(D1.end(), -1.0);
    D1.insert(D1.begin() + 6, -0.0);
    cout << " All the element of 双端序列 D1:" << endl;
    for_each(D1.begin(), D1.end(), Out);
    cout << endl;
    D1.erase(D1.begin() + 1); // 删除两个元素
    D1.erase(D1.begin() + 10);
    cout << " All the element of 双端序列 D1:" << endl;
    for_each(D1.begin(), D1.end(), Out);
    cout << endl;
    D2.clear();
    cout << "D2 has been already cleared!" << endl;
    cout << "All the element of 双端序列 D2:" << endl;
    for_each(D2.begin(), D2.end(), Out);
    cout << endl;
    deque<double>::iterator it = find(D1.begin(), D1.end(), 80.5); // 使用 find()算法函数
    int step = (it - D1.begin());                                  // 求出所找元素的位置 （下标）
    cout << " find 80. 5. in D1 , its Index: " << step << " . " << endl;
    return 0;
}