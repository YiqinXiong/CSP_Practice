/* 
*   用时 28分
*   得分 100分
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
const int N = 1005;
const int K = 10005;

int main()
{
    int count = 0;
    int temp = 0;
    scanf("%d %d", &n, &k);
    int limit = k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        limit -= temp;
        if (limit <= 0)
        {
            count++;
            limit = k;
        }
        else if (i == n - 1)
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}