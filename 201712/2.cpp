/* 用时15min， 得分100 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;
const int N = 1005, K = 9;
queue<int> boys;
int counter;

//报数为k的倍数或末位数为k则淘汰
bool out(int callNum)
{
    return (callNum % 10 == k) || (!(callNum % k));
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        boys.push(i);
    }
    counter = 1;
    while (boys.size() > 1)
    {
        if (out(counter))
        {
            boys.pop();
        }
        else
        {
            boys.push(boys.front());
            boys.pop();
        }
        counter++;
    }
    printf("%d\n", boys.front());
    return 0;
}