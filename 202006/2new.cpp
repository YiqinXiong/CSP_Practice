#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef map<int, int> mymap;

int main()
{
    int n, a, b;
    mymap umap, vmap;
    cin >> n >> a >> b;
    for (int i = 0; i < a; i++)
    {
        int index, value;
        cin >> index >> value;
        umap[index] = value;
    }
    for (int i = 0; i < b; i++)
    {
        int index, value;
        cin >> index >> value;
        vmap[index] = value;
    }
    ll ans = 0;
    for (auto it = umap.begin(); it != umap.end(); it++)
    {
        mymap::iterator findRes;
        if ((findRes = vmap.find(it->first)) != vmap.end())
        {
            ans += it->second * findRes->second;
        }
    }
    cout << ans << endl;
    return 0;
}