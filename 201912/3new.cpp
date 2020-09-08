/*
*   时间：2h24min=144min
*   得分：50
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

struct termItem
{
    string elem;
    int num;
};

struct formulaItem
{
    vector<termItem> term;
    int num;
};

struct exprItem
{
    int num;
    vector<formulaItem> formula;
};

typedef map<string, int> mymap;
mymap leftMap, rightMap;

bool cmpLeftAndRight()
{
    if (leftMap.size() != rightMap.size())
    {
        return false;
    }
    mymap::iterator itl = leftMap.begin();
    for (; itl != leftMap.end(); itl++)
    {
        mymap::iterator itr;
        if ((itr = rightMap.find(itl->first)) == rightMap.end())
        {
            return false;
        }
        if(itl->second!=itr->second){
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        leftMap.clear();
        rightMap.clear();
        string equ, left, right;
        cin >> equ;
        //拆分左右表达式
        int pos = equ.find('=');
        left = equ.substr(0, pos);
        right = equ.substr(pos + 1);
        //处理左表达式
        handleExpr(left);
        //处理右表达式
        handleExpr(right);
        //比较左右
    }
    return 0;
}