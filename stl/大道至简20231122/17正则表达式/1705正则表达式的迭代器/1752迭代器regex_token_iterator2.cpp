#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
    string s("This subject has a submarine as a subsequence. ");
    cout << "Original string(1): " << s << endl;
    regex rgx("\\b(sub)([^]*)");
    typedef regex_token_iterator<string::iterator> mytoken_iter;
    mytoken_iter rend;
    cout << "all matches: ";
    mytoken_iter a(s.begin(), s.end(), rgx);
    while (a != rend)
    {
        cout << "[" << *a++ << "]";
    }
    cout << endl;
    cout << "2nd submatches: ";
    mytoken_iter b(s.begin(), s.end(), rgx, 2);
    while (b != rend)
    {
        cout << "[" << *b++ << "]";
    }
    cout << endl;
    cout << "1st and 2nd submarine: ";
    int dim[2] = {1, 2};
    mytoken_iter c(s.begin(), s.end(), rgx, dim);
    while (c != rend)
    {
        cout << "[" << *c++ << "]";
    }
    cout << endl;
    sregex_token_iterator rend1;
    cout << "As a splitter : ";
    sregex_token_iterator d(s.cbegin(), s.cend(), rgx, -1);
    while (d != rend1)
    {
        cout << "[" << *d << "]";
        d++;
    }
    cout << endl;
    string s1("This subject, has a submarine, as a, subsequence. ");
    cout << "Original string(2): " << s1 << endl;
    regex rgx1("[\t\n]*[,;.][\t\n]*"); //[ \t\n]* [,;. ][ \t\n]* //\\b(,)
    // mytoken_iter e(s1. cbegin(),s1. cend(),rgx1, -1);
    sregex_token_iterator e(s1.cbegin(), s1.cend(), rgx1, -1);
    while (e != rend1)
    {
        cout << "[" << *e << "]";
        e++;
    }
    cout << endl;
    // cout << "regex (\"[,]* \")"
    regex rgx2("[\t\n]*[,;.][\t\n]*");
    sregex_token_iterator f(s1.cbegin(), s1.cend(), rgx2, -1);
    while (f != rend1)
    {
        cout << "[" << *f << "]";
        f++;
    }
    cout << endl;
    string s2("This subject. has a submarine, as a; subsequence. ");
    cout << "Original string(3): " << s2 << endl;
    regex rgx3("[\t]*[,;.][\t]*");
    sregex_token_iterator g(s2.cbegin(), s2.cend(), rgx3, -1);
    while (g != rend1)
    {
        cout << "[" << *g << "]";
        g++;
    }
    cout << endl;
    cout << "Original string(4): " << s2 << endl;
    regex rgx4("[\t]*[,;.][\t]*"); //[ \t]* [,;. ][ \t]*
    sregex_token_iterator h(s2.begin(), s2.end(), rgx4);
    while (h != rend1)
    {
        cout << "[" << *h << "]";
        h++;
    }
    cout << endl;
    cout << "Original string(5): " << s2 << endl;
    regex rgx5("[\t]*[,;.][\t]*"); //\\b(sub)([^]* )
    sregex_token_iterator h1(s2.begin(), s2.end(), rgx5, -1);
    while (h1 != rend1)
    {
        cout << "[" << *h1 << "]";
        h1++;
    }
    cout << endl;
    return 0;
}