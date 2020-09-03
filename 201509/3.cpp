/*
*   ��ʱ 80��
*   �÷� 100��
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
    //1.�ҵ�һ�γ��ֵġ� }}����Ϊpos2����pos2�и�
    pos2 = str.find(" }}");
    //cout << "pos2:" <<pos2 <<endl;
    if(pos2==string::npos)
        return;
    string left = str.substr(pos2+3);
    str = str.substr(0,pos2);
    //2.��ǰ�벿�������һ�γ��ֵġ�{{ ����Ϊpos1������pos1��pos2ȷ��һ�����
    pos1 = str.find_last_of("{{ "); //ע��find_last_of���ص���"{{ "�����һ���ַ����±�
    //cout << "pos1:" <<pos1 <<endl;
    if(pos1==string::npos)
        return;
    //cout << pos1+offset << " " << pos2+offset << " " << str.substr(pos1+1) << endl;
    marks.push(mark(pos1+offset,pos2+offset,str.substr(pos1+1)));
    //3.�Ժ�벿���ظ�1��2
    replaceMod(left,marks,offset+pos2+3);
}

int main()
{
    //����
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
    //����
    for(int i=0; i<m; i++)
    {
        stack<mark> markInLine;
        string line = doc[i];
        //cout << "line: " << line <<endl;
        replaceMod(line,markInLine,0);
        //�滻
        while(!markInLine.empty())
        {
            mark mk = markInLine.top();
            markInLine.pop();
            line.replace(mk.pos1-2,mk.pos2-(mk.pos1-2)+3,kvMap[mk.vari]);
        }
        //��ӡ
        cout << line <<endl;
    }
    return 0;
}
