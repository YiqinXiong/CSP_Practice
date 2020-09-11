/* 用时12分 */
//思路就是找最小的时间点tmin和最大的时间点tmax，找交集
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 2005;
const int MAXT = 1000005;
int tmap[MAXT]; //记录所有时刻
int n;

int main()
{
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < b; j++)
        {
            tmap[j]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int c, d;
        cin >> c >> d;
        for (int j = c; j < d; j++)
        {
            if (tmap[j] == 1)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
4
1 3
5 6
9 13
14 15
2 4
5 7
10 11
13 14
*/