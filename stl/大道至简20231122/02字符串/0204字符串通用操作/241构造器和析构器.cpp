#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str("12345678");
    char ch[] = "abcdefgh";
    string a;                             // 定义一个空字符串
    string str_1(str);                    // 构造函数， 全部复制
    string str_2(str, 2, 5);              // 构造函数， 从字符串 str 的第2 个元素开始， 复制5 个元素， 赋值给 str_2
    string str_3(ch, 5);                  // 将字符串 ch 的前 5 个元素赋值给 str_3
    string str_4(5, 'X');                 // 将 5 个 ‘X’ 组成的字符串 “XXXXX” 赋值给 str_4
    string str_5(str.begin(), str.end()); // 复制字符串 str 的所有元素， 并赋值给 str_5
    cout << str << endl;
    cout << a << endl;
    cout << str_1 << endl;
    cout << str_2 << endl;
    cout << str_3 << endl;
    cout << str_4 << endl;
    cout << str_5 << endl;
    return 0;
}