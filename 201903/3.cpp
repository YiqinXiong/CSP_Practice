/* 用时 92 min */
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>

struct DISK
{
    int index;
    char block[10005][9]; //最多40KiB=4B*10000
};

int n; //硬盘总数目(n>=2)
const int N = 1005;
int s; //阵列的条带大小（单位：块，每块4Byte）
const int S = 1005;
int l; //现存的硬盘数目
const int L = 1005;
int m; //读取操作的数目
const int M = 1005;

DISK disk[N + 1]; //磁盘阵列
int blk_num;      //阵列总块数

int rd_blk;  //块序号
int rd_s;    //条带序号
int rd_s_in; //条带内序号
int k;       //块内的条带序号
int k_in;    //一行内的序号
int p_disk;  //校验条带所在磁盘序号
int rd_disk; //磁盘序号

char c1, c2;
char buffer[10005 * 8];
int len;

int main()
{
    scanf("%d %d %d", &n, &s, &l);
    for (int i = 0; i < l; i++)
    {
        scanf("%d %s", &disk[i].index, buffer);
        len = strlen(buffer);
        for (int j = 0; j < (len / 8); j++)
        {
            strncpy(disk[i].block[j], buffer + (j * 8), 8);
        }
    }
    blk_num = (len / 8) * l;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &rd_blk);
        if (rd_blk >= blk_num)
        {
            printf("-\n");
        }
        else
        {
            rd_s = rd_blk / s;
            rd_s_in = rd_blk % s;
            k = rd_s / (n - 1);
            k_in = rd_s % (n - 1);
            p_disk = (n - 1) - (k % n);
            rd_disk = (p_disk + 1 + k_in) % l;
            printf("%s\n", disk[rd_disk].block[k * s + rd_s_in]);
        }
    }
    return 0;
}