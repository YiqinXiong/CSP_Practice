/* 耗时  min，得分 */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int n;
const int N = 305;
const int MaxPrice = 305; //理论最大100 * 3 + 5
int day1[N];
int day2[N];
int i, j, k;

bool solve(int index, int n)
{
    // if (index == n)
    // {
    //     if (((day1[0] + day1[1]) / 2) != day2[0])
    //     {
    //         return false;
    //     }
    //     for (int j = 1; j < n - 1; j++)
    //     {
    //         if (((day1[j - 1] + day1[j] + day1[j + 1]) / 3) != day2[j])
    //         {
    //             return false;
    //         }
    //     }
    //     if (((day1[n - 2] + day1[n - 1]) / 2) != day2[1])
    //     {
    //         return false;
    //     }
    //     return true;
    // }
    for (int i = 1; i <= MaxPrice; i++)
    {
        day1[index] = i;
        if (index == 1)
        {
            if (((day1[index - 1] + day1[index]) / 2) != day2[index - 1])
            {
                continue;
            }
        }
        if (index > 1 && index < n - 1)
        {
            if (((day1[index - 2] + day1[index - 1] + day1[index]) / 3) != day2[index - 1])
            {
                continue;
            }
        }
        if (index == n - 1)
        {
            if (((day1[index - 2] + day1[index - 1] + day1[index]) / 3) == day2[index - 1])
            {
                if (((day1[index - 1] + day1[index]) / 2) == day2[index])
                {
                    return true;
                }
            }
            continue;
        }
        if (solve(index + 1, n))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", day2 + i);
    }
    if (solve(0, n))
    {

        for (int i = 0; i < n - 1; i++)
        {
            printf("%d ", day1[i]);
        }
        printf("%d\n", day1[n - 1]);
    }
    else
    {
        printf("not found\n");
    }

    return 0;
}