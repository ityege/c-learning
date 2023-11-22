#include <iostream>
using namespace std;
void count(bool YN, int &counter); // 函数声明
void count(bool YN, int &counter)  // 函数定义
{
    if (YN)
    {
        counter++;
    }
}
int main() // main()主函数
{
    int counter = 0; // 计数器
    bool YN = 1;     // 逻辑变量，用于当条件满足时，退出 while 循环
    while (YN)
    {
        count(YN, counter);      // 计算循环次数
        cout << counter << endl; // 输出次数至屏幕
        if (counter > 5)         // 判断循环次数是否大于 5 次
        {
            YN = 0; // 如果循环次数超过 5 次，将逻辑变量 YN 置 0
        }
    }
    return 0;
}