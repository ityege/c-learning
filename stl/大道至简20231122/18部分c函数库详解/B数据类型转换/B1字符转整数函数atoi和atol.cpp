#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[])
{
    char str[10] = "1234abcd";
    char str1[10] = "4567";
    char str2[10] = "b2345";
    int A = atoi(str);
    int B = atoi(str1);
    int C = atoi(str2);
    cout << "A: " << A << " , "
         << "B: " << B << " , "
         << "C :" << C << endl;
    return 0;
}