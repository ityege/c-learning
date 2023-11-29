#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    string s("subject");
    regex e("(sub)(. *)");
    cout << "s: subject ; e: (sub)(. *) . " << endl;
    if (regex_match("subject", std::regex("(sub)(. *)")))
        cout << "regex_match(s,e) . . . . . . matched. \n";
    else
        cout << "regex_match(s,e) is not matcged. " << endl;
    if (std::regex_match(s.begin(), s.end(), e))
        cout << "iterator range matched\n";
    cmatch cm; // same as std::match_results < const char* > cm;
    cout << "cmatch cm. . . " << endl;
    regex_match("subject", cm, e);
    cout << "regex_match (\"subject\",cm,e); " << cm.size() << "is matches\n";
    smatch sm; // same as std::match_results < string::const_iterator > sm;
    cout << "smatch sm. . . " << endl;
    regex_match(s, sm, e);
    cout << "regex_match (s,sm,e), sm. size = " << sm.size() << " matches\n";
    regex_match(s.cbegin(), s.cend(), sm, e);
    cout << "range with " << sm.size() << " matches" << endl;
    std::cout << "the matches sm were: ";
    for (unsigned i = 0; i < sm.size(); ++i)
    {
        std::cout << "[" << sm[i] << "] ";
    }
    cout << ". " << endl;
    // using explicit flags:
    regex_match("subject", cm, e, std::regex_constants::match_default);
    std::cout << "the matches cm were: ";
    for (unsigned i = 0; i < cm.size(); ++i)
    {
        std::cout << "[" << cm[i] << "] ";
    }
    std::cout << ". " << std::endl;
    return 0;
}