/* 用时22分 */
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int time = 0;
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
            switch (k)
            {
            case 1:
                /* 红灯red：zone=红、绿、黄 */
                time += t;
                break;
            case 2:
                /* 黄灯yellow：zone=黄、红、绿 */
                time += t + r;
                break;
            case 3:
                /* 绿灯green：zone=绿、黄、红 */
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