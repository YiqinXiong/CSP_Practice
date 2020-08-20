/* 
*   用时 26分
*   得分 50分
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long ull;
int n;
const int N = 100005;
int m;
const int M = 100005;
int l, r;
ull v;
ull a[N];

int main()
{
    int i, j;
    int lead_num; //导引数
    unsigned int temp;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%u", &temp);
        a[i] = (ull)temp;
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &lead_num);
        if (lead_num == 1)
        {
            scanf("%d", &l);
            scanf("%d", &r);
            scanf("%u", &temp);
            v = (ull)temp;
            for (j = l; j <= r; j++)
            {
                if (!(a[j] % v))
                {
                    a[j] /= v;
                }
            }
        }
        else
        {
            scanf("%d", &l);
            scanf("%d", &r);
            ull sum = 0;
            for (j = l; j <= r; j++)
            {
                sum += a[j];
            }
            printf("%llu\n", sum);
        }
    }

    return 0;
}

// 5 3
// 1 2 3 4 5
// 2 1 5
// 1 1 3 2
// 2 1 5
