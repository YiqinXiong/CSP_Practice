/*
*   ��ʱ 1Сʱ5��
*   �÷� 90��->100��
*   ˼· ʹ��stringsream���getline���·��
*   90��ԭ��cin >> string��stringΪ�մ�ʱ��һֱ�ȴ����룬Ӧ��ʹ��getline��ȡ
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int P;  //����Ŀ¼����
string curDir;  //��ǰĿ¼

//��ӡ��׼��·��
void printPath(vector<string>& path)
{
    if(path.empty())
    {
        cout << "/" << endl;
        return;
    }
    for(int i=0; i<path.size(); i++)
    {
        cout << "/" << path[i];
    }
    cout << endl;
}

//����·���ַ���
void handlePathStr(vector<string>& path,string pathStr)
{
    stringstream ss(pathStr);
    string temp;
    while(getline(ss,temp,'/'))
    {
        if(temp.empty() || temp==".")
            continue;
        if(temp=="..")
        {
            if(!path.empty())
                path.pop_back();
        }
        else
        {
            path.push_back(temp);
        }
    }
}

//�ѵ�ǰ·��ѹ��path
void gotoCurDir(vector<string>& path)
{
    stringstream ss(curDir);
    string temp;
    while(getline(ss,temp,'/'))
    {
        if(temp.empty())
            continue;
        path.push_back(temp);
    }
}

void formatDir(string dir)
{
    vector<string> path;
    //·��Ϊ���ַ����������滯����ǵ�ǰĿ¼
    if(dir.empty())
    {
        gotoCurDir(path);
    }
    else
    {
        //����·��
        if(dir[0]=='/')
        {
            handlePathStr(path, dir);
        }
        //���·��
        else
        {
            gotoCurDir(path);
            handlePathStr(path, dir);
        }
    }
    printPath(path);
}

int main()
{

    cin >> P;
    cin >> curDir;
    string dir;
    vector<string> dirs;
    getchar();
    for(int i=0; i<P; i++)
    {
        getline(cin, dir);
        dirs.push_back(dir);
    }
    for(int i=0;i<P;i++){
        formatDir(dirs[i]);
    }
    return 0;
}
