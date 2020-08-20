/* 
*   用时 1小时25分
*   得分 100分
 */
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
const int MAX_N = 1005;
const int MAX_K = 1005;
int w, s, c; //教室号，开始时间，持续时间
const int MAX_w = 1005;
const int MAX_s = 10005;
const int MAX_c = 105;
const int endtime = MAX_s + MAX_c;
vector<int> keys; //钥匙柜
struct elem
{
    bool is_get; //1为取，0为放
    int index;   //钥匙编号
    int time;    //时间点
};
vector<elem> events; //事件

bool cmp_elem(elem a, elem b)
{
    if (a.time == b.time)
    {
        if (a.is_get == b.is_get)
        {
            //同时取或同时放，按钥匙顺序排列
            return a.index < b.index;
        }
        else
        {
            //先放后取
            return !(a.is_get);
        }
    }
    else
    {
        return a.time < b.time;
    }
}

//取钥匙
void get_key(int w)
{
    vector<int>::iterator it = find(keys.begin(), keys.end(), w);
    *it = 0;
}

//还钥匙
void return_key(int w)
{
    //找最左边空位置
    vector<int>::iterator it = find(keys.begin(), keys.end(), 0);
    *it = w;
}

int main()
{
    elem tmp;
    cin >> N >> K;
    //初始化
    for (int i = 0; i < N; i++)
    {
        keys.push_back(i + 1);
    }
    for (int i = 0; i < K; i++)
    {
        cin >> w >> s >> c;
        events.push_back(elem{true, w, s});
        events.push_back(elem{false, w, s + c});
    }
    sort(events.begin(), events.end(), cmp_elem);
    for (vector<elem>::iterator it = events.begin(); it != events.end(); it++)
    {
        if (it->is_get)
        {
            get_key(it->index);
        }
        else
        {
            return_key(it->index);
        }
    }
    vector<int>::iterator it;
    for (it = keys.begin(); it != keys.end() - 1; it++)
    {
        cout << *it << " ";
    }
    it = keys.end() - 1;
    cout << *it << endl;
    return 0;
}