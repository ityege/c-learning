#include "Ex27.h"
#include <iostream>
#include <complex>
using namespace std;
int main()
{
    int i = 1234;
    float j = 567.34;
    complex<float> c(2.5, 4.1);
    cout << "i == \"" << toString(i) << "\"" << endl; // 将数字转换为字符串，并输出
    cout << "i == \"" << toString(j) << "\"" << endl; // 将数字转换为字符串，并输出
    cout << "i == \"" << toString(c) << "\"" << endl; // 将数字转换为字符串，并输出
    // …
    i = fromString<int>(string("1234"));                   // 将字符串转换为数字
    j = fromString<float>(string("567. 34"));              // 将字符串转换为数字
    c = fromString<complex<float>>(string("(2. 5,4. 1)")); ////将字符串转换为数字
    cout << "i == \"" << i << "\"" << endl;
    cout << "i == \"" << j << "\"" << endl;
    cout << "i == \"" << c << "\"" << endl;
    return 0;
}