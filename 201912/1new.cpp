/*
*   用时 15分
*   得分 100分
*/

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int n;
int a[4];

bool isJump(int n)
{
    if(!(n%7)) return true;
    while(n>0)
    {
        if((n%10)==7)
        {
            return true;
        }
        n/=10;
    }
    return false;
}

int main()
{
    cin >> n;
    int counter=0;
    int num=1;
    while(counter<n)
    {
        if(isJump(num))
        {
            a[(num-1)%4]++;
        }
        else
        {
            counter++;
        }
        num++;
    }
    for(int i=0;i<4;i++){
        cout << a[i] << endl;
    }
    return 0;
}
