#include <iostream>                          //包含头文件 iostream
#include <vector>                            //包含头文件 vector
#include <algorithm>                         //包含头文件 algorithm
using namespace std;                         // 使用命名空间 std
template <class T>                           // 使用类模板定义类 T
void FillValue(T &vect, int first, int last) // 定义 FillValue()函数,该函数的功能是给对象
{                                            // vect 的每个元素赋值
    if (last >= first)
    {
        for (int i = first; i <= last; ++i) // 使用 for 循环，向序列中插入元素
            vect.insert(vect.end(), i);
    }
    else
    {
        cout << " The indexes is error: last < first. " << endl;
    }
}
void print(int elem) // 在屏幕上输出函数的参数 elem
{
    cout << elem << " ";
}
int main() // 程序入口 main()函数
{
    vector<int> myvector;                              // 使用向量模板定义向量 myvector
    FillValue(myvector, 1, 10);                        // 给向量赋值
    for_each(myvector.begin(), myvector.end(), print); // 输出向量中的每个元素的值
    cout << endl;                                      // 换行
    return -1;
}