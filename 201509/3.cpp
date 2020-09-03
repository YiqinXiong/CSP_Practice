/*
*   用时 80分
*   得分 100分
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>

using namespace std;

struct mark
{
    int pos1,pos2;
    string vari;
    mark(int p1,int p2,string v):pos1(p1),pos2(p2),vari(v) {}
};

map<string,string> kvMap;

void printKvMap()
{
    map<string,string>::iterator it;
    for(it=kvMap.begin(); it!=kvMap.end(); it++)
    {
        cout << it->first << ", " << it->second << endl;
    }
}

int m,n;

void replaceMod(string str, stack<mark>& marks,int offset)
{
    //cout << "call replaceMod..." << endl;
    int pos1, pos2;
    //1.找第一次出现的“ }}”记为pos2，以pos2切割
    pos2 = str.find(" }}");
    //cout << "pos2:" <<pos2 <<endl;
    if(pos2==string::npos)
        return;
    string left = str.substr(pos2+3);
    str = str.substr(0,pos2);
    //2.在前半部分找最后一次出现的“{{ ”记为pos1，根据pos1和pos2确定一个标记
    pos1 = str.find_last_of("{{ "); //注意find_last_of返回的是"{{ "中最后一个字符的下标
    //cout << "pos1:" <<pos1 <<endl;
    if(pos1==string::npos)
        return;
    //cout << pos1+offset << " " << pos2+offset << " " << str.substr(pos1+1) << endl;
    marks.push(mark(pos1+offset,pos2+offset,str.substr(pos1+1)));
    //3.对后半部分重复1和2
    replaceMod(left,marks,offset+pos2+3);
}

int main()
{
    //输入
    vector<string> doc;
    cin >> m >> n;
    getchar();
    for(int i=0; i<m; i++)
    {
        string line;
        getline(cin,line);
        doc.push_back(line);
    }
    for(int i=0; i<n; i++)
    {
        string line;
        getline(cin,line);
        int pos = line.find(' ');
        string key,value;
        key = line.substr(0,pos);
        line = line.substr(pos+2);
        pos = line.find('"');
        value = line.substr(0,pos);
        kvMap[key] = value;
    }
    //printKvMap();
    //处理
    for(int i=0; i<m; i++)
    {
        stack<mark> markInLine;
        string line = doc[i];
        //cout << "line: " << line <<endl;
        replaceMod(line,markInLine,0);
        //替换
        while(!markInLine.empty())
        {
            mark mk = markInLine.top();
            markInLine.pop();
            line.replace(mk.pos1-2,mk.pos2-(mk.pos1-2)+3,kvMap[mk.vari]);
        }
        //打印
        cout << line <<endl;
    }
    return 0;
}
