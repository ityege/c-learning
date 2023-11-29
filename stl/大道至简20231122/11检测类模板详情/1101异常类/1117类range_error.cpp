#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    range_error re("Error type: range_error. ");
    try
    {
        locale loc("test");
    }
    catch (...)
    {
        cout << re.what() << endl;
        cout << typeid(re).name() << endl;
    }
    return 0;
}