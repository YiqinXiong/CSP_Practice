/* 
*   用时 1小时31分
*   得分 60分
*   对开盘价排序，按开盘价从高向低遍历，记录最高的成交量
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct order
{
    int type; //0：buy、1：sell、2：cancel、-1：invalid
    double price;
    int num;
    order(int t, double p, int n) : type(t), price(p), num(n) {}
};

struct priceNum
{
    double price;
    int num;
    priceNum(double p, int n) : price(p), num(n) {}
};

vector<order> allOrder;
vector<order> buyOrder;
vector<order> sellOrder;
priority_queue<int> cancels;
priority_queue<double> prices;
set<double> priceSet;
vector<priceNum> priceNumVector;

void printOder(vector<order> vec)
{
    vector<order>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++)
    {
        if (it->type == -1)
        {
            cout << "删除行号" << it->num << endl;
        }
        else if (it->type == 0)
        {
            cout << "buy" << it->price << " " << it->num << endl;
        }
        else if (it->type == 1)
        {
            cout << "sell" << it->price << " " << it->num << endl;
        }
        else if (it->type == 2)
        {
            cout << "cancel" << it->price << " " << it->num << endl;
        }
    }
}

bool cmp1(order a, order b)
{
    return a.price > b.price;
}

bool cmp2(order a, order b)
{
    return a.price < b.price;
}

bool cmp3(priceNum a, priceNum b)
{
    return a.num > b.num;
}

int main()
{
    string str, st;
    //输入
    while (getline(cin, str))
    {
        stringstream ss(str);
        ss >> st;
        if (st == "buy")
        {
            double p;
            int s;
            ss >> p >> s;
            allOrder.push_back(order(0, p, s));
            priceSet.insert(p);
        }
        else if (st == "sell")
        {
            double p;
            int s;
            ss >> p >> s;
            allOrder.push_back(order(1, p, s));
            priceSet.insert(p);
        }
        else if (st == "cancel")
        {
            int c;
            ss >> c;
            cancels.push(c);
            allOrder.push_back(order(2, 0, c));
            // cout << "输入的删除行号：" << c << endl;
        }
    }
    // cout << "打印刚输入后的allOrder" << endl;
    // printOder(allOrder);
    //删掉cancel的条目
    while (!cancels.empty())
    {
        int idx = cancels.top() - 1;
        cancels.pop();
        allOrder[idx].type = -1;
        allOrder[idx].num = idx;
    }
    // cout << "打印删掉cancel的条目后的allOrder" << endl;
    // printOder(allOrder);
    //得到各个成交价
    set<double>::iterator sit;
    for (sit = priceSet.begin(); sit != priceSet.end(); sit++)
    {
        prices.push(*sit);
    }
    //区分buyOrder和sellOrder
    vector<order>::iterator it;
    for (it = allOrder.begin(); it != allOrder.end(); it++)
    {
        if (it->type == 0)
        {
            buyOrder.push_back(*it);
        }
        else if (it->type == 1)
        {
            sellOrder.push_back(*it);
        }
    }
    //按照成交价格排序，买单从大到小，卖单从小到大
    sort(buyOrder.begin(), buyOrder.end(), cmp1);
    sort(sellOrder.begin(), sellOrder.end(), cmp2);
    // cout << "打印排序后的buyOrder" << endl;
    // printOder(buyOrder);
    // cout << "打印排序后的sellOrder" << endl;
    // printOder(sellOrder);
    //遍历每个成交价格，记录每个成交价格的成交量
    while (!prices.empty())
    {
        double pri = prices.top();
        prices.pop();
        vector<order>::iterator buyIt, sellIt;
        buyIt = buyOrder.begin();
        sellIt = sellOrder.begin();
        int buyNum = 0, sellNum = 0;
        while (buyIt != buyOrder.end() && buyIt->price >= pri)
        {
            buyNum += buyIt->num;
            buyIt++;
        }
        while (sellIt != sellOrder.end() && sellIt->price <= pri)
        {
            sellNum += sellIt->num;
            sellIt++;
        }
        priceNumVector.push_back(priceNum(pri, min(buyNum, sellNum)));
    }
    //按照成交量降序排序，选取首元素输出
    sort(priceNumVector.begin(), priceNumVector.end(), cmp3);
    printf("%.2lf %d", priceNumVector[0].price, priceNumVector[0].num);
    return 0;
}