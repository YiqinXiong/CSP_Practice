/* 耗时 150 min，得分80 */
/*
* 思路：规范化结构：{bool hasid：是否有id, string tag:标签, string id:元素id}
* 一个父亲指针father
*
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct elem
{
    bool hasid;   //是否有id
    string tag;   //标签
    string id;    //id
    elem *father; //指向父亲（上级元素）的指针
};

typedef pair<int, elem *> P; //int记录层级，elem*记录了层级变化时上一层的指针

int n, m;
const int N = 105;
const int M = 15;
elem text[N];   //记录每一行的html文本，每行一个元素
stack<P> level; //用栈记录层级变化
int res[N];     //记录输出结果

//转换为大写串
string toUpper(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] += ('A' - 'a');
        }
    }
    return str;
}

int main()
{
    //初始化
    for (int i = 0; i < N; i++)
    {
        text[i].father = NULL;
        text[i].hasid = false;
        text[i].id = "";
        text[i].tag = "";
    }
    //读入
    string tmp;
    int pos1, pos2;
    scanf("%d %d", &n, &m);
    getchar();
    //处理根结点
    getline(cin, tmp);
    level.push(P(0, NULL));
    text[0].father = NULL;
    if ((pos1 = tmp.find('#')) != -1)
    {
        text[0].hasid = true;
        text[0].id = tmp.substr(pos1);
        text[0].tag = toUpper(tmp.substr(0, pos1 - 1));
    }
    else
    {
        text[0].tag = toUpper(tmp);
    }
    //处理其他节点
    for (int i = 1; i < n; i++)
    {
        getline(cin, tmp);
        pos1 = tmp.find('#');
        pos2 = tmp.find_last_of('.'); //字符串中最后一个'.'的位置，找不到返回-1

        /* 分离tag和id，tag全大写，id带#号 */
        if (pos1 != -1)
        {
            text[i].hasid = true;
            text[i].id = tmp.substr(pos1);
            text[i].tag = toUpper(tmp.substr(pos2 + 1, pos1 - pos2 - 2));
        }
        else
        {
            text[i].tag = toUpper(tmp.substr(pos2 + 1));
        }

        /* 处理父子关系 */
        //向深处一级
        if (pos2 > level.top().first)
            level.push(P(pos2, &(text[i - 1]))); //保存爸爸
        //向浅处一级
        else if (pos2 < level.top().first)
            level.pop();
        text[i].father = level.top().second;
    }
    int count;  //计数器
    elem *eptr; //指针
    for (int i = 0; i < m; i++)
    {
        getline(cin, tmp);
        pos1 = tmp.find(' ');
        pos2 = tmp.find('#');
        count = 0;
        //多层次的选择器
        if (pos1 != -1)
        {
            bool flg;
            string A = tmp.substr(0, pos1);  //选择器A
            string B = tmp.substr(pos1 + 1); //选择器B
            pos1 = A.find('#');
            pos2 = B.find('#');
            //B为id选择器
            if (pos2 != -1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (text[j].hasid && text[j].id == B)
                    {
                        flg = false;
                        //A为id选择器
                        if (pos1 != -1)
                        {
                            eptr = text[j].father;
                            while (eptr != NULL)
                            {
                                if (eptr->hasid && eptr->id == A)
                                {
                                    flg = true;
                                    break;
                                }
                                eptr = eptr->father;
                            }
                            if (flg)
                            {
                                res[count] = j + 1;
                                count++;
                            }
                        }
                        //A为tag选择器
                        else
                        {
                            A = toUpper(A); //变为大写
                            eptr = text[j].father;
                            while (eptr != NULL)
                            {
                                if (eptr->tag == A)
                                {
                                    flg = true;
                                    break;
                                }
                                eptr = eptr->father;
                            }
                            if (flg)
                            {
                                res[count] = j + 1;
                                count++;
                            }
                        }
                    }
                }
            }
            //B为tag选择器
            else
            {
                B = toUpper(B); //变为大写
                for (int j = 0; j < n; j++)
                {
                    if (text[j].tag == B)
                    {
                        flg = false;
                        //A为id选择器
                        if (pos1 != -1)
                        {
                            eptr = text[j].father;
                            while (eptr != NULL)
                            {
                                if (eptr->hasid && eptr->id == A)
                                {
                                    flg = true;
                                    break;
                                }
                                eptr = eptr->father;
                            }
                            if (flg)
                            {
                                res[count] = j + 1;
                                count++;
                            }
                        }
                        //A为tag选择器
                        else
                        {
                            A = toUpper(A); //变为大写
                            eptr = text[j].father;
                            while (eptr != NULL)
                            {
                                if (eptr->tag == A)
                                {
                                    flg = true;
                                    break;
                                }
                                eptr = eptr->father;
                            }
                            if (flg)
                            {
                                res[count] = j + 1;
                                count++;
                            }
                        }
                    }
                }
            }
        }
        //单层找id的选择器
        else if (pos2 != -1)
        {
            for (int j = 0; j < n; j++)
            {
                if (text[j].hasid && text[j].id == tmp)
                {
                    res[count] = j + 1;
                    count++;
                }
            }
        }
        //单层找tag的选择器
        else
        {
            tmp = toUpper(tmp); //变为大写
            for (int j = 0; j < n; j++)
            {
                if (text[j].tag == tmp)
                {
                    res[count] = j + 1;
                    count++;
                }
            }
        }
        //输出结果
        printf("%d", count);
        for (int j = 0; j < count; j++)
        {
            printf(" %d", res[j]);
        }
        printf("\n");
    }
    return 0;
}