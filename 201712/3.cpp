/* 用时140min， 得分15 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct TM
{
    int yyyy; //年
    int mm;   //月
    int dd;   //日
    int HH;   //小时
    int MM;   //分钟
};

struct COM
{
    int minu;       //分钟
    int hour;       //小时
    int dayOfMonth; //日
    int month;      //月份
    int dayOfWeek;  //星期
    string com;     //指令
};

int n;
const int N = 25;
string startTime;
string endTime;
TM sT, eT;
COM coms[N];
int monthList[12];

int dayOfMonth(int yyyy, int mm)
{
    //闰年，4年一闰，百年不闰，四百年再闰
    if (!(yyyy % 400) || (!(yyyy % 4) && (yyyy % 100)))
    {
        switch (mm)
        {
        case 1:
            return 31;
        case 2:
            return 29;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            break;
        }
    }
    else
    {
        switch (mm)
        {
        case 1:
            return 31;
        case 2:
            return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            break;
        }
    }
}

void resolveCtrlStr(COM *c, string str)
{
    int pos;
    //minutes
    pos = str.find(' ');                          //找分隔点
    (*c).minu = atoi(str.substr(0, pos).c_str()); //取数据
    str = str.substr(pos + 1);                    //移动字符串
    //hours
    pos = str.find(' ');                          //找分隔点
    (*c).hour = atoi(str.substr(0, pos).c_str()); //取数据
    str = str.substr(pos + 1);                    //移动字符串
    //dayOfMonth
    pos = str.find(' ');                                //找分隔点
    (*c).dayOfMonth = atoi(str.substr(0, pos).c_str()); //取数据
    str = str.substr(pos + 1);                          //移动字符串
    //month
    pos = str.find(' ');                           //找分隔点
    (*c).month = atoi(str.substr(0, pos).c_str()); //取数据
    str = str.substr(pos + 1);                     //移动字符串
    //dayOfWeek
    pos = str.find(' ');                               //找分隔点
    (*c).dayOfWeek = atoi(str.substr(0, pos).c_str()); //取数据
    str = str.substr(pos + 1);                         //移动字符串
    //com
    (*c).com = str;
}

void resolveTimeStr(TM *t, string str)
{
    (*t).yyyy = atoi(str.substr(0, 4).c_str());
    (*t).mm = atoi(str.substr(4, 2).c_str());
    (*t).dd = atoi(str.substr(6, 2).c_str());
    (*t).HH = atoi(str.substr(8, 2).c_str());
    (*t).MM = atoi(str.substr(10, 2).c_str());
}

bool cmpCommand(int month, int dayOfMonth, int dayOfWeek, int hour, int minute, COM *c)
{
    if ((*c).minu == minute && (*c).hour == hour && (*c).dayOfWeek == dayOfWeek && (*c).dayOfMonth == dayOfMonth && (*c).month == month)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int minusDay(int y_to, int m_to, int d_to)
{
    int count = 0;
    int y, m, d;
    for (y = 1970; y <= y_to; y++)
    {
        for (m = 1; m <= 12; m++)
        {
            if (y == y_to && m == m_to)
            {
                for (d = 1; d < d_to; d++)
                {
                    count++;
                }
                return count;
            }
            else
            {
                for (d = 1; d <= dayOfMonth(y, m); d++)
                {
                    count++;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> startTime >> endTime;
    getchar();
    resolveTimeStr(&sT, startTime);
    resolveTimeStr(&eT, endTime);
    for (int i = 0; i < n; i++)
    {
        string comLine;
        getline(cin, comLine);
        resolveCtrlStr(&(coms[i]), comLine);
    }
    int y, m, d, dw, hh, mm, com, count_week = 4, count_day = 0;
    for (y = 1970; y <= eT.yyyy; y++)
    {
        for (m = 1; m <= 12; m++)
        {
            if (y == eT.yyyy && m > eT.mm)
                break;
            for (d = 1; d <= dayOfMonth(y, m); d++)
            {
                // printf("%d,%d,%d--%d--%d\n", y, m, d, count_week, count_day);
                if (y == eT.yyyy && m == eT.mm && d > eT.dd)
                    break;
                for (hh = 0; hh < 24; hh++)
                {
                    if (y == eT.yyyy && m == eT.mm && d == eT.dd && hh > eT.HH)
                        break;
                    for (mm = 0; mm < 60; mm++)
                    {
                        if (y == eT.yyyy && m == eT.mm && d == eT.dd && hh == eT.HH && mm > eT.MM)
                            break;
                        // if (y == 2017 && m == 11 && d == 17 && hh == 0 && mm == 7)
                        // {
                        //     printf("%d\n", count_week);
                        // }
                        for (com = 0; com < n; com++)
                        {
                            if (y >= sT.yyyy && cmpCommand(m, d, count_week, hh, mm, &coms[com]))
                            {
                                printf("%d%02d%02d%02d%02d %s\n", y, m, d, hh, mm, coms[com].com.c_str());
                            }
                        }
                    }
                }
                count_week = (count_week % 7) + 1;
                count_day++;
            }
        }
    }
    return 0;
}

// 3 201711170032 201711222352
// 0 7 17 11 5 nihao
// 51 23 18 11 6 hello
// 52 23 19 11 7 nono
