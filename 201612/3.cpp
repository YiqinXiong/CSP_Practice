/* 
*   用时 2小时26分
*   得分 90分，错误
*   教训 STL容器嵌套时，map的插入和访问不要使用数组形式，插入用insert()，访问用find()
 */
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//角色
struct role
{
    string name;
    map<string, int> privs;
    role(string name, map<string, int> privs) : name(name), privs(privs) {}
};

//用户
struct user
{
    string name;
    vector<role> roles;
    user(string name, vector<role> roles) : name(name), roles(roles) {}
};

int p, r, u, q;
map<string, int> privMap;  //保存所有类型的权限和等级，无等级的为-1
map<string, role> roleMap; //保存所有角色
map<string, user> userMap; //保存所有用户
string rrname;

//返回权限等级，无等级返回-1
int handlePStr(string &pStr)
{
    int pos;
    if ((pos = pStr.find(':')) != string::npos)
    {
        int lev = pStr[pos + 1] - '0';
        pStr = pStr.substr(0, pos);
        return lev;
    }
    else
        return -1;
}

int main()
{
    //P段
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        string pStr;
        cin >> pStr;
        int lev = handlePStr(pStr);
        privMap[pStr] = lev;
    }
    //R段
    cin >> r;
    for (int i = 0; i < r; i++)
    {
        string rname;
        int rnum;
        map<string, int> privs;
        cin >> rname;
        rrname = rname;
        cin >> rnum;
        for (int j = 0; j < rnum; j++)
        {
            string pStr;
            cin >> pStr;
            int lev = handlePStr(pStr);
            privs[pStr] = lev;
        }
        roleMap.insert(pair<string, role>(rname, role(rname, privs)));
    }
    //U段
    cin >> u;
    for (int i = 0; i < u; i++)
    {
        string uname;
        int unum;
        vector<role> roles;
        cin >> uname;
        cin >> unum;
        for (int j = 0; j < unum; j++)
        {
            string rStr;
            cin >> rStr;
            map<string, role>::iterator roleIt = roleMap.find(rStr);
            roles.push_back(roleIt->second);
        }
        userMap.insert(pair<string, user>(uname, user(uname, roles)));
    }
    //Q段
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        bool finded = false; //标记是否找到对应权限
        string uname, pStr;
        cin >> uname >> pStr;
        int lev = handlePStr(pStr);
        map<string, user>::iterator uit = userMap.find(uname);
        map<string, int>::iterator pit = privMap.find(pStr);
        //查有此用户且有此权限
        if (uit != userMap.end() && pit != privMap.end())
        {
            if (lev == -1)
            {
                //分等级权限的不带等级查询
                if (pit->second != -1)
                {
                    int maxLev = -1;
                    vector<role>::iterator rit = uit->second.roles.begin();
                    //遍历所有角色，找对应权限
                    for (; rit != uit->second.roles.end(); rit++)
                    {
                        map<string, int>::iterator ppit;
                        //找到对应权限，取最大的等级
                        if ((ppit = rit->privs.find(pStr)) != rit->privs.end())
                        {
                            finded = true;
                            if (ppit->second > maxLev)
                                maxLev = ppit->second;
                        }
                    }
                    if (finded)
                        cout << maxLev << endl;
                    else
                        cout << "false" << endl;
                }
                //不分等级权限查询
                else
                {
                    vector<role>::iterator rit = uit->second.roles.begin();
                    //遍历所有角色，找对应权限
                    for (; rit != uit->second.roles.end(); rit++)
                    {
                        map<string, int>::iterator ppit;
                        //找到对应权限
                        if ((ppit = rit->privs.find(pStr)) != rit->privs.end())
                        {
                            finded = true;
                            break;
                        }
                    }
                    if (finded)
                        cout << "true" << endl;
                    else
                        cout << "false" << endl;
                }
            }
            //分等级权限的带等级查询
            else
            {
                vector<role>::iterator rit = uit->second.roles.begin();
                //遍历所有角色，找对应权限
                for (; rit != uit->second.roles.end(); rit++)
                {
                    map<string, int>::iterator ppit;
                    //找到对应满足条件权限
                    if ((ppit = rit->privs.find(pStr)) != rit->privs.end())
                    {
                        if (ppit->second >= lev)
                            finded = true;
                    }
                }
                if (finded)
                    cout << "true" << endl;
                else
                    cout << "false" << endl;
            }
        }
        else
            cout << "false" << endl;
    }
    return 0;
}