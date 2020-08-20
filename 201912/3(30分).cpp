#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

const int N = 105;
int n;
vector<string> equs;

bool solve(string s)
{
    int equ_pos = s.find('=');
    string left = s.substr(0, equ_pos);
    string right = s.substr(equ_pos + 1, s.length() - equ_pos - 1);
    for (int i = 0; i < left.length(); i++)
    {
        int pos = right.find(left[i]);
        if (pos < 0)
            return false;
        right.erase(pos, 1);
    }
    if (right == "")
        return true;
    else
        return false;
}

int main()
{
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        equs.push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        if (solve(equs[i]))
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }
    return 0;
}