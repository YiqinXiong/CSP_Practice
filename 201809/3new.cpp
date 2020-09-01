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

//递归查找前代有没有符合条件的查询
bool findFather(string &req, int &lineno)
{
    // cout << "findFather("
    //      << req << ", "
    //      << lineno << ")";
    //i表示当前行号
    //先记录当前层号
    int lev = docFile[lineno].level;
    //向前遍历，找到父亲
    for (; lineno >= 0; lineno--)
    {
        //找到了父亲
        if (docFile[lineno].level < lev)
        {
            if (docFile[lineno].label == req || docFile[lineno].id == req)
            {
                // cout << " return true" << endl;
                return true;
            }
            else
            {
                // cout << " return findFather(" << req << ", " << lineno << ")" << endl;
                return findFather(req, lineno);
            }
        }
    }
    //没找到父亲
    // cout << " return false" << endl;
    return false;
}

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

        if (req.size() >= 2)
        {
            //多级查询
            for (int j = 0; j < n; j++)
            {
                int lastReqIdx = req.size() - 1;
                //先找到满足最后一个查询条件的行
                if (docFile[j].label == req[lastReqIdx] || docFile[j].id == req[lastReqIdx])
                {
                    // cout << "满足条件的行是：[" << j + 1 << "] " << endl;
                    int lineno = j;
                    //逐个向前匹配查询条件
                    for (lastReqIdx = lastReqIdx - 1; lastReqIdx >= 0; lastReqIdx--)
                    {
                        if (!findFather(req[lastReqIdx], lineno))
                        {
                            break;
                        }
                    }
                    if (lastReqIdx < 0)
                    {
                        ans.push_back(j + 1);
                    }
                }
            }
        }
        else
        {
            //单个查询
            for (int j = 0; j < n; j++)
            {
                int lastReqIdx = req.size() - 1;
                if (docFile[j].label == req[lastReqIdx] || docFile[j].id == req[lastReqIdx])
                {
                    ans.push_back(j + 1);
                }
            }
        }
        // sort(ans.begin(), ans.end());   //本身按顺序，不用排序
        cout << ans.size();
        for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
        {
            cout << " " << *it;
        }
        cout << endl;
    }
    return 0;
}
