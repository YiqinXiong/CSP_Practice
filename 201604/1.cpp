/* 
*   用时 16分
*   得分 100分
*/
#include <stdio.h>
#include <iostream>
using namespace std;

const int N = 1005;
int n;
int a[N];

int main()
{
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n < 3)
    {
        cout << 0 << endl;
    }
    else
    {
        // 初始走势
        bool increase = a[1] > a[0];
        for (int i = 2; i < n; i++)
        {
            if (increase != (a[i] > a[i - 1]))
            {
                increase = a[i] > a[i - 1];
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}