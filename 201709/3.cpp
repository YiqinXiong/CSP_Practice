/* 
*   用时 2小时20分
*   得分 40分
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int n, m;
const int N = 105, M = 105;
map<string, string> mp;

//转义1
string trans1(string str)
{
    int pos = str.find("\\\\");
    if (pos == -1)
        return str;
    string s1, s2;

    s1 = str.substr(0, pos) + "\\";
    s2 = pos + 2 >= str.length() ? "" : trans1(str.substr(pos + 2));
    return s1 + s2;
}
//转义2
string trans2(string str)
{
    int pos = str.find("\\\"");
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

//取出引号内的内容
string pick(string str)
{
    string res;
    int pos1, pos2;
    pos1 = str.find_first_of('\"');
    pos2 = str.find_last_of('\"');
    res = str.substr(pos1 + 1, pos2 - pos1 - 1);
    return res;
}

//从引号中取出，并且转义
string transform(string str)
{
    return trans(pick(str));
}

//拆分
vector<string> splitAt(string str, char sign)
{
    vector<string> res;
    str.push_back(sign); //尾部加上分隔符
    int pos;
    while ((pos = str.find_first_of(sign)) != string::npos)
    {
        res.push_back(str.substr(0, pos));
        str = str.substr(pos + 1);
    }
    return res;
}

int main()
{
    vector<string> res;
    string str;
    cin >> n >> m;
    getchar();
    for (int i = 0; i < n; i++)
    {
        string tmp;
        getline(cin, tmp);
        str += tmp;
    }
    res = splitAt(str, ',');
    for (vector<string>::iterator it = res.begin(); it != res.end(); it++)
    {
        vector<string> item = splitAt(*it, ':');
        string key = transform(item[0]);
        string value = transform(item[1]);
        mp[key] = value;
    }
    for (int i = 0; i < m; i++)
    {
        string tmp;
        getline(cin, tmp);
        if (mp[tmp] == "")
        {
            cout << "NOTEXIST" << endl;
        }
        else
        {
            cout << "STRING " << mp[tmp] << endl;
        }
    }
    return 0;
}

/*
10 5
{
"firstName": "John",
"lastName": "Smith",
"address": {
"streetAddress": "2ndStreet",
"city": "NewYork",
"state": "NY"
},
"esc\\aped": "\"hello\""
}
firstName
address
address.city
address.postal
esc\aped

*/