#include <iostream>
#include <locale>
#include <string>
using namespace std;
int main()
{
    locale loc1("german");
    locale loc2 = locale::global(loc1);
    cout << loc1.name() << ". " << endl;
    cout << loc2.name() << ". " << endl;
    locale loc3 = locale::global(std::locale(""));
    cout << loc3.name() << endl;
    return 0;
}