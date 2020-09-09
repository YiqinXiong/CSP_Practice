/* 用时 18 min */
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cutItem
{
    int id;
    int num;
    cutItem(int id, int num) : id(id), num(num) {}
};

vector<int> apples;
vector<cutItem> cuts;

bool cmp(cutItem &a, cutItem &b)
{
    if (a.num == b.num)
        return a.id < b.id;
    return a.num > b.num;
}

int sumNum()
{
    int sum = 0;
    for (int i = 0; i < apples.size(); i++)
    {
        sum += apples[i];
    }
    return sum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int t, k, p;
    for (int i = 0; i < n; i++)
    {
        int appleNum;
        cin >> appleNum;
        apples.push_back(appleNum);
        int cutCount = 0;
        for (int j = 0; j < m; j++)
        {
            int cut;
            cin >> cut;
            apples[i] += cut;
            cutCount -= cut;
        }
        cuts.push_back(cutItem(i + 1, cutCount));
    }
    t = sumNum();
    sort(cuts.begin(), cuts.end(), cmp);
    k = cuts[0].id;
    p = cuts[0].num;
    cout << t << " " << k << " " << p << endl;
    return 0;
}