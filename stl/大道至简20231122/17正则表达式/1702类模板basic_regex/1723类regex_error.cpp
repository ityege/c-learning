#include <iostream>
#include <regex>
using namespace std;
int main()
{
    try
    {
        std::regex myregex("* ");
    }
    catch (std::regex_error &e)
    {
        if (e.code() == std::regex_constants::error_badrepeat)
            cerr << "Exception: A valid regular expression. \n"
                 << endl;
        else
            cerr << "Some other regex exception happened. \n"
                 << endl;
    }
    return 0;
}