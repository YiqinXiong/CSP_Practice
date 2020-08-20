/* 耗时 120 min，得分60*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;
int n;
const int N = 105;
char buf[20];

struct IP
{
    unsigned int ip;
    int len;
};

IP iptemp;
IP iplist[N];

bool cmp(IP a, IP b)
{
    if (a.ip == b.ip)
    {
        return a.len < b.len;
    }
    else
    {
        return a.ip < b.ip;
    }
}

void format(char *buf)
{
    char *pos1;
    char *pos2;
    int count = 0;
    char lenstr[4];
    if ((pos1 = strchr(buf, '/')) != NULL)
    {
        strcpy(lenstr, pos1);
        *pos1 = '\0';
        pos2 = buf;
        while ((pos2 = strchr(pos2, '.')) != NULL)
        {
            pos2++;
            count++;
        }
        for (int i = 0; i < (3 - count); i++)
        {
            strcat(buf, ".0");
        }
        strcat(buf, lenstr);
    }
    else
    {
        pos2 = buf;
        while ((pos2 = strchr(pos2, '.')) != NULL)
        {
            pos2++;
            count++;
        }
        for (int i = 0; i < (3 - count); i++)
        {
            strcat(buf, ".0");
        }
        sprintf(lenstr, "/%d", (count + 1) * 8);
        strcat(buf, lenstr);
    }
}

IP *makeIP(char *buf)
{
    static IP iptemp;
    iptemp.ip = 0; //初始化
    char *pos1;
    char *pos2;
    int offset;
    int tempint;
    int count = 3;
    char strint[4];
    pos1 = pos2 = buf;
    //处理1.2.3.4/32的前3个'.'
    while ((pos1 = strchr(pos2, '.')) != NULL)
    {
        offset = pos1 - pos2;
        strncpy(strint, pos2, offset);
        strint[offset] = '\0';
        tempint = atoi(strint);
        tempint <<= (8 * count);
        iptemp.ip |= (unsigned int)tempint;
        pos1++;
        pos2 = pos1;
        count--;
    }
    //处理1.2.3.4/32的最后一个'/'
    pos1 = strchr(pos2, '/');
    offset = pos1 - pos2;
    strncpy(strint, pos2, pos1 - pos2);
    strint[offset] = '\0';
    tempint = atoi(strint);
    iptemp.ip |= (unsigned int)tempint;
    pos1++;
    //写入前缀长度
    iptemp.len = atoi(pos1);
    return &iptemp;
}

int main()
{
    IP *cur_ip;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", buf);
        format(buf);
        // printf("%s\n", buf);
        cur_ip = makeIP(buf);
        iplist[i].ip = cur_ip->ip;
        iplist[i].len = cur_ip->len;
    }
    sort(iplist, iplist + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cur_ip = iplist + i;
        printf("%d.%d.%d.%d/%d\n",
               (cur_ip->ip & 0xff000000) >> 24,
               (cur_ip->ip & 0xff0000) >> 16,
               (cur_ip->ip & 0xff00) >> 8,
               cur_ip->ip & 0xff,
               cur_ip->len);
    }
    return 0;
}