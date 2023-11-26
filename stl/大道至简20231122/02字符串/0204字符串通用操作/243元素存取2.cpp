#include <iostream>
#include <string>

int main()
{
    std::string s("abcde");
    std::cout << s << std::endl;
    char &r = s[2];              // 建立引用关系
    char *p = &s[3];             // 建立引用关系
    r = 'X';                     // 修改内容
    *p = 'Y';                    // 修改内容
    std::cout << s << std::endl; // 输出
    s = "12345678";              // 重新赋值
    r = 'X';                     // 修改内容
    *p = 'Y';                    // 修改内容
    std::cout << s << std::endl; // 输出
    return 0;
}