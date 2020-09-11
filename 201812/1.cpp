/* 用时42分 */
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int main()
{
    ll time = 0;
    int r, y, g;
    cin >> r >> y >> g;
    int mod = r + y + g;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k, t;
        cin >> k >> t;
        //通过道路
        if (k == 0)
        {
            time += t;
        }
        //信号灯
        else
        {
            int delta = time % mod;
            int pos;
            switch (k)
            {
            case 1:
                /* 红灯red：zone=红、绿、黄 */
                pos = (r - t + delta) % mod;
                if (pos >= 0 && pos < r)
                {
                    //等红灯
                    time += r - pos;
                }
                else if (pos >= r + g && pos < r + g + y)
                {
                    //等黄灯
                    time += r + g + y - pos + r;
                }
                break;
            case 2:
                /* 黄灯yellow：zone=黄、红、绿 */
                pos = (y - t + delta) % mod;
                if (pos >= 0 && pos < y + r)
                {
                    //等红灯/黄灯
                    time += y + r - pos;
                }
                break;
            case 3:
                /* 绿灯green：zone=绿、黄、红 */
                pos = (g - t + delta) % mod;
                if (pos >= g && pos < g + y + r)
                {
                    //等红灯/黄灯
                    time += g + y + r - pos;
                }
                break;
            default:
                break;
            }
        }
    }
    cout << time << endl;
    return 0;
}

/*
30 3 30
8
0 10
1 5
0 11
2 2
0 6
0 3
3 10
0 3
*/