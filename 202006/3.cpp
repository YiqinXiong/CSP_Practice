#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int w;

vector<vector<string>> segs;

int virtualPrint()
{
    vector<string> newSegs;
    for (int i = 0; i < segs.size(); i++)
    {
        vector<string> &seg = segs[i];
        //把多行的seg变为一行的seg
        string segText = seg[0];
        for (int j = 1; j < seg.size(); j++)
        {
            segText += " ";
            segText += seg[j];
        }
        newSegs.push_back(segText);
    }
    //开始打印
    int row = 1, col = 0;
    for (int i = 0; i < newSegs.size(); i++)
    {
        string line = newSegs[i];
        for (int j = 0; j < line.length(); j++)
        {
            if (col == w)
            {
                //略过行首的空白
                if (line[j] == ' ')
                    continue;
                else
                {
                    // cout << endl;
                    row++;
                    col = 0;
                }
            }
            // cout << line[j];
            col++;
        }
        if (i != segs.size() - 1)
        {
            // cout << endl
            //      << endl;
            row += 2;
            col = 0;
        }
    }
    return row;
}

void strip(string &line)
{
    int pos = 0;
    for (; pos < line.length(); pos++)
    {
        if (line[pos] != ' ')
        {
            break;
        }
    }
    line = line.substr(pos);
    for (pos = line.length() - 1; pos >= 0; pos--)
    {
        if (line[pos] != ' ')
        {
            break;
        }
    }
    line = line.substr(0, pos + 1);
}

int main()
{
    cin >> w;
    getchar();
    string line;
    bool inOneSeg = true;
    vector<string> seg;
    while (getline(cin, line))
    {
        strip(line); //去掉前后空格
        //跳过空行
        if (line.empty())
        {
            inOneSeg = false;
            continue;
        }
        if (inOneSeg)
        {
            seg.push_back(line);
        }
        else
        {
            segs.push_back(seg); //保存上一个seg
            inOneSeg = true;
            seg.clear(); //开始当前的seg
            seg.push_back(line);
        }
    }
    segs.push_back(seg); //保存上一个seg
    int ans = virtualPrint();
    cout << ans << endl;
    return 0;
}

/*
CSP

CSP is
a real realrealrealrealreal 
     competition.

   
come   and   join   us   


*/