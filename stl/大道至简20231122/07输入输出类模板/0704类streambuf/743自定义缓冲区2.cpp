#include <iostream>
#include <io.h>
#include <streambuf>
#include <cstdio>
using namespace std;
static const int bufferSize = 10;
class outbuf : public std::streambuf
{
protected:
    char buffer[bufferSize];

public:
    outbuf()
    {
        setp(buffer, buffer + (bufferSize - 1)); // 输出
    }
    virtual ~outbuf()
    {
        sync();
    }

protected:
    int flushBuffer()
    {
        int num = pptr() - pbase();
        if (write(1, buffer, num) != num)
        {
            return EOF;
        }
        pbump(-num);
        return num;
    }
    virtual int_type overflow(int_type c)
    {
        if (c != EOF)
        {
            *pptr() = c;
            pbump(1);
        }
        if (flushBuffer() == EOF)
        {
            return EOF;
        }
        return c;
    }
    virtual int sync()
    {
        if (flushBuffer() == EOF)
        {
            return -1;
        }
        return 0;
    }
};
class fdostream : public std::ostream
{
protected:
    outbuf buf;

public:
    fdostream(int fd) : ostream(0)
    {
        rdbuf(&buf);
    }
};
int main()
{
    fdostream out(1); // 设置输出缓冲区
    out << "51 hexadecimal: " << std::hex << std::showbase << 51 << endl;
    return 0;
}