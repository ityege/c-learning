#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1("123456");
    string str;
    str.assign(str1); // 直接赋值
    cout << str << endl;
    str.assign(str1, 3, 3); // 赋值给子串
    cout << str << endl;
    str.assign(str1, 2, str1.npos); // 赋值给从位置 2 至末尾的子串
    cout << str << endl;
    str.assign(5, 'X'); // 重复 5 个‘X’字符
    cout << str << endl;
    string::iterator itB;
    string::iterator itE;
    itB = str1.begin();
    itE = str1.end();
    str.assign(itB, (--itE)); // 从第 1 个至倒数第 2 个元素，赋值给字符串 str
    cout << str << endl;
    return 0;
}