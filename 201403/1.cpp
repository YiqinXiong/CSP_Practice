/* 
*   用时 10分
*   得分 100分
*/
#include <cstdio>
#include <iostream>

using namespace std;
const int MAX_N = 2005;
bool arr[MAX_N];
int N;

int main()
{
    int ans = 0;
    fill(begin(arr), end(arr), false);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        //把数字范围调整为[0,2000]
        num += 1000;
        arr[num] = true;
    }
    //检索相反数
    int base = 0 + 1000;
    for (int offset = 1; offset <= 1000; offset++)
    {
        if (arr[base - offset] && arr[base + offset])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}