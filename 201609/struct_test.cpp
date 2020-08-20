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

int n;

struct role
{
    int hp;       //生命值
    int ap = 999; //攻击力
    role *next;
    role() : hp(), ap(), next() {}
    role(int h, int a, role *ptr) : hp(h), ap(a), next(ptr) {}
    void init(int h, int a)
    {
        this->hp = h;
        this->ap = a;
        this->next = this;
    }
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
    role r1, r2, r3;
    // 初始化
    // r1 = role();
    cout << &r1 << " " << r1.hp << " " << r1.ap << " " << r1.next << endl;
    r2 = role(100, 666, nullptr);
    cout << &r2 << " " << r2.hp << " " << r2.ap << " " << r2.next << endl;
    r3.init(200, 985);
    cout << &r3 << " " << r3.hp << " " << r3.ap << " " << r3.next << endl;
    // cout << &r4 << " " << r4.hp << " " << r4.ap << " " << r4.next << endl;
    return 0;
}