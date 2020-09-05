/*
*   ��ʱ 1Сʱ11��->1Сʱ48��
*   �÷� 90->100��
*   90��ԭ�򣬵�105��j+1>oneLine.size()��>Ҫ��Ϊ>=
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;

map<string,int> formatMap;

bool testStr(string str){
    //�ɼ��š�Сд��ĸ���������
    for(int i=0;i<str.length();i++){
        if(str[i]!='-'){
            if(str[i]<'a'||str[i]>'z'){
                if(str[i]<'0'||str[i]>'9'){
                    return false;
                }
            }
        }
    }
    return true;
}

void printAnsMap(map<string,string>& ansMap)
{
    map<string,string>::iterator it;
    for(it=ansMap.begin(); it!=ansMap.end(); it++)
    {
        cout << " " << it->first;
        if(it->second!="" && it->second!="hello"){
            cout << " " << it->second;
        }
    }
}

void printFormatMap()
{
    map<string,int>::iterator it;
    for(it=formatMap.begin(); it!=formatMap.end(); it++)
    {
        cout << it->first << "," << it->second <<endl;
    }
}

void fillFormatMap(string str)
{
    int len = str.length();
    for(int i=0; i<len; i++)
    {
        if(str[i]==':')
        {
            continue;
        }
        string temp = "-";
        temp.append(1, str[i]);
        if(i+1<len&&str[i+1]==':')
        {
            formatMap[temp]=111;    //�в���111
        }
        else
        {
            formatMap[temp]=222;    //�޲���222
        }
    }
}

int main()
{
    string str;
    cin >> str;
    fillFormatMap(str);
    //printFormatMap();
    cin >> N;
    getchar();
    string cmdLine;
    for(int i=0; i<N; i++)
    {
        getline(cin,cmdLine);
        stringstream ss(cmdLine);
        string elem;
        //���Ե�һ���ַ���
        getline(ss,elem,' ');
        vector<string> oneLine;
        map<string,string> ansMap;
        while(getline(ss,elem,' '))
        {
            oneLine.push_back(elem);
        }
        cout << "Case " << i+1 << ":";
        //����������
        for(int j=0;j<oneLine.size();j++){
            string s = oneLine[j];
            if(formatMap[s]==111){
                if(j+1>=oneLine.size()){
                    break;
                }
                if(!testStr(oneLine[j+1])){
                    break;
                }
                ansMap[s] = oneLine[j+1];
                j++;
            }else if(formatMap[s]==222){
                ansMap[s]="hello";
            }else{
                break;
            }
        }
        //���
        printAnsMap(ansMap);
        cout << endl;
    }
    return 0;
}
