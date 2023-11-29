#include <iostream>
#include <string>
#include <regex>
#include <locale>
using namespace std;
int main()
{
    std::string pattern("ABCDEFG");
    std::regex first;
    std::regex second("123456");
    first.assign(second);
    second.assign("MNOPQRST", std::regex::ECMAScript | std::regex::icase);
    std::string replacement = "seven";
    std::cout << "first: " << regex_replace("MNOPQRST", first, replacement);
    std::cout << std::endl;
    std::cout << "two: " << regex_replace(pattern.c_str(), second, replacement);
    std::cout << std::endl;
    regex myrg("(sub)([a - z]* ). * ");
    cout << myrg.mark_count() << endl;
    cmatch m;
    regex_match("subject", m, myrg);
    if (m.size() == myrg.mark_count() + 1)
    {
        cout << "OK, all sub - expression captured. " << endl;
        cout << "Matched expression. " << m[0] << endl;
        for (unsigned i = 1; i < m.size(); ++i)
        {
            cout << "Sub - expression" << i << " :" << m[i] << endl;
        }
    }
    std::cout << "first ";
    std::cout << ((first.flags() & regex::icase) == regex::icase ? "is" : "is not");
    std::cout << " case insensitive. \n";
    std::cout << "second ";
    std::cout << ((second.flags() & regex::icase) == regex::icase ? "is" : "is not");
    std::cout << " case insensitive. \n";
    locale loc("English_US. 1251"); // the "C" locale
    myrg.imbue(loc);
    cout << myrg.getloc().name() << endl;
    cmatch mt;
    regex rx("abcdefgh");
    regex rx2;
    swap(rx, rx2);
    bool t = regex_search("abcdefghijk", mt, rx2);
    cout << "match(. ): " << mt.str() << endl;
    return 0;
}