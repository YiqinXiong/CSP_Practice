/* 
*   用时 8分
*   得分 100分
*/
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const int N = 1005;
int n;
int arr[N];

int main()
{
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) == 1)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}