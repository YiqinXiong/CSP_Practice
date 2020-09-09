/* 用时 31 min */
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tree
{
    int id;
    int num;
    int originNum;
    int cutNum;
    bool droped;
    tree(int id, int num, int originNum) : id(id), num(num), originNum(originNum) {}
};

vector<tree> trees;

void solve(int &t, int &d, int &e)
{
    int len = trees.size();
    for (int i = 0; i < len; i++)
    {
        t += trees[i].num;
        if (trees[i].originNum - trees[i].cutNum != trees[i].num)
        {
            trees[i].droped = true;
            d++;
        }
    }
    for (int i = 0; i < len; i++)
    {
        int id1, id2, id3;
        id1 = (i + 0) % len;
        id2 = (i + 1) % len;
        id3 = (i + 2) % len;
        if (trees[id1].droped && trees[id2].droped && trees[id3].droped)
        {
            e++;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int t, d, e;
    t = d = e = 0;
    for (int i = 0; i < n; i++)
    {
        int m;
        scanf("%d",&m);
        int cutCount = 0;
        trees.push_back(tree(i + 1, 0, 0));
        for (int j = 0; j < m; j++)
        {
            int option;
            scanf("%d",&option);
            //统计操作
            if (option > 0)
            {
                trees[i].num = option;
                if(j==0){
                    trees[i].originNum = option;
                }
            }
            //疏果操作
            else
            {
                trees[i].num += option;
                trees[i].cutNum -= option;
            }
        }
    }
    solve(t, d, e);
    cout << t << " " << d << " " << e << endl;
    return 0;
}