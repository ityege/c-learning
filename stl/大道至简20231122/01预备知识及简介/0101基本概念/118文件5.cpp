#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// 分割字符串
std::vector<std::wstring> splitString1(const std::wstring &str, wchar_t delimiter)
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
 * 
 * 利用宽字符读和宽字符写的话，输出是一行，应该是文件的原始编码不是宽字符
 * 
*/
void test1()
{

    std::wifstream inFile("input.txt");    // 打开输入文件
    std::wofstream outFile("output1.txt"); // 打开输出文件

    if (inFile.is_open() && outFile.is_open())
    {
        std::wstring line;

        while (std::getline(inFile, line))
        {
            // 分割每行字符串
            std::vector<std::wstring> tokens = splitString1(line, L'，');

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
}

// 分割字符串
std::vector<std::string> splitString2(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);

    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

/**
 * 
 * 用窄字符读，但是截取的有问题，英文窄字符只有一位，但是中文字符一位编码是不够的。切出来有破损乱码字符
 * 
*/
void test2()
{

    std::ifstream inFile("input.txt");    // 打开输入文件
    std::ofstream outFile("output2.txt"); // 打开输出文件

    if (inFile.is_open() && outFile.is_open())
    {
        std::string line;

        while (std::getline(inFile, line))
        {
            // 分割每行字符串
            std::vector<std::string> tokens = splitString2(line, '，');

            // 将分割后的字符串写入输出文件
            for (const auto &token : tokens)
            {
                outFile << token << std::endl;
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
}
int main()
{
    test1();
    test2();

    return 0;
}