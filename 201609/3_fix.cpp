/* 
*   用时 1小时34分
*   得分 100分
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int N = 1005;

int n;

struct role
{
    int hp; //生命值
    int ap; //攻击力
    role(int h, int a) : hp(h), ap(a) {}
    bool isDead()
    {
        return this->hp <= 0;
    }
    void getDamage(int damage)
    {
        this->hp -= damage;
    }
};

vector<role> slave[2];
int pid = 0;

void printRes()
{
    if (slave[0][0].hp > 0 && slave[1][0].hp > 0)
        cout << 0 << endl;
    else if (slave[0][0].hp > 0)
        cout << 1 << endl;
    else
        cout << -1 << endl;
    for (int i = 0; i < 2; i++)
    {
        printf("%d\n", slave[i][0].hp);
        printf("%lu ", slave[i].size() - 1);
        vector<role>::iterator it;
        for (it = slave[i].begin() + 1; it != slave[i].end(); it++)
        {
            printf("%d ", it->hp);
        }
        printf("\n");
    }
}

int main()
{
    // 初始化
    slave[0].push_back(role(30, 0));
    slave[1].push_back(role(30, 0));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        if (tmp == "summon")
        {
            int position, attack, health;
            cin >> position >> attack >> health;
            slave[pid].insert(slave[pid].begin() + position, role(health, attack));
        }
        else if (tmp == "attack")
        {
            int attacker, defender;
            cin >> attacker >> defender;
            slave[pid][attacker].getDamage(slave[!pid][defender].ap);
            slave[!pid][defender].getDamage(slave[pid][attacker].ap);
            if (slave[pid][attacker].isDead())
            {
                slave[pid].erase(slave[pid].begin() + attacker);
            }
            if (slave[!pid][defender].isDead() && defender != 0)
            {
                slave[!pid].erase(slave[!pid].begin() + defender);
            }
        }
        else if (tmp == "end")
        {
            pid = !pid;
        }
    }
    printRes();
    return 0;
}