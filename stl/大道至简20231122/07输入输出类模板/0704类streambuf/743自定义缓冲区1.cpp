#include <iostream>
#include <streambuf>
#include <locale>
#include <cstdio>
using namespace std;
class outbuf : public std::streambuf
{
protected:
    virtual int_type overflow(int_type c)
    {
        if (c != EOF)
        {
            c = std::toupper(c, getloc());
            if (putchar(c) == EOF)
            {
                return EOF;
            }
        }
        return c;
    }
};
int main()
{
    outbuf ob;
    std::ostream out(&ob); // 自定义输出缓冲区
    int num = 56;
    out << "56 十六进制数值: " << std::hex << std::showbase << num << endl;
    return 0;
}