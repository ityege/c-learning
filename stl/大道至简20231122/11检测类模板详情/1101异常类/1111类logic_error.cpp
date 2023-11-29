#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
int main()
{
    try
    {
        throw logic_error("logic error: 2012-9-11. ");
    }
    catch (exception &ep)
    {
        cerr << "Caught: " << ep.what() << endl;
        cerr << "Type name: " << typeid(ep).name() << endl;
    };
    return 0;
}