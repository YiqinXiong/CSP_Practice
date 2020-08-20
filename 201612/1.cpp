/* 
*   用时 21分
*   得分 100分
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;
int n;
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    int last = -1000;
    int lessCount, greatCount;
    int i, j;
    for (i = 0; i < n; i++)
    {

        if (last == a[i])
        {
            continue;
        }
        lessCount = i;
        int j;
        for (j = i; j < n; j++)
        {
            if (a[j] > a[i])
                break;
        }
        greatCount = n - j;
        if (lessCount == greatCount)
        {
            printf("%d\n", a[i]);
            break;
        }
        // 漏掉这条语句只有70分，忘了要更新last的值
        last = a[i];
    }
    if (i == n)
    {
        printf("%d\n", -1);
    }
    return 0;
}