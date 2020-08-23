/* 
*   用时 5分
*   得分 100分
*/
#include <stdio.h>
#include <iostream>

using namespace std;

const int N = 1005;
int n;

int main()
{
    int last = -1;
    int current;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> current;
        if (current != last)
            ans++;
        last = current;
    }
    cout << ans << endl;
    return 0;
}