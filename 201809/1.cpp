/* 用时8分 */
#include <cstdio>
#include <iostream>

using namespace std;

int a[1005];
int n;

int getAvg(int i)
{
    int avg;
    if (i == 1)
    {
        avg = (a[i] + a[i + 1]) / 2;
    }
    else if (i == n)
    {
        avg = (a[i - 1] + a[i]) / 2;
    }
    else
    {
        avg = (a[i - 1] + a[i] + a[i + 1]) / 3;
    }
    return avg;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << getAvg(i) << " ";
    }
    cout << endl;
    return 0;
}

/*
8
4 1 3 1 6 5 17 9
*/