#include <iostream>
#include <bitset>
#include <string>
using namespace std;
int main()
{
    bitset<10> bs1(7);                    // bitset 中长度为 10 个 bit；初始化为十进制数 7
    bitset<10> bs2(string("1000101011")); // 初始化为 10 个字符长度的字符串
    cout << bs1 << endl;                  // 输出
    cout << bs2 << endl;                  // 输出
    cin.get();                            // 任意键退出
    return 0;
}