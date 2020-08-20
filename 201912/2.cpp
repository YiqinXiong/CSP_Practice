#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pos;

int n;
const int N = 1005;
pos xline[N];

bool sort_by_x(pos a, pos b)
{
    return a.first < b.first;
}

int main()
{
    int c0, c1, c2, c3, c4;
    c0 = c1 = c2 = c3 = c4 = 0;
    int count; //周围的垃圾数目
    int d;     //偏移量
    scanf("%d", &n);
    int tx, ty;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &tx, &ty);
        xline[i].first = tx;
        xline[i].second = ty;
    }
    sort(xline, xline + n, sort_by_x); //按x排序
    for (int i = 0; i < n; i++)
    {
        tx=xline[i].first;
        ty=xline[i].second;
        count = 0;
        d = 1;
        //向左
        while (i - d >= 0 && xline[i - d].first >= tx - 1)
        {
            if (xline[i - d].first == tx && xline[i - d].second == ty + 1)
            {
                count++;
            }
            if (xline[i - d].first == tx && xline[i - d].second == ty - 1)
            {
                count++;
            }
            if (xline[i - d].first == tx - 1 && xline[i - d].second == ty)
            {
                count++;
            }
            d++;
        }
        d = 1;
        //向右
        while (i + d <= n && xline[i + d].first <= tx + 1)
        {
            if (xline[i + d].first == tx && xline[i + d].second == ty + 1)
            {
                count++;
            }
            if (xline[i + d].first == tx && xline[i + d].second == ty - 1)
            {
                count++;
            }
            if (xline[i + d].first == tx + 1 && xline[i + d].second == ty)
            {
                count++;
            }
            d++;
        }
        if (count == 4)
        {
            d = 1;
            //向左
            while (i - d >= 0 && xline[i - d].first >= tx - 1)
            {
                if (xline[i - d].first == tx - 1 && xline[i - d].second == ty - 1)
                {
                    count++;
                }
                if (xline[i - d].first == tx - 1 && xline[i - d].second == ty + 1)
                {
                    count++;
                }
                d++;
            }
            d = 1;
            //向右
            while (i + d <= n && xline[i + d].first <= tx + 1)
            {
                if (xline[i + d].first == tx + 1 && xline[i + d].second == ty - 1)
                {
                    count++;
                }
                if (xline[i + d].first == tx + 1 && xline[i + d].second == ty + 1)
                {
                    count++;
                }
                d++;
            }
        }
        if(count==4){
            c0++;
        }else if(count==5){
            c1++;
        }else if(count==6){
            c2++;
        }else if(count==7){
            c3++;
        }else if(count==8){
            c4++;
        }
    }
    printf("%d\n",c0);
    printf("%d\n",c1);
    printf("%d\n",c2);
    printf("%d\n",c3);
    printf("%d\n",c4);
}