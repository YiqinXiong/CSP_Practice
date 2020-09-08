/*
*   时间：2h23min=143min
*   得分：100
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

//项的各部分
struct termItem
{
    string elem;    //元素
    string formula; //化学式
    termItem(string elem, string formula) : elem(elem), formula(formula) {}
};
typedef vector<termItem> vterm;

//化学式的各部分
struct formulaItem
{
    termItem term;
    int num;
    formulaItem(termItem term, int num) : term(term), num(num) {}
};
typedef vector<formulaItem> vformula;

//表达式的各部分
struct exprItem
{
    int num;
    vformula formula;
    exprItem(int num, vformula &formula) : num(num), formula(formula) {}
};
typedef vector<exprItem> vexpr;

typedef map<string, int> mymap;
mymap leftMap, rightMap;

//获取item的前导系数，并把item中数字部分删除
int getHeadNum(string &item)
{
    //空串默认为1
    if (item.empty())
    {
        return 1;
    }
    //为空的情况，默认为1
    if (item[0] < '0' || item[0] > '9')
    {
        return 1;
    }
    //为数字的情况，使用stoi转换string到int
    int pos = 0;
    for (; pos < item.length(); pos++)
    {
        if (item[pos] < '0' || item[pos] > '9')
        {
            break;
        }
    }
    int ans = stoi(item.substr(0, pos));
    item = item.substr(pos);
    return ans;
}

//获取一个项
termItem getTerm(string &item)
{
    string elem, formula;
    elem = formula = "";
    int pos = 0;
    //元素
    if (isupper(item[pos]))
    {
        //大写+小写
        if (pos + 1 < item.length() && islower(item[pos + 1]))
        {
            pos++;
        }
        elem = item.substr(0, pos + 1);
        item = item.substr(pos + 1);
    }
    //括号括起来的化学式
    else if (item[pos] == '(')
    {
        int lev = 0; //括号匹配层级
        for (pos = pos + 1; pos < item.length(); pos++)
        {
            if (item[pos] == '(')
            {
                lev++;
            }
            if (item[pos] == ')')
            {
                if (lev > 0)
                {
                    lev--;
                }
                else
                {
                    break;
                }
            }
        }
        formula = item.substr(1, pos - 1);
        item = item.substr(pos + 1);
    }
    return termItem(elem, formula);
}

//处理化学式
void handleFormula(string &formula, int bonus, mymap &lrMap)
{
    do
    {
        termItem term = getTerm(formula);
        int num = getHeadNum(formula);
        //是元素，添加到map中
        if (!term.elem.empty())
        {
            lrMap[term.elem] += num * bonus;
        }
        //是化学式，递归调用
        else
        {
            string tempForm = term.formula;
            handleFormula(tempForm, num * bonus, lrMap);
        }
    } while (!formula.empty());
}

//处理表达式
void handleExpr(string expr, mymap &lrMap)
{
    stringstream ss(expr);
    string item;
    while (getline(ss, item, '+'))
    {
        // cout << item << endl;
        int num = getHeadNum(item);
        handleFormula(item, num, lrMap);
    }
}

bool cmpLeftAndRight()
{
    if (leftMap.size() != rightMap.size())
    {
        return false;
    }
    mymap::iterator itl = leftMap.begin();
    for (; itl != leftMap.end(); itl++)
    {
        mymap::iterator itr;
        if ((itr = rightMap.find(itl->first)) == rightMap.end())
        {
            return false;
        }
        if (itl->second != itr->second)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        leftMap.clear();
        rightMap.clear();
        string equ, left, right;
        cin >> equ;
        //拆分左右表达式
        int pos = equ.find('=');
        left = equ.substr(0, pos);
        right = equ.substr(pos + 1);
        //处理左表达式
        handleExpr(left, leftMap);
        //处理右表达式
        handleExpr(right, rightMap);
        //比较左右
        string ans = cmpLeftAndRight() ? "Y" : "N";
        cout << ans << endl;
    }
    return 0;
}