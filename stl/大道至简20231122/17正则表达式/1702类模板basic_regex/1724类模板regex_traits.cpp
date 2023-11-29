#include <iostream>
#include <regex>
#include <locale>
#include <string>
#include <iomanip>
#include <string>
using namespace std;
// for lookup_collatename
struct noisy_traits : std::regex_traits<char>
{
    template <class Iter>
    string_type lookup_collatename(Iter first, Iter last) const
    {
        string_type result = regex_traits::lookup_collatename(first, last);
        std::cout << "regex_traits < > ::lookup_collatename(\""
                  << string_type(first, last)
                  << "\") returns \"" << result << "\"\n";
        return result;
    }
};
int main(int argc, char *argv[])
{
    locale loc("English_US. 1251"); // the "C" locale
    // std::locale::global(std::locale("en_US. UTF -8")); //设置新的环境,用 zh_CN. UTF - 8 试试,English_US. 1251
    locale old = locale::global(loc);
    regex_traits<char> rt1;
    cout << "The regex locale is " << rt1.getloc().name() << endl;
    cout << "The regex length: " << rt1.length("ABCDEFG12345") << endl;
    cout << "string length :" << regex_traits<char>::length("Кошка") << endl;
    cout << "string length :" << regex_traits<wchar_t>::length(L"Кошка") << endl;
    cout << "string length :" << regex_traits<char>::length("北京市是中国的首都. ") << endl;
    cout << "string length :" << regex_traits<wchar_t>::length(L"北京市是中国的首都. ") << endl;
    cout << "string length :" << regex_traits<char>::length("北京市是中国的首都") << endl;
    cout << "string length :" << regex_traits<wchar_t>::length(L"北京市是中国的首都") << endl;
    regex_traits<char>::char_type ch = rt1.translate('B');
    cout << ch << endl;
    ch = rt1.translate_nocase('B');
    cout << "B ---- > (tolower): " << ch << endl;
    string st("ANBFGJ");
    regex_traits<char>::string_type st2;
    st2 = rt1.transform(&*st.begin(), &*(--st.end()));
    st = rt1.transform_primary(&*st.begin(), &*(--st.end()));
    cout << st2 << endl;
    cout << st << endl;
    std::string sl("z|}a");
    std::regex rg("abcd", std::regex::ECMAScript);
    std::cout << std::boolalpha << std::regex_match(sl, rg) << std::endl;
    string sy("alnum");
    auto a = rt1.lookup_classname(sy.begin(), sy.end());
    cout << "classname: " << a << endl;
    string tmps = rt1.lookup_collatename(sy.begin(), sy.end());
    cout << "collatename: " << tmps << endl;
    cout << "hex C == " << rt1.value('C', 16) << endl;
    string sy2("space");
    auto b = rt1.lookup_classname(sy2.begin(), sy2.end());
    cout << "class name: " << b << endl;
    cout << rt1.isctype('G', a) << endl;
    cout << rt1.isctype('_', a) << endl;
    cout << rt1.isctype(' ', a) << endl;
    cout << rt1.isctype('G', b) << endl;
    cout << rt1.isctype('_', b) << endl;
    cout << rt1.isctype(' ', b) << endl;
    auto myloc = rt1.getloc();
    cout << myloc.name() << endl;
    regex_traits<char>::locale_type locn(old);
    rt1.imbue(locn);
    myloc = rt1.getloc();
    cout << '\"' << myloc.name() << '\"' << endl;
    return 0;
}