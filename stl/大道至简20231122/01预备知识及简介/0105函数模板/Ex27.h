#ifndef Ex27_H
#define Ex27_H
#include <iostream>
#include <string>
#include <sstream>
template <typename T>
T fromString(const std::string &s) // 模板函数， 将字符串转化成其他数据类型
{
    std::istringstream is(s);
    T t;
    is >> t;
    return t;
}
template <typename T>
std::string toString(const T &t) // 模板函数， 将其他数据类型转换成字符串
{
    std::ostringstream s;
    s << t;
    return s.str();
}
#endif