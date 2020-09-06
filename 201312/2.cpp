/* 
*   用时 29分
*   得分 100分
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int originVeriCode;
int arr[9];

int mul()
{
    int ans = 0;
    for (int i = 0; i < 9; i++)
    {
        ans += arr[i] * (i + 1);
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    int index = 0;
    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == '-')
        {
            continue;
        }
        arr[index++] = str[i] - '0';
    }
    originVeriCode = str[str.length() - 1] == 'X' ? 10 : str[str.length() - 1] - '0';
    int verifyCode = mul() % 11;
    if (verifyCode == originVeriCode)
    {
        cout << "Right" << endl;
    }
    else
    {
        str[str.length() - 1] = verifyCode == 10 ? 'X' : '0' + verifyCode;
        cout << str << endl;
    }
    return 0;
}