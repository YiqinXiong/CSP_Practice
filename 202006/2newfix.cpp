#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<pair<int, int>> myvec;

int main()
{
    int n, a, b;
    myvec u, v;
    cin >> n >> a >> b;
    for (int i = 0; i < a; i++)
    {
        int index, value;
        scanf("%d %d",&index,&value);
        u.push_back(make_pair(index, value));
    }
    for (int i = 0; i < b; i++)
    {
        int index, value;
        scanf("%d %d",&index,&value);
        v.push_back(make_pair(index, value));
    }
    ll ans = 0;
    int i = 0, j = 0;
    while (i < u.size() && j < v.size())
    {
        if (u[i].first < v[j].first)
        {
            i++;
        }
        else if (u[i].first > v[j].first)
        {
            j++;
        }
        else
        {
            ans += u[i].second * v[j].second;
            i++;
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}