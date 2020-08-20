/* 用时  min */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int m, n; //m宽n高
int p, q;
const int N = 1085;
const int M = 1925;
struct RGB
{
    int r;
    int g;
    int b;
};
RGB colors[M][N];

int main()
{
    string buf = "\033[38;2;255;0;0m \033[38;2;0;0;255m \033[0m\n";
    string b1 = "\x1B\x5B\x34\x38\x3B\x32\x3B\x30\x3B\x30\x3B\x31\x6D\x20\x1B\x5B\x30\x6D\x20\x20\x0A";
    /*
    for (int i = 0; i < b1.length(); i++)
    {
        printf("/x%02X", b1[i]);
    }
    */
    // printf("\033[38;2;255;0;0m \033[38;2;0;0;255m \033[0m\n");
    printf("%s",b1.c_str());

    return 0;
}
\x1B\x5B\x34\x38\x3B\x32\x3B\x30\x3B\x30\x3B\x31\x6D \x20  \x1B\x5B\x30\x6D \x20 \x1B\x5B\x30\x6D \x20 \x1B\x5B\x30\x6D  \x0A

3 2 
1 2
#abc
#f
#1a2b3c
#123
#a1b2c3
#0

\x1B\x5B\x34\x38\x3B\x32\x3B\x39\x33\x3B\x31\x31\x30\x3B\x31\x32\x37\x6D打印颜色R:93G:110B:127\x20打印空格\x1B\x5B\x34\x38\x3B\x32\x3B\x32\x30\x38\x3B\x32\x31\x36\x3B\x32\x32\x35\x6D打印颜色R:208G:216B:225\x20打印空格\x1B\x5B\x34\x38\x3B\x32\x3B\x31\x33\x3B\x32\x31\x3B\x33\x30\x6D打印颜色R:13G:21B:30\x20打印空格\x1B\x5B\x30\x6D行尾恢复默认\x0A换行
\x1B\x5B\x34\x38\x3B\x32\x3B\x39\x33\x3B\x31\x31\x30\x3B\x31\x32\x37\x6D打印颜色R:93G:110B:127\x20打印空格\x1B\x5B\x34\x38\x3B\x32\x3B\x32\x30\x38\x3B\x32\x31\x36\x3B\x32\x32\x35\x6D打印颜色R:208G:216B:225\x20打印空格\x1B\x5B\x34\x38\x3B\x32\x3B\x31\x33\x3B\x32\x31\x3B\x33\x30\x6D打印颜色R:13G:21B:30\x20打印空格\x1B\x5B\x30\x6D行尾恢复默认\x0A换行

\x1B\x5B\x34\x38\x3B\x32\x3B\x39\x33\x3B\x31\x31\x30\x3B\x31\x32\x37\x6D\x20\x1B\x5B\x34\x38\x3B\x32\x3B\x32\x30\x38\x3B\x32\x31\x36\x3B\x32\x32\x35\x6D\x20\x1B\x5B\x34\x38\x3B\x32\x3B\x31\x33\x3B\x32\x31\x3B\x33\x30\x6D\x20\x1B\x5B\x30\x6D\x0A
\x1B\x5B\x34\x38\x3B\x32\x3B\x39\x33\x3B\x31\x31\x30\x3B\x31\x32\x37\x6D\x20\x1B\x5B\x34\x38\x3B\x32\x3B\x32\x30\x38\x3B\x32\x31\x36\x3B\x32\x32\x35\x6D\x20\x1B\x5B\x34\x38\x3B\x32\x3B\x31\x33\x3B\x32\x31\x3B\x33\x30\x6D\x20\x1B\x5B\x30\x6D\x0A
\x1B\x5B\x34\x38\x3B\x32\x3B\x39\x33\x3B\x31\x31\x30\x3B\x31\x32\x37\x6D\x20\x1B\x5B\x34\x38\x3B\x32\x3B\x32\x30\x38\x3B\x32\x31\x36\x3B\x32\x32\x35\x6D\x20\x1B\x5B\x34\x38\x3B\x32\x3B\x31\x33\x3B\x32\x31\x3B\x33\x30\x6D\x20\x1B\x5B\x30\x6D\x0A
\x1B\x5B\x34\x38\x3B\x32\x3B\x30\x3B\x30\x3B\x30\x6D\x20\x1B\x5B\x34\x38\x3B\x32\x3B\x39\x33\x3B\x31\x31\x30\x3B\x31\x32\x37\x6D\x20\x1B\x5B\x34\x38\x3B\x32\x3B\x32\x30\x38\x3B\x32\x31\x36\x3B\x32\x32\x35\x6D\x20\x1B\x5B\x30\x6D\x0A