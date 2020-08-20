/* 用时 25 min */
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

int n, m;
const int N = 1005;
const int M = 1005;
int sum[N];
int option[N][M];
int t, k, p;
int min_value;
int min_index;
int end_sum;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", sum + i);
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &option[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        end_sum += sum[i];
        int delete_num = 0;
        for (int j = 1; j <= m; j++)
        {
            delete_num += option[i][j];
        }
        end_sum += delete_num;
        if (delete_num < min_value)
        {
            min_value = delete_num;
            min_index = i;
        }
    }
    t = end_sum;
    k = min_index;
    p = -min_value;
    printf("%d %d %d\n", t, k, p);
    return 0;
}
