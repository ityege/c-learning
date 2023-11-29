#include <exception>
#include <iostream>
#include <istream>
#include <ostream>
using namespace std;

int main()
{
    ios::iostate olde = cin.exceptions();       // 返回 cin 的异常标志位
    cout << "old exceptions: " << olde << endl; // 输出该标志位
    int x = 0;
    try
    {
        cin.exceptions(ios::eofbit | ios::failbit | ios::badbit); // 设置引发异常的标志位
        // cin. exceptions(ios::goodbit);
        cin >> x;
    }
    catch (exception &e)
    {
        cout << "exception: " << e.what() << endl; // 输出异常类别
    }
    return 0;
}