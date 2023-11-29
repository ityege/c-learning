#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;
int main()
{
    vector<int> v1;
    int dim[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    v1.assign(dim, dim + 9);
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    replace(v1.begin(), v1.end(), 7, 99);
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    replace_if(v1.begin(), v1.end(), bind(less<int>(), placeholders::_1, 5), 11);
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    return 0;
}