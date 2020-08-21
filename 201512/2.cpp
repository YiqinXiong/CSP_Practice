/* 
*   用时 8分
*   得分 100分
*/

#include <stdio.h>
#include <iostream>

using namespace std;

const int N = 35, M = 35;
int map[N][M];
int mask[N][M];
int n, m;

void printMap()
{
    cout << "MAP:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void printMask()
{
    cout << "MASK:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mask[i][j] << " ";
        }
        cout << endl;
    }
}

void solve()
{
    //初始化mask，mask用来记录将要消去的棋子
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mask[n][m] = 0;
        }
    }
    int lastColor;
    int sameCount;
    //行遍历map，得到横向可消除的
    for (int i = 0; i < n; i++)
    {
        lastColor = -1;
        sameCount = 0;
        for (int j = 0; j < m; j++)
        {
            //颜色相同
            if (lastColor == map[i][j])
            {
                sameCount++;
            }
            //颜色不同
            else
            {
                //有超过连续3个的，则mask中记录消除位置
                if (sameCount >= 2)
                {
                    for (int k = 0; k <= sameCount; k++)
                    {
                        mask[i][j - 1 - k]++;
                    }
                }
                sameCount = 0;
            }
            lastColor = map[i][j];
        }
        //有超过连续3个的，则mask中记录消除位置
        if (sameCount >= 2)
        {
            for (int k = 0; k <= sameCount; k++)
            {
                mask[i][m - 1 - k]++;
            }
        }
    }
    //列遍历map，得到横向可消除的
    for (int j = 0; j < m; j++)
    {
        lastColor = -1;
        sameCount = 0;
        for (int i = 0; i < n; i++)
        {
            //颜色相同
            if (lastColor == map[i][j])
            {
                sameCount++;
            }
            //颜色不同
            else
            {
                //有超过连续3个的，则mask中记录消除位置
                if (sameCount >= 2)
                {
                    for (int k = 0; k <= sameCount; k++)
                    {
                        mask[i - 1 - k][j]++;
                    }
                }
                sameCount = 0;
            }
            lastColor = map[i][j];
        }
        if (sameCount >= 2)
        {
            for (int k = 0; k <= sameCount; k++)
            {
                mask[n - 1 - k][j]++;
            }
        }
    }
    //mask中大于0的位置就是要消除的位置，消除并输出结果
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mask[i][j] > 0)
                cout << 0 << " ";
            else
                cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    solve();
    return 0;
}