#include <iostream>
using namespace std;
int main()
{
    char *cstring = "Hello"; // 输出地址时需要使用 void*
    cout << "string \" "
         << " " << cstring << " \" "
         << "is located at address: " << static_cast<void *>(cstring) << endl;
    cout << "string \" "
         << " " << cstring << " \" "
         << "is located at address: " << (void *)cstring << endl;
    return 0;
}