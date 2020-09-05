/* 
*   用时 29分
*   得分 100分
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
    int x, y;
    node(int x, int y) : x(x), y(y) {}
};

const int N = 1005, H = 10005;
int n, h;
int height[N];
int canvas[N][H];
vector<node> nodes;

//计算面积
int countAreaSize(int i, int j)
{
    int xs, ys, xl, yl;
    xs = nodes[i].x;
    xl = nodes[j].x;
    ys = nodes[i].y;
    yl = nodes[j].y;
    if (nodes[i].x > nodes[j].x)
    {
        xs = nodes[j].x;
        xl = nodes[i].x;
    }
    if (nodes[i].y > nodes[j].y)
    {
        ys = nodes[j].y;
        yl = nodes[i].y;
    }
    for (int x = xs; x <= xl; x++)
    {
        for (int y = ys; y <= yl; y++)
        {
            if (!canvas[x][y])
            {
                return -1;
            }
        }
    }
    return (xl - xs + 1) * (yl - ys + 1);
}

void solve()
{
    int ans = 0;
    for (int i = 0; i < nodes.size(); i++)
    {
        for (int j = i; j < nodes.size(); j++)
        {
            int areaSize = countAreaSize(i, j);
            //ans是最大面积
            if (areaSize > ans)
            {
                ans = areaSize;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tempH;
        cin >> tempH;
        height[i] = tempH;
        //记录canvas的涂色部分
        for (int j = 0; j < tempH; j++)
        {
            canvas[i][j] = 1;
            nodes.push_back(node(i, j));
        }
        //h是height中的最大值
        if (tempH > h)
        {
            h = tempH;
        }
    }
    solve();
    return 0;
}