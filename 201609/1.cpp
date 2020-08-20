/* 
*   用时 16分
*   得分 100分
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;
int n;
int sub[N - 1];

int main()
{
    scanf("%d", &n);
    int last, current;
    scanf("%d", &last);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &current);
        sub[i - 1] = abs(current - last);
        last = current;
    }
    int *max_ptr = max_element(sub, sub + n - 1);
    printf("%d\n", *max_ptr);
    return 0;
}