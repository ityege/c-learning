#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void OutToScreen(int &Ele)
{
    cout << Ele << ", ";
}
int main()
{
    list<int> mylt; // 定义容器型对象
    for (int i = 0; i < 10; i++)
        mylt.push_back(i);                           // 添加元素
    for_each(mylt.begin(), mylt.end(), OutToScreen); // 输出容器中的元素
    cout << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    while (!mylt.empty()) // 每次从尾部取出一个元素， 之后输出， 直至为空。
    {
        mylt.pop_back();
        for_each(mylt.begin(), mylt.end(), OutToScreen);
        cout << endl;
    }
    mylt.clear();                // 清空容器
    for (int j = 0; j < 10; j++) // 重新添加元素
        mylt.push_back(j);
    for_each(mylt.begin(), mylt.end(), OutToScreen); // 输出容器中的所有元素
    cout << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    while (!mylt.empty()) // 删除容器中的第一个元素， 输出剩余元素， 直至为空
    {
        mylt.erase(mylt.begin());
        for_each(mylt.begin(), mylt.end(), OutToScreen);
        cout << endl;
    }
    return 0;
}