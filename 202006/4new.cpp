#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

/*
1) 1 -> (2)
2) 2 -> (4)
3) 4 -> (1,6,16)
4) 6 -> (6,4,64)
5) 16 -> 264(26)不算64因为64是16中的6生成的，而不是16新生成的
6) 26 -> 464(46)不算64因为64是26中的6生成的，而不是26新生成的
7) 46 -> 1664(66)
8) 66 -> 6464(46)
9) 64 -> 6416(41)
10) 41 -> 162(62)
11) 62 -> 644(44)
12) 44 -> 1616(61)
13) 61 -> 642(42)
14) 42 -> 164(64)

DP:
1) 1 <- (3)
2) 2 <- (1)
3) 4 <- (2,4)
4) 6 <- (3,4)
5) 16 <- (3)
6) 26 <- (5)
7) 46 <- (6,8)
8) 66 <- (7)
9) 64 <- (4,14)
10) 41 <- (9)
11) 62 <- (10)
12) 44 <- (11)
13) 61 <- (12)
14) 42 <- (13)
*/

typedef long long ll;
ll lastArr[15];
ll curArr[15];
map<string, int> mymap;

const int mod = 998244353;

void copy(ll *last, ll *cur)
{
    for (int i = 1; i <= 14; i++)
    {
        last[i] = cur[i] % mod;
        cur[i] = 0;
    }
}

int main()
{
    //初始化map
    mymap["1"] = 1;
    mymap["2"] = 2;
    mymap["4"] = 3;
    mymap["6"] = 4;
    mymap["16"] = 5;
    mymap["26"] = 6;
    mymap["46"] = 7;
    mymap["66"] = 8;
    mymap["64"] = 9;
    mymap["41"] = 10;
    mymap["62"] = 11;
    mymap["44"] = 12;
    mymap["61"] = 13;
    mymap["42"] = 14;
    //输入
    int n;
    string s;
    cin >> n;
    cin >> s;
    int index = mymap[s];
    lastArr[1] = 1;
    for (int i = 0; i < n; i++)
    {
        curArr[1] += lastArr[3];
        curArr[2] += lastArr[1];
        curArr[3] += lastArr[2] + lastArr[4];
        curArr[4] += lastArr[3] + lastArr[4];
        curArr[5] += lastArr[3];
        curArr[6] += lastArr[5];
        curArr[7] += lastArr[6] + lastArr[8];
        curArr[8] += lastArr[7];
        curArr[9] += lastArr[4] + lastArr[14];
        curArr[10] += lastArr[9];
        curArr[11] += lastArr[10];
        curArr[12] += lastArr[11];
        curArr[13] += lastArr[12];
        curArr[14] += lastArr[13];
        copy(lastArr, curArr);
    }
    cout << lastArr[index] << endl;
    return 0;
}