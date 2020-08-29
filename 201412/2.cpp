/* 
*   用时 59分
*   得分 100分
*/
#include <stdio.h>
#include <iostream>

using namespace std;

const int N = 505;
int map[N][N];
int n;
int x, y;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    //初始位置
    x = y = 0;
    bool leftDown = false;
    while (x < n && y < n)
    {
        //输出
        cout << map[x][y] << " ";
        if (leftDown)
        {
            //左下移动
            y--;
            x++;
            //边界情况
            if (y < 0 || x > n - 1)
            {

                if (y < 0 && x > n - 1)
                {
                    //先复原再y++
                    y++;
                    x--;
                    y++;
                }
                else if (y < 0)
                    y++;
                else
                {
                    //先复原再y++
                    y++;
                    x--;
                    y++;
                }
                leftDown = !leftDown;
            }
        }
        else
        {
            //右上移动
            y++;
            x--;
            //边界情况
            if (x < 0 || y > n - 1)
            {
                if (x < 0 && y > n - 1)
                {
                    //先复原再x++
                    y--;
                    x++;
                    x++;
                }
                else if (x < 0)
                    x++;
                else
                {
                    //先复原再x++
                    y--;
                    x++;
                    x++;
                }
                leftDown = !leftDown;
            }
        }
    }
    cout << endl;
    return 0;
}