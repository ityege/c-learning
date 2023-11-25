#include <iostream>
#include <string>

/**
 * 宽字符是不可以直接往控制台写的
*/
int main(void)
{

    std::wstring line = L"中文测试";

    std::wcout << line << std::endl;

    return 0;
}