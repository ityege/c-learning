#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double vard = 15.432;
    cout << setprecision(4) << vard << endl;
    cout.precision(6);
    cout << vard << endl;
    cout << "ios::fixed usage: " << endl; // 浮点数输出
    cout << setiosflags(ios::fixed) << vard << endl;
    cout << "ios::scientific: " << endl;
    cout << "fixed usage: " << endl;
    cout << fixed << vard << endl; // 浮点数输出
    cout << "scientific usage: " << endl;
    cout << scientific << vard << endl;
    return 0;
}