/* 
*   用时 18分
*   得分 90分，错误
*   思路 遍历n*n种情况，第i个为起点，第j个为终点，i到j之间最小的h为高，则s=(j-i+1)*h
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1005, MAXH = 10005;
int n;
int height[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        int h = MAXH;
        for (int j = i; j < n; j++)
        {
            if (height[j] < h)
            {
                h = height[j];
            }
            int sNew = (j - i + 1) * h;
            // cout << "i: " << i << " ";
            // cout << "j: " << j << " ";
            // cout << "sNew: " << sNew << endl;
            if (sNew > s)
            {
                s = sNew;
            }
        }
    }
    cout << s << endl;
    return 0;
}