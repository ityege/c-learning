#include <string>
#include <regex>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int dim[2] = {0, 2};
    string data = "<person>\n"
                  "<first>Nico</first>\n"
                  "<last>Josuttis</last>\n"
                  "</person>\n";
    regex reg("<(.*)>(.*)</(\\1)>");                      // 遍历所有相匹配的子串 (使用 regex_token_iterator):
    sregex_token_iterator pos(data.cbegin(), data.cend(), // 序列形式
                              reg,                        // 间隔符号表达式
                              dim);
    sregex_token_iterator end;
    for (; pos != end; ++pos)
    {
        cout << "match: " << pos->str() << endl;
    }
    cout << endl;
    string names = "nico, jim, helmut, paul, tim, john paul, rita";
    regex sep("[\t\n]*[,;.][\t\n]*");                     // 以“：”或“. ”与空格间隔
    sregex_token_iterator p(names.cbegin(), names.cend(), // 序列形式
                            sep,                          // 间隔符
                            -1);                          // -1: 间隔符之间的值
    sregex_token_iterator e;
    for (; p != e; ++p)
    {
        cout << "name: " << *p << endl;
    }
    return 0;
}