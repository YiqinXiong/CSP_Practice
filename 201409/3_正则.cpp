/*
*   时间：24min
*   得分：100
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <regex>
using namespace std;

string S;
int caseSense;
int n;
const int N = 105;
const int MAX_LEN = 105;

int main()
{
    string input;
    string pattern;
    getline(cin, S);
    pattern = "^[a-zA-Z]*" + S + "[a-zA-Z]*$";
    cin >> caseSense;
    regex pat;
    if (caseSense)
    {
        pat.assign(pattern);
    }
    else
    {
        pat.assign(pattern, regex::icase);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        smatch res;
        if (regex_match(input, res, pat))
        {
            cout << input << endl;
        }
    }
    return 0;
}
