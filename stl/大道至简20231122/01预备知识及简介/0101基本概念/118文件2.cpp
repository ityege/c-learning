#include <iostream>
#include <cstdio>
int main()
{
    using namespace std;
    cout << "This system can generate " << TMP_MAX << " temporary names of up to " << L_tmpnam << "characters. \n";
    char pszName[L_tmpnam] = {'\0'};
    cout << "Here are ten names: \n";
    for (int i = 0; i < 10; i++)
    {
        tmpnam(pszName); // 生成临时文件名
        cout << pszName << endl;
    }
    return 0;
}
