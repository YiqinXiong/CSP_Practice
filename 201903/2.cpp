#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

struct symbol
{
    char c;
    int lev; //优先级
    symbol(char c, int lev) : c(c), lev(lev) {}
};

int getLev(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == 'x' || c == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int op(int a, int b, char c)
{
    int res;
    switch (c)
    {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case 'x':
        res = a * b;
        break;
    case '/':
        res = a / b;
        break;
    default:
        break;
    }
    return res;
}

int main()
{
    int n;
    stack<int> res;
    stack<symbol> temp;
    temp.push(symbol('#', getLev('#')));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string expr;
        cin >> expr;
        for (int j = 0; j < expr.length(); j++)
        {
            char c = expr[j];
            //数字直接入res栈
            if (isdigit(c))
            {
                res.push(c - '0');
            }
            //符号c先和symbol栈顶top比较，若c优先级较高则压栈，否则top弹出，进行计算，并将结果压入res，直到遇见比c优先级低的（不包括等于）
            else
            {
                while (!(getLev(c) > temp.top().lev))
                {
                    int b = res.top();
                    res.pop();
                    int a = res.top();
                    res.pop();
                    res.push(op(a, b, temp.top().c));
                    temp.pop();
                }
                temp.push(symbol(c, getLev(c)));
            }
        }
        while (temp.top().c != '#')
        {
            int b = res.top();
            res.pop();
            int a = res.top();
            res.pop();
            res.push(op(a, b, temp.top().c));
            temp.pop();
        }
        if (res.top() == 24)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        res.pop();
    }
    return 0;
}