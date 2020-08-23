/* 
*   用时 18分
*   得分 100分
*/
#include <stdio.h>
#include <iostream>

using namespace std;

int y, d;
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isRun(int y)
{
    return (!(y % 4) && y % 100) || (!y % 400);
}

int main()
{
    cin >> y;
    cin >> d;
    if (isRun(y))
        month[1] = 29;
    int i;
    for (i = 0; i < 12; i++)
    {
        d -= month[i];
        if (d <= 0)
        {
            d += month[i];
            break;
        }
    }
    cout << i + 1 << endl;
    cout << d << endl;
    return 0;
}