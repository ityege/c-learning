#include <iostream>
#include <string>
#include <regex>
#include <iterator>
using namespace std;
int main()
{
    string s("there is a subsequence in the string\n");
    // matches words beginning by "sub"
    regex e("\\b(sub)([^ ]*)");
    // using string/c - string (3) version:
    cout << std::regex_replace(s, e, "sub - $2");
    // using range/c - string (6) version:
    string result;
    regex_replace(std::back_inserter(result), s.begin(), s.end(), e, "$2");
    cout << result;
    // with flags:
    cout << std::regex_replace(s, e, "$1 and $2", std::regex_constants::format_no_copy);
    cout << std::endl;
    return 0;
}