/* 耗时 48min，得分100 */
/*
* 思路：
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, m;
const int N = 105;
const int M = 105;
string buf; //输入串

struct RULE
{
    string url;           //链接
    vector<string> paras; //拆分后的链接
    string name;          //名称
};

vector<RULE> rules;  //规则池
vector<string> srcs; //源参数池
vector<string> res;  //结果
size_t pos1, pos2;

bool isInt(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool isStr(string str)
{
    if (isInt(str))
        return false;
    if (str.find('/') != string::npos)
        return false;
    else
        return true;
}

void check(void)
{
    vector<RULE>::iterator it;
    //遍历每个规则
    for (it = rules.begin(); it != rules.end(); it++)
    {
        res.clear();
        bool flag = true;
        //参数数目不匹配直接尝试下一个规则
        if (srcs.size() != (it->paras).size())
            continue;
        //迭代比较每个斜杠之间的内容
        vector<string>::iterator it1, it2;
        it2 = (it->paras).begin();
        for (it1 = srcs.begin(); it1 != srcs.end(); it1++)
        {
            if (it2 == (it->paras).end())
                break;
            /*下面才是比较*/
            if ((*it2) == (*it1))
            {
            }
            else if ((*it2) == "<int>")
            {
                if (!isInt(*it1))
                    flag = false;
                else
                    res.push_back(*it1);
            }
            else if ((*it2) == "<string>")
            {
                if (!isStr(*it1))
                    flag = false;
                else
                    res.push_back(*it1);
            }
            else if ((*it2) == "<path>")
            {
                if (isStr(*it1))
                    flag = false;
                else
                    res.push_back(*it1);
            }
            else
            {
                flag = false;
            }
            /*上面才是比较*/
            it2++;
        }
        if (flag)
        {
            cout << it->name;
            for (it1 = res.begin(); it1 != res.end(); it1++)
            {
                cout << " " << *it1;
            }
            cout << endl;
            break;
        }
    }
    if (it == rules.end())
        cout << "404" << endl;
}

int main()
{
    size_t pos1;
    scanf("%d %d", &n, &m);
    int c = getchar();
    //拆分规则为url+name
    for (int i = 0; i < n; i++)
    {
        getline(cin, buf);
        pos1 = buf.find(' ');
        RULE tmpRule; //临时变量
        tmpRule.url = buf.substr(0, pos1);
        tmpRule.name = buf.substr(pos1 + 1);
        //没有斜杠就补一个
        if (tmpRule.url[tmpRule.url.length() - 1] != '/')
        {
            tmpRule.url += "/";
        }
        //拆分url
        pos1 = pos2 = 0;
        while ((pos1 = tmpRule.url.find('/', pos1)) != string::npos)
        {
            if ((pos2 = tmpRule.url.find('/', pos1 + 1)) == string::npos)
                break;
            string elem = tmpRule.url.substr(pos1 + 1, pos2 - pos1 - 1);
            tmpRule.paras.push_back(elem);
            pos1++;
        }
        rules.push_back(tmpRule);
    }
    for (int i = 0; i < m; i++)
    {
        srcs.clear();
        getline(cin, buf);
        //没有斜杠就补一个
        if (buf[buf.length() - 1] != '/')
        {
            buf += "/";
        }
        //拆分url
        pos1 = pos2 = 0;
        while ((pos1 = buf.find('/', pos1)) != string::npos)
        {
            if ((pos2 = buf.find('/', pos1 + 1)) == string::npos)
                break;
            string elem = buf.substr(pos1 + 1, pos2 - pos1 - 1);
            srcs.push_back(elem);
            pos1++;
        }
        check();
    }

    // for (vector<RULE>::iterator it = rules.begin(); it != rules.end(); it++)
    // {
    //     cout << it->name << " " << it->url << endl;
    //     for (vector<string>::iterator it2 = (it->paras).begin(); it2 != (it->paras).end(); it2++)
    //     {
    //         cout << *it2 << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}