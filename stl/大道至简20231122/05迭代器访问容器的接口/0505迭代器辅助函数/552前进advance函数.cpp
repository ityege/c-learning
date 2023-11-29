#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    int dim[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l1;
    copy(dim, dim + 9, back_inserter(l1));
    copy(l1.begin(), l1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    list<int>::iterator pos;
    pos = find(l1.begin(), l1.end(), 5);
    if (pos != l1.end())
    {
        cout << "The distance between beginning and 5: " << distance(l1.begin(), pos) << endl;
    }
    else
    {
        cout << "5 not found. " << endl;
    }
    return 0;
}