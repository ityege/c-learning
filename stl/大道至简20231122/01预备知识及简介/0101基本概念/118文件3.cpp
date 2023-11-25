#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// 分割字符串
std::vector<std::wstring> splitString(const std::wstring &str, wchar_t delimiter)
{
    std::vector<std::wstring> tokens;
    std::wstring token;
    std::wistringstream tokenStream(str);

    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}
/**
 * 利用宽字符读和宽字符写的话，输出是一行，应该是文件的原始编码不是宽字符
*/
int main()
{
    std::wifstream inFile("input.txt");   // 打开输入文件
    std::wofstream outFile("output.txt"); // 打开输出文件

    if (inFile.is_open() && outFile.is_open())
    {
        std::wstring line;

        while (std::getline(inFile, line))
        {
            // 分割每行字符串
            std::vector<std::wstring> tokens = splitString(line, L'，');

            // 将分割后的字符串写入输出文件
            for (const auto &token : tokens)
            {
                outFile << token << std::endl;
            }
        }

        inFile.close();  // 关闭输入文件
        outFile.close(); // 关闭输出文件

        std::wcout << L"文件处理完成。" << std::endl;
    }
    else
    {
        std::wcout << L"无法打开文件。" << std::endl;
    }

    return 0;
}