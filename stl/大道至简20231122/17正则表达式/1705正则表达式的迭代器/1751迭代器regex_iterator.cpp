#include <string>
#include <regex>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const char *pat = "axayazabcdefgh";
typedef std::regex_iterator<const char *> myiter;
string t;
int main()
{
    myiter::regex_type rx("a");
    myiter next(pat, pat + strlen(pat), rx);
    myiter end;
    for (; next != end; ++next)
    {
        cout << "match == " << next->str() << endl;
        t = next->suffix().str();
        pat = t.data();
        cout << " t: " << t << " ; pat: " << pat << endl;
    }
    cout << "First regex finished. " << endl;
    myiter it1(next);
    myiter it2;
    it2 = it1;
    // another
    string data = "<person>\n"
                  "<first>Nico</first>\n"
                  "<last>Josuttis</last>\n"
                  "</person>\n";
    regex reg("<(.*)>(.*)</(\\1)>");
    sregex_iterator pos(data.cbegin(), data.cend(), reg);
    sregex_iterator end1;
    for (; pos != end1; ++pos)
    {
        cout << "match: " << pos->str() << endl;
        cout << " tag: " << pos->str(1) << endl;
        cout << " value: " << pos->str(2) << endl;
    }
}