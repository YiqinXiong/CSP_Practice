/* 
*   用时 42分
*   得分 100分
*/
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct node
{
    int type;        //0为目录，1为文件
    string name;     //名字
    string path;     //绝对路径
    int father;      //父结点
    int son;         //第一个孩子结点
    int nextBrother; //下一个兄弟结点
};

node root[10];
int n;
string curDirPath;
int curDirIndex;

//通过name得到儿子结点的index
int findSonIndexByName(string name, int index)
{
    int sonIndex = root[index].son;
    while (sonIndex != -1)
    {
        if (root[sonIndex].name == name)
        {
            return sonIndex;
        }
        sonIndex = root[sonIndex].nextBrother;
    }
    return -1;
}

//处理两个分隔符/之间的部分
void handleItem(string item, int &index)
{
    //空串被忽略，目录不变
    if (item == "")
        return;
    //其他情况
    if (item == ".")
    {
        //当前目录
        return;
    }
    else if (item == "..")
    {
        //上级目录
        index = root[index].father;
    }
    else
    {
        //下级目录
        index = findSonIndexByName(item, index);
    }
}

//正规化路径
void formatPath(string path)
{
    //空串->当前目录
    if (path == "")
    {
        cout << curDirPath << endl;
        return;
    }
    //若末尾不为/，则添加一个/，便于分割
    if (path[path.length() - 1] != '/')
    {
        path.append(1, '/');
    }
    int index; //最终所指路径
    //绝对路径，从根目录开始
    if (path[0] == '/')
    {
        index = 0;
    }
    //相对路径，从当前目录开始
    else
    {
        index = curDirIndex;
    }
    //分割
    stringstream ss(path);
    string item;
    while (getline(ss, item, '/'))
    {
        handleItem(item, index);
    }
    if (index != -1)
    {
        cout << root[index].path << endl;
    }
    else
    {
        cout << "path error!" << endl;
    }
}

//找到当前目录的下标
int findIndexByPath(string path)
{
    for (int i = 0; i < 10; i++)
    {
        if (root[i].path == path)
        {
            return i;
        }
    }
}

//初始化目录结构
void initNode()
{
    //0
    root[0].type = 0;
    root[0].name = "/";
    root[0].path = "/";
    root[0].father = 0;
    root[0].son = 1;
    root[0].nextBrother = -1;
    //1
    root[1].type = 0;
    root[1].name = "d1";
    root[1].path = "/d1";
    root[1].father = 0;
    root[1].son = 2;
    root[1].nextBrother = 4;
    //2
    root[2].type = 1;
    root[2].name = "f1";
    root[2].path = "/d1/f1";
    root[2].father = 1;
    root[2].son = -1;
    root[2].nextBrother = 3;
    //3
    root[3].type = 1;
    root[3].name = "f2";
    root[3].path = "/d1/f2";
    root[3].father = 1;
    root[3].son = -1;
    root[3].nextBrother = -1;
    //4
    root[4].type = 0;
    root[4].name = "d2";
    root[4].path = "/d2";
    root[4].father = 0;
    root[4].son = 5;
    root[4].nextBrother = -1;
    //5
    root[5].type = 0;
    root[5].name = "d3";
    root[5].path = "/d2/d3";
    root[5].father = 4;
    root[5].son = 6;
    root[5].nextBrother = 7;
    //6
    root[6].type = 1;
    root[6].name = "f3";
    root[6].path = "/d2/d3/f3";
    root[6].father = 5;
    root[6].son = -1;
    root[6].nextBrother = -1;
    //7
    root[7].type = 0;
    root[7].name = "d4";
    root[7].path = "/d2/d4";
    root[7].father = 4;
    root[7].son = 8;
    root[7].nextBrother = 9;
    //8
    root[8].type = 1;
    root[8].name = "f1";
    root[8].path = "/d2/d4/f1";
    root[8].father = 7;
    root[8].son = -1;
    root[8].nextBrother = -1;
    //9
    root[9].type = 1;
    root[9].name = "f4";
    root[9].path = "/d2/f4";
    root[9].father = 4;
    root[9].son = -1;
    root[9].nextBrother = -1;
}

int main()
{
    initNode();
    cin >> n;
    cin >> curDirPath;
    curDirIndex = findIndexByPath(curDirPath);
    vector<string> lines;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        lines.push_back(line);
    }
    for (int i = 0; i < n; i++)
    {
        formatPath(lines[i]);
    }
    return 0;
}