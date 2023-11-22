#include <iostream>
using namespace std;
int main()
{
    long Aa = 11;                                                          // 给变量 Aa 赋值
    long *B_Pointer = NULL;                                                // 声明指针变量 B_Pointer, 并将其赋值为空
    B_Pointer = &Aa;                                                       // 将变量 Aa 的内存地址保存在 B_Pointer 中
    cout << "Aa 的值: " << Aa << " ,Aa 的内存地址: " << B_Pointer << endl; // 输出
    cin.get();                                                             // 等待程序退出
    return 0;
}