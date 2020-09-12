/* 用时2小时36分，得分95 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;
int n;
ll s, t;
unordered_map<string, int> mymap;

//初始化mymap
void initMyMap()
{
    mymap["jan"] = 1;
    mymap["feb"] = 2;
    mymap["mar"] = 3;
    mymap["apr"] = 4;
    mymap["may"] = 5;
    mymap["jun"] = 6;
    mymap["jul"] = 7;
    mymap["aug"] = 8;
    mymap["sep"] = 9;
    mymap["oct"] = 10;
    mymap["nov"] = 11;
    mymap["dec"] = 12;
    mymap["sun"] = 0;
    mymap["mon"] = 1;
    mymap["tue"] = 2;
    mymap["wed"] = 3;
    mymap["thu"] = 4;
    mymap["fri"] = 5;
    mymap["sat"] = 6;
}

//存储月份的天数
int monthTable[13][2] = {{0, 0},
                         {31, 31},
                         {28, 29},
                         {31, 31},
                         {30, 30},
                         {31, 31},
                         {30, 30},
                         {31, 31},
                         {31, 31},
                         {30, 30},
                         {31, 31},
                         {30, 30},
                         {31, 31}};

//判断是否是闰年
int isLunar(int yyyy)
{
    if ((!(yyyy % 400)) || (!(yyyy % 4) && (yyyy % 100)))
        return 1;
    return 0;
}

//时间信息结构体
struct timeInfo
{
    int yyyy, mm, dd, HH, MM, week;
    int getWeek()
    {
        int countDay = 0;
        int y = 1970, m = 1, d = 1;
        for (; y < this->yyyy; y++)
        {
            countDay += isLunar(y) ? 366 : 365;
        }
        for (; m < this->mm; m++)
        {
            countDay += monthTable[m][isLunar(this->yyyy)];
        }
        for (; d < this->dd; d++)
        {
            countDay++;
        }
        return ((countDay % 7) + 4) % 7;
    }
    void InitTimeInfo(ll t)
    {
        this->MM = t % 100;
        t /= 100;
        this->HH = t % 100;
        t /= 100;
        this->dd = t % 100;
        t /= 100;
        this->mm = t % 100;
        t /= 100;
        this->yyyy = t;
        this->week = getWeek();
    }
    void Advance()
    {
        this->MM++;
        if (this->MM == 60)
        {
            this->MM = 0;
            this->HH++;
            if (this->HH == 24)
            {
                this->HH = 0;
                this->dd++;
                this->week = (this->week + 1) % 7;
                if (this->dd > monthTable[this->mm][isLunar(this->yyyy)])
                {
                    this->dd = 1;
                    this->mm++;
                    if (this->mm > 12)
                    {
                        this->mm = 1;
                        this->yyyy++;
                    }
                }
            }
        }
    }
};

//判断时间A是否早于时间B
bool isAsmallerthanB(timeInfo &a, timeInfo &b)
{
    if (a.yyyy == b.yyyy)
    {
        if (a.mm == b.mm)
        {
            if (a.dd == b.dd)
            {
                if (a.HH == b.HH)
                {
                    return a.MM < b.MM;
                }
                return a.HH < b.HH;
            }
            return a.dd < b.dd;
        }
        return a.mm < b.mm;
    }
    return a.yyyy < b.yyyy;
}

//信息结构体
struct info
{
    string minutes, hours, dayOfMonth, month, dayOfWeek;
    string command;
    bool recMap[5][60];
    info(string &mm, string &hh, string &day, string &month, string &weekday, string &cmd) : minutes(mm), hours(hh), dayOfMonth(day), month(month), dayOfWeek(weekday), command(cmd)
    {
        fill(recMap[0], recMap[0] + 5 * 60, false);
    }
    int toValue(string &str)
    {
        bool isNum = true;
        for (int i = 0; i < str.length(); i++)
        {
            //大写改小写，忽略大小写
            if (isupper(str[i]))
            {
                str[i] = tolower(str[i]);
            }
            //判断是否是数字字符
            if (!isdigit(str[i]))
            {
                isNum = false;
            }
        }
        //是数字串直接返回值
        if (isNum)
        {
            return stoi(str);
        }
        //是字母则查表返回值
        return mymap[str];
    }
    void handleItem(string &str, int type)
    {
        //找星号
        if (str.find('*') != string::npos)
        {
            for (int i = 0; i < 60; i++)
                recMap[type][i] = true;
            return;
        }
        stringstream ss(str);
        string item;
        //按逗号分割
        while (getline(ss, item, ','))
        {
            //对每一段找减号
            int pos = item.find('-');
            if (pos == string::npos)
            {
                recMap[type][toValue(item)] = true;
            }
            else
            {
                string fromStr = item.substr(0, pos);
                string toStr = item.substr(pos + 1);
                int from = toValue(fromStr);
                int to = toValue(toStr);
                for (int val = from; val <= to; val++)
                {
                    recMap[type][val] = true;
                }
            }
        }
    }
    void InitMap()
    {
        handleItem(this->minutes, 0);
        handleItem(this->hours, 1);
        handleItem(this->dayOfMonth, 2);
        handleItem(this->month, 3);
        handleItem(this->dayOfWeek, 4);
    }
};

int main()
{
    initMyMap();
    vector<info> infos;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++)
    {
        string mm, hh, day, month, weekday, cmd;
        cin >> mm >> hh >> day >> month >> weekday >> cmd;
        infos.push_back(info(mm, hh, day, month, weekday, cmd));
        infos.back().InitMap();
    }

    timeInfo sT, eT, curT;
    sT.InitTimeInfo(s);
    eT.InitTimeInfo(t);
    while (isAsmallerthanB(sT, eT))
    {
        for (auto it = infos.begin(); it != infos.end(); it++)
        {
            if (it->recMap[0][sT.MM])
            {
                // cout << "matchMM:" << sT.MM << endl;
                if (it->recMap[1][sT.HH])
                {
                    // cout << "matchHH:" << sT.HH << endl;
                    if (it->recMap[2][sT.dd])
                    {
                        // cout << "matchdd:" << sT.dd << endl;
                        if (it->recMap[3][sT.mm])
                        {
                            // cout << "matchmm:" << sT.mm << endl;
                            if (it->recMap[4][sT.week])
                            {
                                // cout << "matchweek:" << sT.week << endl;
                                printf("%04d%02d%02d%02d%02d ", sT.yyyy, sT.mm, sT.dd, sT.HH, sT.MM);
                                cout << it->command << endl;
                            }
                        }
                    }
                }
            }
        }
        sT.Advance();
    }

    return 0;
}

/*
3 201711170032 201711222352
0 7 * * 1,3-5 get_up
30 23 * * Sat,Sun go_to_bed
15 12,18 * * * have_dinner

1 201711170000 201711172359
0 7 * * 1,3-5 get_up
30 23 * * Sat,Sun go_to_bed
15 12,18 * * * have_dinner

1 201711182329 201711192331
30 23 * * Sat,Sun go_to_bed
*/