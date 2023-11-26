#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<double> mylist;    // 创建 list 容器
    mylist.push_back(10.2); // 压入 1 个数值
    bool empty = 0;
    if (mylist.empty())                        // 如果容器为空，
        cout << " The list is empty!" << endl; // 输出信息
    else                                       // 否则
    {
        empty = mylist.empty();
        cout << mylist.front() << ", " << empty << endl; // 输出容器中的元素和 empty()函数的返回值
    }
    return 0;
}