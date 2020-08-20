#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string trans1(string str)
{
    int pos = str.find_first_of("\\\\");
    cout << pos << endl;
    if (pos == -1)
        return str;
    string s1, s2;

    s1 = str.substr(0, pos) + "\\";
    s2 = pos + 2 >= str.length() ? "" : trans1(str.substr(pos + 2));
    return s1 + s2;
}

string trans2(string str)
{
    int pos = str.find_first_of("\\\"");
    cout << pos << endl;
    if (pos == -1)
        return str;
    string s1, s2;

    s1 = str.substr(0, pos) + "\"";
    s2 = pos + 2 >= str.length() ? "" : trans2(str.substr(pos + 2));
    return s1 + s2;
}

//转义
string trans(string str)
{
    str = trans1(str);
    str = trans2(str);
    return str;
}

int main()
{
    string str;
    getline(cin, str);
    str = trans2(str);
    printf("%s\n", str.c_str());
    return 0;
}