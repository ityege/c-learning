#include <iostream>
#include <string>
int main()
{
    const std::string cS("conststring");
    std::string s("abcde");
    char temp = 0;
    char temp_1 = 0;
    char temp_2 = 0;
    char temp_3 = 0;
    char temp_4 = 0;
    char temp_5 = 0;
    temp = s[2];                 // 获取字符 ‘c’
    temp_1 = s.at(2);            // 获取字符 ‘c’
    temp_2 = s[s.length()];      // 未定义行为， 返回字符 ‘ \0’, 但 Visual C++2012 执行时未报错
    temp_3 = cS[cS.length()];    // 指向字符 ‘ \0’
    temp_4 = s.at(s.length());   // 程序异常
    temp_5 = cS.at(cS.length()); // 程序异常
    std::cout << temp << temp_1 << temp_2 << temp_3 << temp_4 << temp_5 << std::endl;
    return 0;
}