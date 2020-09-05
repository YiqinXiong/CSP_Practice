/* 
*   用时 19分
*   得分 100分
*/
#include <cstdio>
#include <iostream>
#include <algorithm>

struct node
{
    int value;
    int occurTime;
};

const int S = 10005;
int n;
node occurTimes[S];

using namespace std;

bool cmp(node a, node b)
{
    if (a.occurTime == b.occurTime)
        return a.value < b.value;
    return a.occurTime > b.occurTime;
}

void initOccurTimes()
{
    for (int i = 0; i < S; i++)
    {
        occurTimes[i].value = i;
        occurTimes[i].occurTime = 0;
    }
}

int main()
{
    initOccurTimes();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        occurTimes[temp].occurTime++;
    }
    sort(begin(occurTimes), end(occurTimes), cmp);
    cout << occurTimes[0].value << endl;
    return 0;
}