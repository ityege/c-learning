#include <iostream>
// #include <stdexcept>
using namespace std;
int main()
{
    try
    {
        throw domain_error("Your domain is in error!");
    }
    catch (domain_error &e)
    {
        cerr << "Caught: " << e.what() << endl;
        cerr << "Type name: " << typeid(e).name() << endl;
    };
    return 0;
}