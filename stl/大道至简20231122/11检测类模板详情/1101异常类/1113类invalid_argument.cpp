#include <bitset>
#include <iostream>
using namespace std;
int main()
{
    try
    {
        bitset<32> bitset(string("11001010101100001b100101010110000"));
    }
    catch (exception &e)
    {
        cerr << "Caught " << e.what() << endl;
        cerr << "Type name: " << typeid(e).name() << endl;
    };
    return 0;
}