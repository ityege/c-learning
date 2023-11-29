#include <iostream>
#include <regex>
using namespace std;
int main(int argc, char *argv[])
{
    cmatch m1;
    if (m1.empty())
        cout << "m1 is empty. " << endl;
    else
        cout << "m1 is full. " << endl;
    string st1 = "subject";
    regex rgx_rule("(sub)(. * )");
    regex_match(st1.data(), m1, rgx_rule);
    if (m1.ready())
        cout << "match ready. . . " << endl;
    if (m1.empty())
        cout << "m1 is empty. " << endl;
    else
        cout << "m1 is full. " << endl;
    cout << "m1 size: " << m1.size() << endl;
    for (unsigned i = 0; i < m1.size(); ++i)
        cout << "match (" << i << ")"
             << " : " << m1[i] << endl;
    for (unsigned i = 0; i < m1.size(); ++i)
        cout << "match (" << i << ") length is "
             << " : " << m1[i].length() << endl;
    for (unsigned i = 0; i < m1.size(); ++i)
        cout << "match (" << i << ") position is "
             << " : " << m1.position(i) << endl;
    for (unsigned i = 0; i < m1.size(); ++i)
        cout << "match (" << i << ") content is "
             << " : " << m1[i].str() << endl;
    cout << "match content is \" ";
    for (cmatch::iterator it = m1.begin(); it != m1.end(); ++it)
    {
        cout << *it << ", ";
    }
    cout << "\"" << endl;
    string s2("there is a needle in this haystack");
    smatch m2;
    regex e2("needle");
    cout << "searching for needle in [" << s2 << "]\n";
    regex_search(s2, m2, e2);
    if (m2.ready())
    {
        cout << m2[0] << " found! \n";
        cout << "prefix: [" << m2.prefix() << "]" << endl;
        cout << "suffix: [" << m2.suffix() << "]" << endl;
    }
    cout << m2.format("the prefix expression matched [＄′]. ") << endl;
    cout << m2.format("the suffix expression matched [＄']. ") << endl;
    smatch m3;
    m2.swap(m3);
    for (unsigned i = 0; i < m3.size(); ++i)
        cout << "match (" << i << ") content is "
             << " : " << m3[i].str() << endl;
    cout << "\"" << endl;
    cmatch m4;
    m1.swap(m4);
    for (unsigned i = 0; i < m4.size(); ++i)
        cout << "match (" << i << ") content is "
             << " : " << m4[i].str() << endl;
    cout << "\"" << endl;
    cout << m4.format("the expression 0 matched [＄ 0]. \n") << endl;
    cout << m4.format("the expression 1 matched [＄ 1]. \n") << endl;
    cout << m4.format("the expression 2 matched [4 ＄ 2]. \n") << endl;
    cout << m4.format("the entire expression matched [＄ &]. \n") << endl;
    return 0;
}