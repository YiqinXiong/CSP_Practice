#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
using namespace std;

const int N = 105;
int n;
vector<string> equs;

bool solve(string s)
{
    int equ_pos = s.find('=');
    if(equ_pos == -1) return false;
    string left = s.substr(0, equ_pos);
    string right = s.substr(equ_pos + 1, s.length() - equ_pos - 1);
    set<string> les1,les2, res1,res2;
    left.erase(remove(left.begin(), left.end(), '+'), left.end());     //删除left中所有+号
    right.erase(remove(right.begin(), right.end(), '+'), right.end()); //删除right中所有+号
    //左边
    for (int i = 0; i < left.length(); i++)
    {
        //是大写字母
        if (left[i] <= 'Z' && left[i] >= 'A')
        {
            //Aa型的元素
            if ((i + 1 < left.length()) && (left[i + 1] <= 'z' && left[i + 1] >= 'a'))
            {
                les2.insert(left.substr(i, 2));
                i++; //跳过那个小写字母
            }
            //A型的元素
            else
            {
                les1.insert(left.substr(i, 1));
            }
        }
    }
    //构建记录表
    map<string,int> lmap;
    for (set<string>::iterator it = les1.begin(); it != les1.end(); it++)
    {
        lmap[(*it)]=0;
    }
    for (set<string>::iterator it = les2.begin(); it != les2.end(); it++)
    {
        lmap[(*it)]=0;
    }
    //计数
    for (int i = 0; i < left.length(); i++)
    {
        //是大写字母
        if (left[i] <= 'Z' && left[i] >= 'A')
        {
            //Aa型的元素
            if ((i + 1 < left.length()) && (left[i + 1] <= 'z' && left[i + 1] >= 'a'))
            {
                string tmp = left.substr(i,2);
                lmap[(tmp)]++;
                i++; //跳过那个小写字母
            }
            //A型的元素
            else
            {
                string tmp = left.substr(i,1);
                lmap[(tmp)]++;
            }
        }
    }
    //右边
    for (int i = 0; i < right.length(); i++)
    {
        //是大写字母
        if (right[i] <= 'Z' && right[i] >= 'A')
        {
            //Aa型的元素
            if ((i + 1 < right.length()) && (right[i + 1] <= 'z' && right[i + 1] >= 'a'))
            {
                res2.insert(right.substr(i, 2));
                i++; //跳过那个小写字母
            }
            //A型的元素
            else
            {
                res1.insert(right.substr(i, 1));
            }
        }
    }
    //构建记录表
    map<string,int> rmap;
    for (set<string>::iterator it = res1.begin(); it != res1.end(); it++)
    {
        rmap[(*it)]=0;
    }
    for (set<string>::iterator it = res2.begin(); it != res2.end(); it++)
    {
        rmap[(*it)]=0;
    }
    //计数
    for (int i = 0; i < right.length(); i++)
    {
        //是大写字母
        if (right[i] <= 'Z' && right[i] >= 'A')
        {
            //Aa型的元素
            if ((i + 1 < right.length()) && (right[i + 1] <= 'z' && right[i + 1] >= 'a'))
            {
                string tmp = right.substr(i,2);
                rmap[(tmp)]++;
                i++; //跳过那个小写字母
            }
            //A型的元素
            else
            {
                string tmp = right.substr(i,1);
                rmap[(tmp)]++;
            }
        }
    }
    //比较
    for (set<string>::iterator it = les1.begin(); it != les1.end(); it++)
    {
        if(lmap[(*it)] != rmap[(*it)])
            return false;
    }
    for (set<string>::iterator it = les2.begin(); it != les2.end(); it++)
    {
        if(lmap[(*it)] != rmap[(*it)])
            return false;
    }
    return true;
}

int main()
{
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        equs.push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        if (solve(equs[i]))
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }
    return 0;
}