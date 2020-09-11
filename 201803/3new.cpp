/* 用时2小时，得分90 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

struct rule
{
    string name;
    vector<string> items;
    bool endSlash;
    rule(string &name, vector<string> &items, bool endSlash) : name(name), items(items), endSlash(endSlash) {}
};

vector<rule> rules;

//检查URL是否合法
bool checkURL(string &url)
{
    for (int i = 0; i < url.length(); i++)
    {
        char c = url[i];
        if (c != '/' && !isupper(c) && !islower(c) && !isdigit(c) && c != '-' && c != '_' && c != '.')
            return false;
    }
    return true;
}

//检查是否是数字串
bool isDigitStr(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

//子项匹配，str返回1，int返回2，path返回3，普通返回4，不匹配返回-1
int isMatch(string &rule, string &item)
{
    if (rule == "<str>")
    {
        return 1;
    }
    else if (rule == "<int>")
    {
        if (isDigitStr(item))
            return 2;
        else
            return -1;
    }
    else if (rule == "<path>")
    {
        return 3;
    }
    else
    {
        if (rule == item)
            return 4;
        else
            return -1;
    }
}

//匹配URL
void matchURL(vector<string> &vec, string &url)
{
    bool isMat = false;
    auto it = rules.begin();
    //遍历所有规则
    for (; it != rules.end(); it++)
    {
        vector<string> &ruleVec = it->items;
        if (ruleVec.size() > vec.size())
        {
            continue;
        }
        bool allMatch = true;
        vector<string> matchItems;
        for (int i = 0; i < ruleVec.size(); i++)
        {
            int matchResult;
            string matchItem = "";
            if ((matchResult = isMatch(ruleVec[i], vec[i])) == -1)
            {
                allMatch = false;
                break;
            }
            //根据匹配结果分开处理
            bool urlEndSlash = url[url.length() - 1] == '/';
            switch (matchResult)
            {
            case 1:
                //str
                matchItem = vec[i];
                if (i == ruleVec.size() - 1 && ((it->endSlash && (!urlEndSlash) || (!it->endSlash) && urlEndSlash) || ruleVec.size() < vec.size()))
                {
                    allMatch = false;
                }
                matchItems.push_back(matchItem);
                break;
            case 2:
                //int
                matchItem = to_string(stoi(vec[i]));
                if (i == ruleVec.size() - 1 && ((it->endSlash && (!urlEndSlash) || (!it->endSlash) && urlEndSlash) || ruleVec.size() < vec.size()))
                {
                    allMatch = false;
                }
                matchItems.push_back(matchItem);
                break;
            case 3:
                //path
                for (int j = i; j < vec.size(); j++)
                {
                    matchItem += vec[j];
                    matchItem.append(1, '/');
                }
                if (!urlEndSlash)
                {
                    matchItem = matchItem.substr(0, matchItem.length() - 1);
                }
                matchItems.push_back(matchItem);
                break;
            case 4:
                //普通
                if (i == ruleVec.size() - 1 && ((it->endSlash && (!urlEndSlash) || (!it->endSlash) && urlEndSlash) || ruleVec.size() < vec.size()))
                {
                    allMatch = false;
                }
                break;
            default:
                break;
            }
        }
        if (allMatch)
        {
            isMat = true;
            cout << it->name;
            for (int i = 0; i < matchItems.size(); i++)
            {
                cout << " " << matchItems[i];
            }
            cout << endl;
            break;
        }
    }
    if (!isMat)
    {
        cout << "404" << endl;
    }
}

//切割URL
void splitURL(string &str, vector<string> &vec)
{
    string item;
    stringstream ss(str);
    while (getline(ss, item, '/'))
    {
        if (item.length() == 0)
            continue;
        vec.push_back(item);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    //输入规则
    for (int i = 0; i < n; i++)
    {
        string ruleStr, ruleName;
        cin >> ruleStr >> ruleName;
        vector<string> vec;
        splitURL(ruleStr, vec);
        rules.push_back(rule(ruleName, vec, ruleStr[ruleStr.length() - 1] == '/'));
    }
    //处理URL
    for (int i = 0; i < m; i++)
    {
        string url;
        cin >> url;
        if (checkURL(url))
        {
            vector<string> vec;
            splitURL(url, vec);
            matchURL(vec, url);
        }
        else
        {
            cout << "404" << endl;
        }
    }
    return 0;
}

/*
1 1
/static/<path> static_serve
/static/js/jquery.js
*/