/* 
*   用时 14分
*   得分 100分
*/
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 105;
int n;
int map[N][N];

int main()
{
    int ans = 0;
    cin >> n;
    //n个矩形
    for (int i = 0; i < n; i++)
    {
        //涂一个矩形的颜色
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++)
        {
            for (int y = y1; y < y2; y++)
            {
                map[x][y]++;
            }
        }
    }
    //计算涂上色的块数
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j])
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}