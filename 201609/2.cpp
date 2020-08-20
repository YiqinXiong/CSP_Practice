/* 
*   用时 35分
*   得分 100分
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105;
const int SEAT_NUM = 100;
const int ROW = 20;
int n;
bool carrige[SEAT_NUM];
int leftSeats[ROW];

void printLeftSeats()
{
    for (int i = 0; i < ROW; i++)
    {
        printf("[%2d] ", leftSeats[i]);
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", carrige[5 * i + j] ? 'O' : 'X');
        }
        printf("\n");
    }
}

void buyTicket(int buyNum)
{
    int i;
    for (i = 0; i < ROW; i++)
    {
        // 一行坐的下
        if (leftSeats[i] >= buyNum)
        {
            // 起始售票位置
            int begin = i * 5 + (5 - leftSeats[i]);
            // 售票
            for (int j = 0; j < buyNum; j++)
            {
                carrige[begin + j] = true;
                printf("%d ", begin + j + 1);
            }
            printf("\n");
            // 更新该行剩余座位数
            leftSeats[i] -= buyNum;
            // printLeftSeats();
            break;
        }
    }
    // 一行坐不下
    if (i == ROW)
    {
        int sellCount = 0;
        for (int i = 0; i < SEAT_NUM; i++)
        {
            // 找到空座位就售票
            if (carrige[i] == false)
            {
                carrige[i] = true;
                printf("%d ", i + 1);
                sellCount++;
                if (sellCount == buyNum)
                {
                    break;
                }
                // 更新剩余座位数
                leftSeats[i / 5]--;
            }
        }
        printf("\n");
        // printLeftSeats();
    }
}

int main()
{
    fill(begin(carrige), end(carrige), false);
    fill(begin(leftSeats), end(leftSeats), 5);
    // printLeftSeats();
    scanf("%d", &n);
    int buyNum;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &buyNum);
        buyTicket(buyNum);
    }
    return 0;
}