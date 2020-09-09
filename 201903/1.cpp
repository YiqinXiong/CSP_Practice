#include <iostream>
#include <cstdio>

using namespace std;

int a[100005];

int main()
{
    int n;
    cin >> n;
    int vmax, vmin;
    bool isDouble;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (a[0] > a[n - 1])
    {
        vmax = a[0];
        vmin = a[n - 1];
    }
    else
    {
        vmax = a[n - 1];
        vmin = a[0];
    }
    printf("%d ", vmax);
    if (n % 2)
    {
        int vmid = a[n / 2];
        printf("%d ", vmid);
    }
    else
    {
        int l, r;
        l = a[n / 2 - 1];
        r = a[n / 2];
        if ((l + r) % 2)
        {
            double vmid = (l + r) / 2.0;
            printf("%.1lf ", vmid);
        }
        else
        {
            int vmid = (l + r) / 2;
            printf("%d ", vmid);
        }
    }
    printf("%d\n", vmin);
    return 0;
}