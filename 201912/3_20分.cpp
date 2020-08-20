#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <map>
#include <regex>
#include <stdlib.h>
using namespace std;

int n;
const int N = 105;
vector<string> ls, rs;
map<string, int> l_map, r_map;

int main()
{
    string src, pattern;
    string left, right;
    bool flag;
    int pos_equ;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        string src, pattern;
        string left, right;
        flag = true;
        l_map.clear();
        r_map.clear();
        ls.clear();
        rs.clear();
        cin >> src;
        if (src.find('(') != string::npos)
        {
            printf("N\n");
            continue;
        }
        pos_equ = src.find('=');
        left = src.substr(0, pos_equ);
        right = src.substr(pos_equ + 1);
        // cout << left << endl;
        // cout << right << endl;
        pattern = "[A-Z]+";
        regex pat(pattern);
        sregex_iterator end;
        //左拆分
        sregex_iterator iter_l(left.begin(), left.end(), pat);
        for (auto it = iter_l; it != end; it++)
        {
            ls.push_back(it->str());
        }
        //右拆分
        sregex_iterator iter_r(right.begin(), right.end(), pat);
        for (auto it = iter_r; it != end; it++)
        {
            rs.push_back(it->str());
        }
        //左统计
        for (vector<string>::iterator it = ls.begin(); it != ls.end(); it++)
        {
            regex pat_num("^(\\d)+");
            smatch res_num;
            int front_num;
            //前导数字不为1
            if (regex_search(*it, res_num, pat_num))
            {
                front_num = atoi(res_num.begin()->str().c_str());
            }
            //前导数字为1
            else
            {
                front_num = 1;
            }
            regex pat_elem("[A-Z]");
            sregex_iterator iter_s_l(it->begin(), it->end(), pat_elem);
            for (auto it = iter_s_l; it != end; it++)
            {
                string sub_elem;
                int sub_num;
                string tmp = it->str();
                if (it->length() == 1)
                {
                    sub_elem = tmp;
                    sub_num = 1;
                }
                else
                {
                    char c = tmp[1];
                    //A+数字
                    if (c >= '0' && c <= '9')
                    {
                        sub_elem = tmp.substr(0, 1);
                        sub_num = atoi(tmp.substr(1).c_str());
                    }
                    //Aa+数字
                    else
                    {
                        sub_elem = tmp.substr(0, 2);
                        sub_num = atoi(tmp.substr(2).c_str());
                    }
                }
                l_map[sub_elem] += (sub_num * front_num);
            }
        }
        //右统计
        for (vector<string>::iterator it = rs.begin(); it != rs.end(); it++)
        {
            regex pat_num("^(\\d)+");
            smatch res_num;
            int front_num;
            //前导数字不为1
            if (regex_search(*it, res_num, pat_num))
            {
                front_num = atoi(res_num.begin()->str().c_str());
            }
            //前导数字为1
            else
            {
                front_num = 1;
            }
            regex pat_elem("[A-Z]");
            sregex_iterator iter_s_r(it->begin(), it->end(), pat_elem);
            for (auto it = iter_s_r; it != end; it++)
            {
                string sub_elem;
                int sub_num;
                string tmp = it->str();
                if (it->length() == 1)
                {
                    sub_elem = tmp;
                    sub_num = 1;
                }
                else
                {
                    char c = tmp[1];
                    //A+数字
                    if (c >= '0' && c <= '9')
                    {
                        sub_elem = tmp.substr(0, 1);
                        sub_num = atoi(tmp.substr(1).c_str());
                    }
                    //Aa+数字
                    else
                    {
                        sub_elem = tmp.substr(0, 2);
                        sub_num = atoi(tmp.substr(2).c_str());
                        if (sub_num == 0)
                            sub_num = 1;
                    }
                }
                r_map[sub_elem] += (sub_num * front_num);
            }
        }
        map<string, int>::iterator map_it;
        for (map_it = l_map.begin(); map_it != l_map.end(); map_it++)
        {
            int r_num = r_map[map_it->first];
            if (map_it->second != r_num)
            {
                flag = false;
                break;
            }
        }
        if (flag)
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