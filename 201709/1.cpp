/* 
*   用时 9分
*   得分 100分
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

int n;
const int N = 305;

int main()
{
    cin >> n;
    n /= 10;              //n缩小10倍
    int n5 = n / 5;       //满足买5瓶送2瓶这个条件的次数
    int n3 = (n % 5) / 3; //剩下的里面，满足买3瓶送1瓶这个条件的次数
    cout << n + n5 * 2 + n3 << endl;
    return 0;
}