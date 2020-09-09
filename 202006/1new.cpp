#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> P;
typedef vector<P> vp;

//t0+t1x+t2y一致大于0为0，一致小于0为1，有大有小为-1
int test(vp &vec, int t0, int t1, int t2, int init)
{
    int res = init;
    for (int i = 0; i < vec.size(); i++)
    {
        int x = vec[i].first;
        int y = vec[i].second;
        if (t0 + t1 * x + t2 * y > 0)
        {
            if (res == 1)
            {
                return -1;
            }
            res = 0;
        }
        else
        {
            if (res == 0)
            {
                return -1;
            }
            res = 1;
        }
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vp pA, pB;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'A')
        {
            pA.push_back(make_pair(x, y));
        }
        else
        {
            pB.push_back(P(x, y));
        }
    }
    for (int i = 0; i < m; i++)
    {
        int t0, t1, t2;
        cin >> t0 >> t1 >> t2;
        int resA = test(pA, t0, t1, t2, 2);
        if (resA == -1)
        {
            cout << "No" << endl;
        }
        else
        {
            int resB = test(pB, t0, t1, t2, !resA);
            if (resB == -1)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}