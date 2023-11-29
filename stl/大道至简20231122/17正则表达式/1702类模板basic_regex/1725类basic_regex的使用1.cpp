#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    string pattern = "^.*$";
    regex first;                                 // 默认方式
    regex second = first;                        // 复制
    regex third(pattern);                        // 初始化 string 对象
    regex fourth("<[^>]>");                // 初始化 string 表达式
    regex fifth(pattern.begin(), pattern.end()); // 以范围的形式进行初始化
    using namespace std::regex_constants;
    regex seventh("[0-9A-Z] + ", regex_constants::ECMAScript);
    regex eighth("[0-9A-Z] + ", ECMAScript);    // 与上一行语句作用相同
    regex ninth("\\bd\\w + ", ECMAScript | icase); // 多个标识
    string subject = "Duddy the duck \n";
    string replacement = "yup the duck 123456789 \n";
    cout << std::regex_replace(subject, ninth, replacement) << endl;
    return 0;
}