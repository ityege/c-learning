#include <iostream>
#include <iterator> // 添加此头文件以解决 'ostream_iterator' 未声明的问题
#include <functional>
#include <algorithm>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    map<int, double> M;
    M[1] = 0.3;
    M[47] = 0.8;
    M[33] = 0.1;

    cout << "抽取键值：";
    transform(M.begin(), M.end(), ostream_iterator<int>(cout, " "),
              [](const pair<const int, double>& p) { return p.first; });
    cout << endl;

    cout << "抽取实值：";
    transform(M.begin(), M.end(), ostream_iterator<double>(cout, " "),
              [](const pair<const int, double>& p) { return p.second; });
    cout << endl;

    return 0;
}