#include <iostream>
#include <locale>
/**
 * 这一段代码msvc可以在控制台正确输出中文,g++在linux平台正常执行，但是在windows平台会报错。
 * 
 * 
*/
int main() {
    // 设置本地化
    std::locale::global(std::locale(""));

    // 创建宽字符字符串
    std::wstring wideStr = L"这是一个宽字符字符串";

    // 输出宽字符字符串
    std::wcout.imbue(std::locale());
    std::wcout << wideStr << std::endl;

    return 0;
}
