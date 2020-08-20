/* 用时15min， 得分100 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int n;
const int N = 1005;
int arr[N];

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n, cmp);
    int minN = INT32_MAX;
    int tmp;
    for (int i = 0; i < n - 1; i++)
    {
        tmp = arr[i + 1] - arr[i];
        if (tmp < minN)
        {
            minN = tmp;
        }
    }
    printf("%d\n",minN);
    return 0;
}