
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

int n;
const int N = 25;
string startTime;
string endTime;


int main()
{
    cin >> n >> startTime >> endTime;
    printf("%d\n",atoi(startTime.c_str()));
    return 0;
}