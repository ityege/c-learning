#include <iostream>
#include <string>
#include <fstream>

/**
 * 宽字符是不能直接往控制台写的，也不能写入文件。
 * 
*/
int main(void)
{

    std::wstring str = L"中文测试";

    std::wofstream file("outputw.txt");

    file << "abc" << str << std::endl;
    file.close();

    std::wcout << str << std::endl;
    return 0;
}