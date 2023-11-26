#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    int col[] = {1, 5, 7, 2, 8};
    sort(col, col + 5);
    copy(col, col + 5, ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}