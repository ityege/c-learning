#include <iostream>
#include <string>
using namespace std;
template <typename T>
void print(const T &var) // 也可以使用 template < class T > 声明函数模板
{
    cout << var << endl;
}
int main()
{
    string str("Hello Beijing!");
    print(str);
    cin.get();
    return 0;
}