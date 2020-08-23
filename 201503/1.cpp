/* 
*   用时 8分
*   得分 100分
*/
#include <stdio.h>
#include <iostream>

using namespace std;
const int MAX_NM = 1005;
int n, m;
int map[MAX_NM][MAX_NM];

int main()
{
    cin >> n >> m;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            cin >> map[row][col];
        }
    }
    for (int col = m-1; col >= 0; col--)
    {
        for (int row = 0; row < n; row++)
        {
            cout << map[row][col] << " ";
        }
        cout << endl;
    }
    return 0;
}