/* 
*   用时 32分
*   得分 100分
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
const int N = 1005;
const int M = 1005;
int pos[N]; //记录位置
int que[N]; //队列

void printList(void)
{
    for (int i = 1; i < n; i++)
    {
        printf("%d ", que[i]);
    }
    printf("%d\n", que[n]);
}

int main()
{
    int p, q; //学号为p，向后移动q（q可正可负）
    int new_pos;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= n; i++)
    {
        que[i] = i;
        pos[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        // printList();
        scanf("%d %d", &p, &q);
        new_pos = pos[p] + q;
        if (pos[p] <= new_pos)
        {
            //往前挪动
            for (int j = pos[p]; j < new_pos; j++)
            {
                que[j] = que[j + 1];
                pos[que[j + 1]]--;
            }
        }
        else
        {
            //往后挪动
            for (int j = pos[p]; j > new_pos; j--)
            {
                que[j] = que[j - 1];
                pos[que[j - 1]]++;
            }
        }
        //然后把p插入新位置
        que[new_pos] = p;
        //更新p的位置
        pos[p] = new_pos;
    }
    printList();
    return 0;
}