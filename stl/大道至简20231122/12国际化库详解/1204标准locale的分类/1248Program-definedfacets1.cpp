#include <iostream>
#include <locale>
using namespace std;
int main()
{
    cin.imbue(locale("German_Germany"));
    cout.imbue(locale::classic());
    double f;
    cin >> f;          // 输入按德国形式
    cout << f << endl; // 输出按经典（本地）形式
    cout << "cin. fail() :" << cin.failbit << endl;
    return 0;
}