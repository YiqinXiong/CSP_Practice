/*
*   用时 1小时5分
*   得分 90分->100分
*   思路 使用stringsream配合getline拆分路径
*   90分原因：cin >> string当string为空串时会一直等待输入，应该使用getline读取
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int P;  //输入目录个数
string curDir;  //当前目录

//打印标准化路径
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

//处理路径字符串
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

//把当前路径压入path
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
    //路径为空字符串，则正规化结果是当前目录
    if(dir.empty())
    {
        gotoCurDir(path);
    }
    else
    {
        //绝对路径
        if(dir[0]=='/')
        {
            handlePathStr(path, dir);
        }
        //相对路径
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
