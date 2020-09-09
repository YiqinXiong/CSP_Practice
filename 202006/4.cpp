#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int count(string target, string &str)
{
    int ans = 0;
    int pos = 0;
    while ((pos = str.find(target, pos)) != string::npos)
    {
        // cout << pos << endl;
        ans++;
        pos++;
    }
    return ans;
}

void replaceStr(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case '1':
            str[i] = '2';
            break;
        case '2':
            str[i] = '4';
            break;
        case '4':
            str.replace(i, 1, "16");
            i++;
            break;
        case '6':
            str.replace(i, 1, "64");
            i++;
            break;
        default:
            break;
        }
    }
}

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    string numStr = "1";
    for (int i = 1; i <= n; i++)
    {
        replaceStr(numStr);
        // cout << numStr << endl;
    }
    cout << count(s, numStr) << endl;
    return 0;
}