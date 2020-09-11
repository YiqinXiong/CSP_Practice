#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int n, m;

struct value
{
    // int lev;
    int type; //0为字符串，1为对象
    string str;
    map<string, value> obj;
    value() {}
};

typedef map<string, value> myMap;
myMap jsonMap;

//去除字符串首尾空格
void strip(string &str)
{
    int pos1, pos2;
    int len = str.length();
    if (len == 0)
    {
        return;
    }
    for (pos1 = 0; pos1 < len; pos1++)
    {
        if (str[pos1] != ' ')
        {
            break;
        }
    }
    for (pos2 = len - 1; pos2 >= 0; pos2--)
    {
        if (str[pos2] != ' ')
        {
            break;
        }
    }
    str = str.substr(pos1, pos2 + 1 - pos1);
}

//转义字符串
void trans(string &str)
{
    int pos = 0;
    while ((pos = str.find('\\', pos)) != string::npos)
    {
        if (str[pos + 1] == '"')
        {
            str.erase(pos, 1);
        }
        else if (str[pos + 1] == '\\')
        {
            str.erase(pos, 1);
            pos++;
        }
    }
}

//获取一个字符串
string getStr(string &json)
{
    int pos1, pos2;
    if ((pos1 = json.find('"')) == string::npos)
    {
        return "";
    }
    pos2 = json.find('"', pos1 + 1);
    while (json[pos2 - 1] == '\\')
    {
        pos2 = json.find('"', pos2 + 1);
    }
    string str = json.substr(pos1 + 1, pos2 - pos1 - 1);
    trans(str);
    json = json.substr(pos2 + 1);
    return str;
}

//找到匹配的后花括号
int findRBB(int lev, string &str, int begin)
{
    int l = lev;
    int i;
    for (i = begin; i < str.length(); i++)
    {
        if (str[i] == '{')
            l++;
        if (str[i] == '}')
        {
            if (l == lev)
                break;
            else
                l--;
        }
    }
    return i;
}

//返回处理完之后的字符串位置pos
int solve(int lev, string json, myMap &obj)
{
    int pos1 = json.find('{');
    int len = json.length();
    int pos2 = findRBB(lev, json, pos1 + 1);
    json = json.substr(pos1 + 1, pos2 - pos1 - 1);
    string key;
    while (!(key = getStr(json)).empty())
    {
        int pos1 = json.find('"');
        int pos2 = json.find('{');
        //字符串
        if (pos2 == string::npos || (pos1 != string::npos && pos1 < pos2))
        {
            value v = value();
            v.type = 0;
            v.str = getStr(json);
            obj.insert(make_pair(key, v));
        }
        //对象
        else
        {
            value v = value();
            v.type = 1;
            int pos = solve(lev + 1, json, v.obj);
            json = json.substr(pos + 1);
            obj.insert(make_pair(key, v));
        }
    }
    return pos2;
}

int main()
{
    string json = "";
    cin >> n >> m;
    getchar();
    //输入json文本，变为一行
    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        strip(line);
        json += line;
    }
    //处理json
    solve(0, json, jsonMap);
    //查询
    for (int i = 0; i < m; i++)
    {
        string req;
        cin >> req;
        stringstream ss(req);
        int lev;
        string name;
        value tempValue;
        tempValue.obj = jsonMap;
        bool exist = true;
        while (getline(ss, name, '.'))
        {
            auto it = tempValue.obj.find(name);
            if (it == tempValue.obj.end())
            {
                exist = false;
                cout << "NOTEXIST" << endl;
                break;
            }
            else
            {
                tempValue = it->second;
            }
        }
        if (exist)
        {
            if (tempValue.type == 0)
                cout << "STRING " << tempValue.str << endl;
            else
                cout << "OBJECT" << endl;
        }
    }
    // trans(json);
    // cout << json << endl;
    return 0;
}

/*
15 9
{
"firstName": "",
"lastName": "Smith",
"address": {
"streetAddress": "2ndStreet",
"city": "NewYork",
"state": "NY",
"lth":{
    "name":"lth",
    "lastname":"liu",
    "obj"   :    {}
}
},
"esc\\aped": "\"hello\""
}
firstName
address
address.city
address.postal
esc\aped
address.lth
address.lth.name
address.lth.lastname
address.lth.obj
*/