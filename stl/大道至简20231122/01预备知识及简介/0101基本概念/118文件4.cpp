#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <fstream>
#include <sstream>

int main(void)
{

    std::wstring line = L"中文宽字符测试";
    // 创建一个宽字符转窄字符的转换器
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;

    // 将宽字符字符串转换为窄字符字符串
    std::string narrowStr = converter.to_bytes(line);

    // 输出窄字符字符串
    std::cout << narrowStr << std::endl;

    return 0;
}