#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

int N=10000;
int n;

bool isSkip(int num){
    if(!(num%7)) return true;
    int bit=num%10;
    if(bit==7) return true;
    num/=10;
    while (num!=0)
    {
        bit=num%10;
        if(bit==7) return true;
        num/=10;
    }
    return false;
}

int main()
{
    scanf("%d",&n);
    int counter=1;
    int skipTimes[4]={0};
    while (n)
    {
        if(isSkip(counter)){
            skipTimes[(counter-1)%4]++;
        }else{
            n--;
        }
        counter++;
    }
    for(int i=0;i<4;i++){
        printf("%d\n",skipTimes[i]);
    }
}