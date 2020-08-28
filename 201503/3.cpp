/* 
*   用时 49分
*   得分 100分
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int a, b, c, y1, y2;

bool isRun(int year)
{
    return !(year % 4) && (year % 100) || !(year % 400);
}

// 返回y年a月的第一个星期c是a月的第几天（天数从0计算）
int getFirstDayOfMonth(int y, int a, int c)
{
    int days = 0;
    /*** 计算1850年1月1日到y年a月1日的天数*/
    // 1.计算1850年1月1日到y年1月1日的天数
    for (int i = 1850; i < y; i++)
    {
        isRun(i) ? days += 366 : days += 365;
    }
    // 2.计算y年1月1日到y年a月1日的天数
    isRun(y) ? month[2] = 29 : month[2] = 28;
    for (int i = 1; i < a; i++)
    {
        days += month[i];
    }
    /*** 计算y年a月1日是星期几（从1计算）*/
    int firstDay = (((days % 7) + (2 - 1)) % 7) + 1;
    /*** 计算y年a月的第一个星期c是第几天（从0计算）*/
    if (c >= firstDay)
        return c - firstDay;
    return c + 7 - firstDay;
}

int main()
{
    cin >> a >> b >> c >> y1 >> y2;
    for (int i = y1; i <= y2; i++)
    {
        int firstWeekDay = getFirstDayOfMonth(i, a, c);
        int counter = 0;
        int j;
        for (j = firstWeekDay; j < month[a]; j += 7)
        {
            counter++;
            if (counter == b)
            {
                printf("%d/%02d/%02d\n", i, a, j + 1);
                break;
            }
        }
        if (counter < b)
        {
            printf("none\n");
        }
    }

    return 0;
}
