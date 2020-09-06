/* 
*   测试字符串使用>和<号进行比较，结果是可以比较，按照字典序
 */
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1 = "crm:0";
    string s2 = "crm:1";
    string s3 = "a0";
    string res1 = s1 > s2 ? "s1>s2" : "s1<s2";
    string res2 = s1 > s3 ? "s1>s3" : "s1<s3";
    string res3 = s2 > s3 ? "s2>s3" : "s2<s3";
    cout << res1 << endl;
    cout << res2 << endl;
    cout << res3 << endl;
    return 0;
}