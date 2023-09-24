#include <iostream>
#include <gnu/libc-version.h>
/***
 * 确定系统的 glibc 版本
 * /lib/libc.so.6
 * 我实践是这个目录
 * /lib/x86_64-linux-gnu/libc.so.6
GNU C Library (Ubuntu GLIBC 2.31-0ubuntu9) stable release version 2.31.
Copyright (C) 2020 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.
Compiled by GNU CC version 9.3.0.
libc ABIs: UNIQUE IFUNC ABSOLUTE
For bug reporting instructions, please see:
<https://bugs.launchpad.net/ubuntu/+source/glibc/+bugs>.
 *
*/

int main()
{
    std::cout << gnu_get_libc_version() << std::endl;
    return 0;
}