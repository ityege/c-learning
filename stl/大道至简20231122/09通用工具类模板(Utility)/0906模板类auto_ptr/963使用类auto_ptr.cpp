#include <memory>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    std::unique_ptr<std::string> str(new std::string("Goose eggs. "));
    std::unique_ptr<std::string> str2(std::move(str));
    std::unique_ptr<std::string> str3(new std::string("Chicken runs. "));

    cout << str.get() << endl;
    cout << str2.get() << endl;
    cout << str3.get() << endl;
    //cout << "str: " << *str << endl;
    cout << "str2: " << *str2 << endl;
    cout << "str3: " << *str3 << endl;

    return 0;
}