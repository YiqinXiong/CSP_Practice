/*用时1小时20分，得分60*/
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int SS = 0, RR = 1;

struct mission
{
    int type;
    int pid;
    int target;
    mission(int type, int pid, int target) : type(type), pid(pid), target(target) {}
};

bool canExec(mission &a, mission &b)
{
    if (a.type == b.type)
        return false;
    return (a.target == b.pid) && (b.target == a.pid);
}

int main()
{
    int T, n;
    cin >> T >> n;
    getchar();
    for (int i = 0; i < T; i++)
    {
        vector<queue<mission>> code;
        //每一行
        for (int pid = 0; pid < n; pid++)
        {
            string line;
            getline(cin, line);
            stringstream ss(line);
            string str;
            queue<mission> process;
            while (getline(ss, str, ' '))
            {
                int type = str[0] == 'S' ? SS : RR;
                int target = stoi(str.substr(1));
                process.push(mission(type, pid, target));
            }
            code.push_back(process);
        }
        while (1)
        {
            vector<mission> getTop;
            for (int pid = 0; pid < n; pid++)
            {
                if (!code[pid].empty())
                {
                    getTop.push_back(code[pid].front());
                }
            }
            int len = getTop.size();
            //len=0的情况,无死锁
            if (len == 0)
            {
                cout << 0 << endl;
                break;
            }
            //len=1的情况,必死锁
            if (len == 1)
            {
                cout << 1 << endl;
                break;
            }
            //len>=2的情况
            //前提是len>=2。两两遍历所有进程
            bool lockInThisTerm = true;
            for (int p1 = 0; p1 < len - 1; p1++)
            {
                for (int p2 = p1 + 1; p2 < len; p2++)
                {
                    if (canExec(getTop[p1], getTop[p2]))
                    {
                        code[getTop[p1].pid].pop();
                        code[getTop[p2].pid].pop();
                        lockInThisTerm = false;
                    }
                }
            }
            //若这轮锁住，则必死锁
            if (lockInThisTerm)
            {
                cout << 1 << endl;
                break;
            }
        }
    }
    return 0;
}

/*
3 2
R1 S1
S0 R0
R1 S1
R0 S0
R1 R1 R1 R1 S1 S1 S1 S1
S0 S0 S0 S0 R0 R0 R0 R0

2 3
R1 S1
R2 S0 R0 S2
S1 R1
R1
R2 S0 R0
S1 R1
*/