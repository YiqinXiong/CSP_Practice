/* 
*   用时 48min
*   得分 100
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct atom
{
    int index;
    long long value;
};

long long result;

const int N = 1000000005, A = 500005, B = 500005;
int n, a, b;
atom vA[A];
atom vB[B];

bool cmp(atom a, atom b)
{
    return a.index < b.index;
}

int main()
{
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < a; i++)
    {
        scanf("%d %lld", &(vA[i].index), &(vA[i].value));
    }
    sort(vA, vA + a, cmp);
    // printf("finish vA\n");
    for (int i = 0; i < b; i++)
    {
        scanf("%d %lld", &(vB[i].index), &(vB[i].value));
    }
    sort(vB, vB + b, cmp);
    // printf("finish vB\n");
    int ia = 0, ib = 0;
    while (ia < a && ib < b)
    {
        if (vA[ia].index == vB[ib].index)
        {
            result += vA[ia].value * vB[ib].value;
            // printf("res = %lld\n", result);
            ia++;
            ib++;
        }
        else if (vA[ia].index < vB[ib].index)
        {
            // printf("ia++ %d->%d\n", ia, ia + 1);
            ia++;
        }
        else
        {
            // printf("ia++ %d->%d\n", ib, ib + 1);
            ib++;
        }
        // printf("ia=%d,ib=%d,res=%lld\n", ia, ib, result);
    }
    printf("%lld\n", result);
    return 0;
}

// 10 3 4
// 4 5
// 7 -3
// 10 1
// 1 10
// 4 20
// 5 30
// 7 40