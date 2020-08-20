#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
using namespace std;

int n, q;
const int N = 1000005;
const int Q = 100005;
int l[Q];
int r[Q];

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", l+i, r+i);
    }
    for(int i=0;i<q;i++){
        int s = 0;
        for(int j=l[i];j<=r[i];j++){
            s+=j;
        }
        printf("%d\n",s);
    }
    return 0;
}