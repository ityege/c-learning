#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
struct B
{
    virtual void print() = 0;
};
struct D1 : public B
{
    void print()
    {
        cout << "I'm a D1. " << endl;
    }
};
struct D2 : public B
{
    void print()
    {
        cout << "I'm a D2. " << endl;
    }
};
int main(int argc, char *argv[])
{
    vector<D1> v;
    v.push_back(D1());
    v.push_back(D1());
    for_each(v.begin(), v.end(), mem_fun_ref(&B::print));
    vector<vector<int>> v2;
    v2.push_back(vector<int>(2));
    v2.push_back(vector<int>(7));
    v2.push_back(vector<int>(3));
    transform(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "), mem_fun_ref(&vector<int>::size));
    cout << endl;
    return 0;
}