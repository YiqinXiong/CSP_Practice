#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

const int M = 1925, N = 1085;
int m, n, p, q;

struct color
{
    int r, g, b;
    color(int r, int g, int b) : r(r), g(g), b(b) {}
    color()
    {
        r = g = b = 0;
    }
};

color canvas[N][M];
color block[N][M];

void getColor(color &c, string &s)
{
    s = s.substr(1);
    int len = s.length();
    string temp;
    switch (len)
    {
    case 1:
        s.append(1, s[0]);
        c.r = c.g = c.b = stoi(s, nullptr, 16);
        break;
    case 3:
        temp = "";
        temp.append(2, s[0]);
        c.r = stoi(temp, nullptr, 16);
        temp = "";
        temp.append(2, s[1]);
        c.g = stoi(temp, nullptr, 16);
        temp = "";
        temp.append(2, s[2]);
        c.b = stoi(temp, nullptr, 16);
        break;
    case 6:
        c.r = stoi(s.substr(0, 2), nullptr, 16);
        c.g = stoi(s.substr(2, 2), nullptr, 16);
        c.b = stoi(s.substr(4, 2), nullptr, 16);
        break;
    default:
        break;
    }
}

void printHex(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        printf("\\x%02X", str[i]);
    }
}

//打印控制，mode=0为重置，mode=1为前景色，mode=2为背景色
void printControl(int mode, color &c)
{
    char buf[100];
    string str;
    switch (mode)
    {
    case 0:
        str = "\033[0m";
        break;
    case 1:
        sprintf(buf, "\033[38;2;%d;%d;%dm", c.r, c.g, c.b);
        str = string(buf);
        break;
    case 2:
        sprintf(buf, "\033[48;2;%d;%d;%dm", c.r, c.g, c.b);
        str = string(buf);
        break;
    default:
        break;
    }
    printHex(str);
}

bool isSameColor(color &a, color &b)
{
    return (a.r == b.r) && (a.g == b.g) && (a.b == b.b);
}

int main()
{
    cin >> m >> n;
    cin >> p >> q;
    string colorStr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> colorStr;
            getColor(canvas[i][j], colorStr);
        }
    }
    int newN = n / q;
    int newM = m / p;
    for (int i = 0; i < newN; i++)
    {
        for (int j = 0; j < newM; j++)
        {
            int hBegin, vBegin;
            hBegin = j * p;
            vBegin = i * q;
            ll rSum = 0, gSum = 0, bSum = 0;
            for (int v = vBegin; v < vBegin + q; v++)
            {
                for (int h = hBegin; h < hBegin + p; h++)
                {
                    rSum += canvas[v][h].r;
                    gSum += canvas[v][h].g;
                    bSum += canvas[v][h].b;
                }
            }
            block[i][j].r = rSum / (p * q);
            block[i][j].g = gSum / (p * q);
            block[i][j].b = bSum / (p * q);
        }
    }
    color defaultColor = color(0, 0, 0);
    color lastColor = defaultColor;
    for (int i = 0; i < newN; i++)
    {
        for (int j = 0; j < newM; j++)
        {
            if (isSameColor(lastColor, block[i][j]))
            {
                ;
            }
            else if (isSameColor(defaultColor, block[i][j]))
            {
                printControl(0, defaultColor);
                lastColor = defaultColor;
            }
            else
            {
                printControl(2, block[i][j]);
                lastColor = block[i][j];
            }
            printHex(" ");
            // cout << endl;
        }
        if (!isSameColor(lastColor, defaultColor))
        {
            printControl(0, defaultColor);
            lastColor = defaultColor;
        }
        printHex("\n");
        // cout << "  endl" << endl;
    }
    // printHex("\033[48;2;1;2;3m \033[0m\n");
    return 0;
}

/*
1 1
1 1
#010203

2 2
1 1
#0
#222
#2
#333333

2 2
1 2
#111111
#0
#000000
#111
*/