#include <iostream>
#include <list>
#include <ctime>
using namespace std;     // 必须
void mysleep(int second) // 自己编写的延时函数
{
    clock_t st;
    st = clock();
    while (clock() - st < second * CLOCKS_PER_SEC)
        ;
}
int main()
{
    int count = 5;
    float number = 0.0;
    list<int> mylist; // 对 list 模板类进行实例化， list < int >
    cout << " 请任意输入 5 个数字:" << endl;
    while (count--)
    {
        cin >> number;
        mylist.push_back(number); // 将输入数据压入列表 list
    }
    list<int>::iterator iter;
    for (iter = mylist.begin(); iter != mylist.end(); iter++) // 输出列表 list 的元素
        cout << *iter << ",";
    cout << endl;
    return 0;
}