/* 
*   用时 39分
*   得分 100分
*   起初编译错误，原因是结构体名字命名为stat，猜测和测试服务器中变量重名
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct statistics
{
    int value;      //值
    int occurrence; //出现次数
    statistics(int v, int o) : value(v), occurrence(o) {}
};

const int N = 1005;

int input[N];
vector<statistics> output;

int n;

//按规则排序：1.出现次数递减 2.值递增
bool cmp(statistics a, statistics b)
{
    if (a.occurrence == b.occurrence)
    {
        return a.value < b.value;
    }
    return a.occurrence > b.occurrence;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    //先排序，相等的聚在一起
    sort(input, input + n);
    //统计每一段的数量
    int last = input[0];
    int lastIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (input[i] != last)
        {
            output.push_back(statistics(last, i - lastIndex));
            lastIndex = i;
        }
        last = input[i];
    }
    output.push_back(statistics(last, n - lastIndex));
    //按规则排序：1.出现次数递减 2.值递增
    sort(output.begin(), output.end(), cmp);
    vector<statistics>::iterator it;
    for (it = output.begin(); it != output.end(); it++)
    {
        cout << it->value << " " << it->occurrence << endl;
    }
    return 0;
}
