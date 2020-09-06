/*
*   用时 15分
*   得分 100分
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <windows.h>

using namespace std;

const int N=1005;
int n;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int ddx[4] = {-1,1,-1,1};
int ddy[4] = {1,1,-1,-1};
int ans[5];
map<pair<int,int>,bool> canvas;

bool check(pair<int,int> p)
{
    int x,y;
    for(int i=0; i<4; i++)
    {
        x = p.first+dx[i];
        y = p.second+dy[i];

        pair<int,int> newp(x,y);
        if(canvas.find(newp)==canvas.end()) return false;
    }
    return true;
}

int getScore(pair<int,int> p)
{
    int x,y;
    int score=0;
    for(int i=0; i<4; i++)
    {
        x = p.first+ddx[i];
        y = p.second+ddy[i];
        pair<int,int> newp(x,y);
        if(canvas.find(newp)!=canvas.end()) score++;
    }
    return score;
}

int main()
{
    canvas.clear();
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin >> x >> y;
        pair<int,int> p(x,y);
        //cout << p.first << " " << p.second << endl;
        //canvas.insert(pair<pair<int,int>,bool>(p,true));
        canvas[p] = true;
    }
    map<pair<int,int>,bool>::iterator it = canvas.begin();
    for(; it!=canvas.end(); it++)
    {
        if(!check(it->first)) continue;
        int score = getScore(it->first);
        ans[score]++;
    }

    for(int i=0; i<5; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
/*
7
1 2
2 1
0 0
1 1
1 0
2 0
0 1

2
0 0
-100000 10

11
9 10
10 10
11 10
12 10
13 10
11 9
11 8
12 9
10 9
10 11
12 11
*/
