/* 耗时 10min，得分100 */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

const int N = 35;
int bonus;
int judge;
int score;

int main()
{
    bonus = 1;
    score = 0;
    while (true)
    {
        scanf("%d", &judge);
        if (judge == 1)
        {
            bonus = 1;
            score += bonus;
        }
        else if (judge == 2)
        {
            if (bonus == 1)
                bonus = 2;
            else
                bonus += 2;
            score += bonus;
        }
        else
            break;
    }
    printf("%d\n",score);
    return 0;
}