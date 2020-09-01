#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

const int N = 105, M = 15;
int n, m;

struct elem
{
    string label; //标签
    string id;    //id
    int level;    //root为0，逐层递增
};

elem docFile[N]; //输入的结构化文档

//查找前代有没有符合条件的查询

//转大写
void strToUpper(string &src)
{
    for (int i = 0; i < src.length(); i++)
    {
        src[i] = toupper(src[i]);
    }
}

//格式化文档的输入
void inputDocFile(string &elemLine, int i)
{
    int pos = 0, pos1 = -1, pos2 = -1; //pos1和pos2分别记录label和id字符串开始的位置
    //计算层级
    while (pos < elemLine.length() && elemLine[pos] == '.')
    {
        pos++;
    }
    docFile[i].level = pos;
    //记录label起始位置
    pos1 = pos;
    //记录id起始位置
    while (pos < elemLine.length() && elemLine[pos] != '#')
    {
        pos++;
    }
    if (pos >= elemLine.length())
    {
        //无id
        docFile[i].id = "";
        docFile[i].label = elemLine.substr(pos1);
    }
    else
    {
        //有id
        pos2 = pos;
        docFile[i].id = elemLine.substr(pos2);
        docFile[i].label = elemLine.substr(pos1, pos2 - pos1 - 1);
    }
    strToUpper(docFile[i].label);
}

int main()
{
    string elemLine;
    cin >> n >> m;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, elemLine);
        inputDocFile(elemLine, i);
        // cout << docFile[i].id << " "
        //      << docFile[i].label << " "
        //      << docFile[i].level << endl;
    }
    for (int i = 0; i < m; i++)
    {
        vector<string> req;
        vector<int> ans;
        //使用stringstream+getline分割reqLine字符串
        string reqLine;
        getline(cin, reqLine);
        stringstream ss(reqLine);
        string q;
        while (getline(ss, q, ' '))
        {
            if (q[0] != '#')
            {
                strToUpper(q);
            }
            req.push_back(q);
        }
        //查询
        int lastReqIdx = req.size() - 1;
        if (req.size() >= 2)
        {
            //多级查询
            // for ()
        }
        else
        {
            //单个查询
            for (int j = 0; j < n; j++)
            {
                if (docFile[j].label == req[lastReqIdx] || docFile[j].id == req[lastReqIdx])
                {
                    ans.push_back(j + 1);
                }
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size();
        for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
        {
            cout << " " << *it;
        }
        cout << endl;
    }
    return 0;
}
