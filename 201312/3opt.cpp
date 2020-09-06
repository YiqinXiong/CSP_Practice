/* 
*   用时 21分
*   得分 100分
*   思路 优化版。按高度从高到低遍历，对当前遍历到的i，向左右扩展（i-1、i+1），遇到更低的高度或边界则结束
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    int h;
    int index;
    node(int h, int index) : h(h), index(index) {}
};

const int N = 1005, MAXH = 10005;
int n;
int height[N];
vector<node> nodes;

bool cmp(node &a, node &b)
{
    return a.h < b.h;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
        nodes.push_back(node(height[i], i));
    }
    int s = 0;
    sort(nodes.begin(), nodes.end(), cmp);
    while (!nodes.empty())
    {
        node &nd = nodes.back();
        nodes.pop_back();
        // cout << "nd.h: " << nd.h << " ";
        // cout << "nd.index: " << nd.index << endl;
        int ileft, iright;
        ileft = iright = nd.index;
        //左扩展
        while (ileft - 1 >= 0 && height[ileft - 1] >= nd.h)
        {
            ileft--;
        }
        //右扩展
        while (iright + 1 < n && height[iright + 1] >= nd.h)
        {
            iright++;
        }
        int sNew = (iright - ileft + 1) * nd.h;
        // cout << "ileft: " << ileft << " ";
        // cout << "iright: " << iright << " ";
        // cout << "sNew: " << sNew << endl;
        if (sNew > s)
        {
            s = sNew;
        }
    }
    cout << s << endl;
    return 0;
}