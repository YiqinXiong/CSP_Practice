/* 用时 44 min */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int n;
const int N = 1010;
const int M = 1010;
int sum[N];                //初始总数
int mi[N];                 //每棵树的操作次数
int option[N][M];          //1为初始苹果数，2到mi为操作
bool is_drop[N] = {false}; //判断是否掉落
int end_sum;               //最后剩余果数
int drop_sum;              //发生掉落的果数
int triple_drop_sum;       //连续3棵树掉落的组数

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &mi[i]);
        for (int j = 1; j <= mi[i]; j++)
        {
            scanf("%d", &option[i][j]);
        }
        sum[i] = option[i][1];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= mi[i]; j++)
        {
            //检查
            if (option[i][j] > 0)
            {
                if (sum[i] != option[i][j])
                    is_drop[i] = true;
                sum[i] = option[i][j];
            }
            //疏果
            else
            {
                sum[i] += option[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        end_sum += sum[i + 1];
        if (is_drop[i + 1])
            drop_sum++;
        if (is_drop[(i % n) + 1] && is_drop[((i + 1) % n) + 1] && is_drop[((i + 2) % n) + 1])
            triple_drop_sum++;
    }
    printf("%d %d %d\n", end_sum, drop_sum, triple_drop_sum);
    return 0;
}