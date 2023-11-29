#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    vector<int> v1;
    istream_iterator<int> inputCin(cin);
    istream_iterator<int> IEof;
    while (inputCin != IEof)
    {
        
        v1.push_back(*inputCin);
        ++inputCin;
    }
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    return 0;
}