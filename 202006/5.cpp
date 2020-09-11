#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

struct depend
{
    int depId, depType;
    depend(int id, int type) : depId(id), depType(type) {}
};

struct item
{
    int l, r, a, b, c;
    int depId, depType;
    item(int l, int r, int a, int b, int c) : l(l), r(r), a(a), b(b), c(c) {}
    double getMid()
    {
        return -(this->b / (2.0 * this->a));
    }
};

int n, m;
map<int, item> items;
map<int, depend> depends;
int buyNum[1005];

bool allBuy()
{
    for (int i = 0; i < n; i++)
    {
        if (buyNum[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int solve()
{
    int ans = 0;
    bool changed = true;
    int i=0;
    while (!allBuy() && changed)
    {
        changed = false;
        if(depends[i])
        i=(i+1)%n;
    }

    return ans;
}

int countHappy()
{
    int ans = 0;
    for (int i = 0; i < 1005; i++)
    {
        int num = buyNum[i];
        if (num == 0)
        {
            continue;
        }
        item &a = items[i];
        int happy = a.a * num * num + a.b * num + a.c;
        if (happy > 0)
        {
            ans += happy;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int l, r, a, b, c;
        cin >> l >> r >> a >> b >> c;
        items.insert(make_pair(i, item(l, r, a, b, c)));
    }
    for (int i = 1; i <= m; i++)
    {
        int z, x, y;
        cin >> z >> x >> y;
        depends.insert(make_pair(y, depend(x, z)));
    }
    int ans = solve();
    cout << ans << endl;
    return 0;
}