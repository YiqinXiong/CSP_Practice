/* 
*   用时 8分
*   得分 100分
*/

#include <stdio.h>
#include <iostream>

using namespace std;
int n;

int main()
{
    int res;
    cin >> n;
    do
    {
        res += n % 10;
    } while ((n = n / 10));
    cout << res << endl;
    return 0;
}