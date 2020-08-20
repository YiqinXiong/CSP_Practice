/* 
*   用时 42分
*   得分 100分
*/
#include <stdio.h>
#include <iostream>
using namespace std;

int map[4 + 15 + 1][10];
int mask[4 + 15 + 1][10];
int unit[4][4];
int beginCol;

void printMask()
{
    for (int i = 0; i < 4 + 15 + 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << mask[i][j] << " ";
        }
        cout << endl;
    }
}

void printMap()
{
    for (int i = 4; i < 4 + 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << map[i][j] + mask[i][j] << " ";
        }
        cout << endl;
    }
}

//如果冲突返回false，否则返回true
bool downStep()
{
    static int steps = 0;
    steps++;
    // cout << steps << endl;
    //备份mask
    int mask_bak[4 + 15 + 1][10];
    for (int i = 0; i < 4 + 15 + 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mask_bak[i][j] = mask[i][j];
        }
    }
    //图形下降
    for (int i = -1; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i + steps >= 0)
            {
                mask[i + steps][beginCol - 1 + j] =
                    i == -1 ? 0 : unit[i][j];
            }
        }
    }
    //判断是否冲突
    for (int i = 0; i < 4 + 15 + 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] && mask[i][j])
            {
                // cout << "回溯前mask" << endl;
                // printMask();
                //冲突了则回溯
                for (int i = 0; i < 4 + 15 + 1; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        mask[i][j] = mask_bak[i][j];
                    }
                }
                // cout << "回溯后mask" << endl;
                // printMask();
                return false;
            }
        }
    }
    return true;
}

int main()
{
    // 输入
    for (int i = 0; i < 4 + 15 + 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            //上面4行全0
            if (i < 4)
            {
                map[i][j] = 0;
            }
            else if (i < 4 + 15)
            {
                cin >> map[i][j];
            }
            //最后1行全1，作为底
            else
            {
                map[i][j] = 1;
            }
            mask[i][j] = 0;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> unit[i][j];
        }
    }
    cin >> beginCol;
    // cout << "打印初始map" << endl;
    // printMap();

    //向下移动
    while (downStep())
        ;
    //得出最后map
    // cout << "打印最终map" << endl;
    printMap();
    return 0;
}