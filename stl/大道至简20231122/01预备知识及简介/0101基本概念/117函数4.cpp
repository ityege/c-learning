#include <iostream>
#include <cstring>
#include <string>

using namespace std;
extern int A; // 外部变量
extern int B; // 外部变量
int main()
{
    auto int x = 0;           // auto 类型整数变量
    register int y = 0;   // register 类型整数变量
    static int count = 0; // 静态存储类型整型变量
    char *ch = new char();
    sprintf(ch, "%d,%d,%d,%d,%d.", x, y, count, A, B);
    cout << ch << endl; // 输出
    return 0;
}