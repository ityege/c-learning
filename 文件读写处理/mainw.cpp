#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <codecvt>
#include <locale>

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
/***
 *
 * 窄字符读入转成宽字符处理，处理完成再转成窄字符输出或者输出文件。
 *
 */
int main()
{

    // 创建一个宽字符窄字符的转换器
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;

    std::ifstream inFile("input.txt");   // 打开输入文件
    std::ofstream outFile("output.txt"); // 打开输出文件

    if (inFile.is_open() && outFile.is_open())
    {
        std::string line;

        while (std::getline(inFile, line))
        {

            std::wstring lineWideStr = converter.from_bytes(line);

            // 分割每行字符串
            std::vector<std::wstring> tokens = splitString(lineWideStr, L'，');

            // 打印在控制台
            for (const auto &token : tokens)
            {
                // 将宽字符字符串转换为窄字符字符串
                std::string narrowStr = converter.to_bytes(token);
                // 输出窄字符字符串
                std::cout << narrowStr << std::endl;
                // 将分割后的字符串写入输出文件
                outFile << narrowStr << std::endl;
            }
        }

        inFile.close();  // 关闭输入文件
        outFile.close(); // 关闭输出文件

        std::cout << "文件处理完成。" << std::endl;
    }
    else
    {
        std::cout << "无法打开文件。" << std::endl;
    }

    return 0;
}