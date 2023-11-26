#pragma warning(disable : 4786)
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> myvt;
    myvt.reserve(4);
    myvt.push_back(" 1. Beijing City. ");
    myvt.push_back(" 2. Tianjin City. ");
    myvt.push_back(" 3. Shanghai City. ");
    myvt.push_back(" 4. Chongqing City. ");
    cout << " OK!" << endl;
    cout << " 成功消除编译警告信息!" << endl;
    vector<string>::iterator it;
    for (it = myvt.begin(); it != myvt.end(); it++)
        cout << *it << endl;
    cin.get();
    return 0;
}