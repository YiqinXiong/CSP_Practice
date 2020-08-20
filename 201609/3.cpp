/* 
*   用时 1小时34分
*   得分 10分
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int N = 1005;
const int HERO = 100, SLAVE = 101;

int n;

struct role
{

    int type; //英雄、随从
    int hp;   //生命值
    int ap;   //攻击力
};

role heroA;
role heroB;
role *slaveA[7];
role *slaveB[7];
// vector<role> slaveA;
// vector<role> slaveB;
bool isA = true;
int winResult = 0;

void printRes()
{
    printf("%d\n", winResult);
    printf("%d\n", heroA.hp);
    int p = 0;
    for (int i = 0; i < 7; i++)
    {
        if (slaveA[i] != nullptr)
        {
            p++;
        }
    }
    printf("%d ", p);
    for (int i = 0; i < 7; i++)
    {
        if (slaveA[i] != nullptr)
        {
            printf("%d ", slaveA[i]->hp);
        }
    }
    printf("\n");

    printf("%d\n", heroB.hp);
    p = 0;
    for (int i = 0; i < 7; i++)
    {
        if (slaveB[i] != nullptr)
        {
            p++;
        }
    }
    printf("%d ", p);
    for (int i = 0; i < 7; i++)
    {
        if (slaveB[i] != nullptr)
        {
            printf("%d ", slaveB[i]->hp);
        }
    }
    printf("\n");
}

void deleteSlave(int pos, bool isAttacker)
{
    if ((isAttacker && isA) || (!isAttacker && !isA))
    {
        // 向左移动
        for (int i = pos - 1; i < 7 - 1; i++)
        {
            slaveA[i] = slaveA[i + 1];
        }
        // 最右边加一个空位
        slaveA[7 - 1] = nullptr;
    }
    else
    {
        // 向左移动
        for (int i = pos - 1; i < 7 - 1; i++)
        {
            slaveB[i] = slaveB[i + 1];
        }
        // 最右边加一个空位
        slaveB[7 - 1] = nullptr;
    }
}

void insert(int pos, int ap, int hp)
{
    if (isA)
    {
        // 移动右边所有
        for (int i = 6; i > pos - 1; i--)
        {
            slaveA[i] = slaveA[i - 1];
        }
        // 随从插入对应位置
        slaveA[pos - 1] = (role *)malloc(sizeof(role));
        slaveA[pos - 1]->type = SLAVE;
        slaveA[pos - 1]->ap = ap;
        slaveA[pos - 1]->hp = hp;
    }
    else
    {
        // 移动右边所有
        for (int i = 6; i > pos - 1; i--)
        {
            slaveB[i] = slaveB[i - 1];
        }
        // 随从插入对应位置
        slaveB[pos - 1] = (role *)malloc(sizeof(role));
        slaveB[pos - 1]->type = SLAVE;
        slaveB[pos - 1]->ap = ap;
        slaveB[pos - 1]->hp = hp;
    }
}

int main()
{
    // 分配存储空间
    // role *heroA = (role *)malloc(sizeof(role));
    // role *heroB = (role *)malloc(sizeof(role));
    // for (int i = 0; i < 7; i++)
    // {
    //     slaveA[i] = (role *)malloc(sizeof(role));
    //     slaveB[i] = (role *)malloc(sizeof(role));
    //     slaveA[i]->type = slaveB[i]->type = SLAVE;
    // }
    fill(begin(slaveA), end(slaveA), nullptr);
    fill(begin(slaveB), end(slaveB), nullptr);
    // 初始化
    heroA.hp = heroB.hp = 30;
    heroA.ap = heroB.ap = 0;
    heroA.type = heroA.type = HERO;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        if (tmp == "summon")
        {
            int position, attack, health;
            cin >> position >> attack >> health;
            insert(position, attack, health);
        }
        else if (tmp == "attack")
        {
            int damage;
            int attacker, defender;
            cin >> attacker >> defender;
            // 攻击对方英雄
            if (defender == 0)
            {
                if (isA)
                {
                    damage = slaveA[attacker - 1]->ap;
                    slaveA[attacker - 1]->hp -= damage;
                    heroB.hp -= damage;
                    if (slaveA[attacker - 1]->hp <= 0)
                    {
                        deleteSlave(attacker, true);
                    }
                    if (heroB.hp <= 0)
                    {
                        winResult = 1;
                    }
                }
                else
                {
                    damage = slaveB[attacker - 1]->ap;
                    slaveB[attacker - 1]->hp -= damage;
                    heroA.hp -= damage;
                    if (slaveB[attacker - 1]->hp <= 0)
                    {
                        deleteSlave(attacker, true);
                    }
                    if (heroA.hp <= 0)
                    {
                        winResult = -1;
                    }
                }
            }
            // 攻击对方随从
            else
            {
                if (isA)
                {
                    damage = slaveA[attacker - 1]->ap;
                    slaveA[attacker - 1]->hp -= damage;
                    slaveB[defender - 1]->hp -= damage;
                    if (slaveA[attacker - 1]->hp <= 0)
                    {
                        deleteSlave(attacker, true);
                    }
                    if (slaveB[defender - 1]->hp <= 0)
                    {
                        deleteSlave(defender, false);
                    }
                }
                else
                {
                    damage = slaveB[attacker - 1]->ap;
                    slaveB[attacker - 1]->hp -= damage;
                    slaveA[defender - 1]->hp -= damage;
                    if (slaveB[attacker - 1]->hp <= 0)
                    {
                        deleteSlave(attacker, true);
                    }
                    if (slaveA[defender - 1]->hp <= 0)
                    {
                        deleteSlave(defender, false);
                    }
                }
            }
        }
        else
        {
            isA = !isA;
        }
        printRes();
        printf("\n");
    }
    printRes();
    return 0;
}