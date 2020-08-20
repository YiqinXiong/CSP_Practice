/* 用时 140 min */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int m, n; //m宽n高
int p, q;
int len;
const int N = 1085;
const int M = 1925;

int colors[M][N][3] = {0};
char temp[2020];

void printRes(const char *str)
{
    int i;
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        printf("\\x%02X", str[i]);
    }
}

int main()
{
    scanf("%d %d", &m, &n);
    scanf("%d %d", &p, &q);
    string buf;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> buf;
            if (buf.length() == 2)
            {
                if (buf[1] >= '0' && buf[1] <= '9')
                {
                    colors[x][y][0] = (buf[1] - '0') * 17;
                    colors[x][y][1] = colors[x][y][2] = colors[x][y][0];
                }
                else
                {
                    colors[x][y][0] = (buf[1] - 'a' + 10) * 17;
                    colors[x][y][1] = colors[x][y][2] = colors[x][y][0];
                }
            }
            else if (buf.length() == 4)
            {
                for (int i = 1; i <= 3; i++)
                {
                    if (buf[i] >= '0' && buf[i] <= '9')
                    {
                        colors[x][y][i - 1] = (buf[i] - '0') * 17;
                    }
                    else
                    {
                        colors[x][y][i - 1] = (buf[i] - 'a' + 10) * 17;
                    }
                }
            }
            else
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        if (buf[1 + i * 2 + j] >= '0' && buf[1 + i * 2 + j] <= '9')
                        {
                            if (j == 0)
                                colors[x][y][i] = (buf[1 + i * 2 + j] - '0') * 16;
                            else
                                colors[x][y][i] += buf[1 + i * 2 + j] - '0';
                        }
                        else
                        {
                            if (j == 0)
                                colors[x][y][i] = (buf[1 + i * 2 + j] - 'a' + 10) * 16;
                            else
                                colors[x][y][i] += buf[1 + i * 2 + j] - 'a' + 10;
                        }
                    }
                }
            }
        }
    }
    int r, g, b;
    int R, G, B;
    int size = p * q;
    for (int y = 0; y < n / q; y++)
    {
        r = g = b = 0;
        for (int x = 0; x < m / p; x++)
        {
            //每进行一小块像素计算时，都需要把像素R,G,B重置
            R = G = B = 0;
            //计算每一小块的像素
            for (int k = y * q; k < y * q + q; k++)
            {
                for (int h = x * p; h < x * p + p; h++)
                {
                    R += colors[h][k][0];
                    G += colors[h][k][1];
                    B += colors[h][k][2];
                }
            }
            //对每一小块的像素去平均准，并转换为字符串形式
            R /= size;
            G /= size;
            B /= size;
            //将计算的像素平均值与r,g,b或者默认值0,0,0比较来输出对应数据格式
            if (!(R == r && G == g && B == b))
            {
                if (R == 0 && G == 0 && B == 0)
                {
                    printRes("\033[0m");
                    // cout << "恢复默认";
                }
                else
                {
                    // sprintf(temp, "\033[48;2;%d;%d;%dm", r, g, b);
                    sprintf(temp, "\033[48;2;%d;%d;%dm", R, G, B);
                    printRes(temp);
                    // cout << "打印颜色R:" << R << "G:" << G << "B:" << B;
                }
            }
            printRes(" ");
            // cout << "打印空格";
            r = R;
            g = G;
            b = B;
            //在每行结尾处，如果终端颜色不是默认值，应该重置终端的颜色状态。
            if (x == m / p - 1 && !(R == 0 && G == 0 && B == 0))
            {
                printRes("\033[0m");
                // cout << "行尾恢复默认";
            }
        }
        printRes("\n");
        // cout << "换行";
    }
    return 0;
}