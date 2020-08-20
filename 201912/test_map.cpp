#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <regex>
using namespace std;

int main()
{
    map<string, int> mp;
    string test = "hello";
    string tmp = "Aa";
    string it = "666H3O";
    mp[test] += 4;

    regex pat_num("^(\\d)+");
    smatch res_num;
    int front_num;
    //前导数字不为1
    if (regex_search(it, res_num, pat_num))
    {
        
        front_num = atoi(res_num.begin()->str().c_str());
        printf("yes %d!\n",front_num);
    }
    //前导数字为1
    else
    {
        printf("no!\n");
        front_num = 1;
    }

    cout << mp[test] << endl;
    cout << atoi(tmp.substr(2).c_str()) << endl;
    return 0;
}
