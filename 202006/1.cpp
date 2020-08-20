/* 
*   用时 48min
*   得分 100
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int M = 25, N = 1005;
int m, n;
struct P
{
    int x;
    int y;
    char type;
};
P points[N];

int t1, t2, t3;

bool isTogether(int t1, int t2, int t3, P *pA, P *pB)
{
    int xA = pA->x;
    int yA = pA->y;
    int xB = pB->x;
    int yB = pB->y;
    if ((t1 + t2 * xA + t3 * yA > 0) && (t1 + t2 * xB + t3 * yB > 0))
    {
        return true;
    }
    if ((t1 + t2 * xA + t3 * yA < 0) && (t1 + t2 * xB + t3 * yB < 0))
    {
        return true;
    }
    return false;
}

bool cmp(P a, P b)
{
    return a.type == 'A' && b.type == 'B';
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %c", &(points[i].x), &(points[i].y), &(points[i].type));
    }
    sort(points, points + n, cmp);
    int indexB;
    for (indexB = 0; indexB < n; indexB++)
    {
        if (points[indexB].type == 'B')
            break;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &t1, &t2, &t3);
        bool flag = true;
        int j;
        for (j = 0; j < indexB; j++)
        {
            flag = true;
            for (int k = indexB; k < n; k++)
            {
                if (isTogether(t1, t2, t3, &points[j], &points[k]))
                {
                    printf("No\n");
                    flag = false;
                    break;
                }
            }
            if (flag == false)
            {
                break;
            }
        }
        if (j == indexB)
        {
            printf("Yes\n");
        }
    }
    return 0;
}