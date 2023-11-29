#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    string s("This subject has a submarine as a subsequence");
    smatch m;
    regex e("\\b(sub)([^ ]* )"); // matches words beginning by "sub"
    cout << "Target sequence: " << s << endl;
    cout << "Regular expression: /\\b(sub)([^ ]* )/" << endl;
    cout << "The following matches and submatches were found:" << endl;
    while (regex_search(s, m, e))
    {
        for (auto x : m) // 注意此处
            cout << x << " ";
        cout << endl;
        s = m.suffix().str(); // 继续找
    }
    return 0;
}