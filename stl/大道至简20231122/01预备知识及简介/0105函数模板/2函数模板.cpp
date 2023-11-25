#include <iostream>
#include <string>
using namespace std;
template <class T>
void print(T &ii, T &jj) // 函数模板
{
    cout << ii << endl;
    cout << jj << endl;
}
int main()
{
    string strA("Hello Beijing!");
    string strB("I am a programmer!");
    print(strA, strB);
    cin.get();
    return 0;
}
