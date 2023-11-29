#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ostreambuf_iterator<char> bufwrite(cout);
    string hello("Hello, world! \n");
    copy(hello.begin(), hello.end(), bufwrite); // 复制字符串至缓冲区
    istreambuf_iterator<char> inpos(cin);
    istreambuf_iterator<char> endpos;
    ostreambuf_iterator<char> outpos(cout);
    while (inpos != endpos)
    {
        *outpos = *inpos;
        ++inpos;
        ++outpos;
    }
    return 0;
}