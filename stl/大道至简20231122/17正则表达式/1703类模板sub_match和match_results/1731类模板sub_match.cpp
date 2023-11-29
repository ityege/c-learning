#include <regex>
#include <iostream>
int main()
{
    std::regex rx("c(a* )|(b)");
    std::cmatch mr;
    std::regex_search("xcaaay", mr, rx); // 判断是否有子字符串和正则表达式相匹配
    std::csub_match sub = mr[1];
    std::cout << "matched == " << std::boolalpha
              << sub.matched << std::endl;
    std::cout << "length == " << sub.length() << std::endl;
    std::csub_match::difference_type dif = std::distance(sub.first, sub.second);
    std::cout << "difference == " << dif << std::endl;
    std::csub_match::iterator first = sub.first;
    std::csub_match::iterator last = sub.second;
    std::cout << "range == " << std::string(first, last)
              << std::endl;
    std::cout << "string == " << sub << std::endl;
    std::csub_match::value_type *ptr = "aab";
    std::cout << "compare(\"aab\") == "
              << sub.compare(ptr) << std::endl;
    std::cout << "compare(string) == "
              << sub.compare(std::string("AAA")) << std::endl;
    std::cout << "compare(sub) == "
              << sub.compare(sub) << std::endl;
    return (0);
}