#include <iostream>
#include <string>
using namespace std;
template <class T1, class T2>
void print(T1 &ii, T2 &jj) // 函数模板
{
    cout << ii << endl;
    cout << jj << endl;
}
int main()
{
    string strA("Hello  Beijing!"); // 定义 string 对象
    int B = 50;
    print(strA, B); // 输出
    cin.get();
    return 0;
}