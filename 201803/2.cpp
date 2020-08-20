/* 耗时 48min，得分100 */
/*
* 思路：(1)小球互相碰撞可以看作穿透过去;(2)小球碰撞不会改变最终顺序，最终从左到右还是依次为1、2、3...号小球
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n; //小球个数
const int N = 105;
int t; //经过秒数
const int T = 105;
int L; //轨道长度
const int LMAX = 1005;

struct BALL
{
    int pos;  //位置
    bool dir; //方向（true右，false左)
    int seq;  //序号
};

BALL a[N];        //小球位置和方向
int sort_list[N]; //记录位置顺序和小球顺序的映射关联

bool cmp1(BALL a, BALL b)
{
    return a.pos < b.pos;
}
bool cmp2(BALL a, BALL b)
{
    return a.seq < b.seq;
}

int main()
{
    int tmpInt;
    scanf("%d %d %d", &n, &L, &t);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmpInt);
        a[i].pos = tmpInt;
        a[i].dir = true; //初始向右
        a[i].seq = i;
    }
    sort(a, a + n, cmp1); //按位置从左到右排序
    for (int i = 0; i < n; i++)
    {
        sort_list[i] = a[i].seq;
    }

    //对秒数循环
    for (int i = 0; i < t; i++)
    {
        //对小球循环
        for (int j = 0; j < n; j++)
        {
            //处理触碰边界的情况
            if ((a[j].pos == L && a[j].dir) || (a[j].pos == 0 && !(a[j].dir)))
            {
                a[j].dir = !(a[j].dir); //反向
            }
            //小球互相碰撞可以看作穿透过去
            if (a[j].dir)
            {
                a[j].pos++;
            }
            else
            {
                a[j].pos--;
            }
        }
    }
    sort(a, a + n, cmp1); //按位置从左到右排序
    for (int i = 0; i < n; i++)
    {
        a[i].seq = sort_list[i];
    }
    sort(a, a + n, cmp2); //按原seq排序
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", a[i].pos);
    }
    printf("%d\n", a[n - 1].pos);
    return 0;
}