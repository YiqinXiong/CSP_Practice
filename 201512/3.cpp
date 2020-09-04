/* 
*   用时 1小时26分
*   得分 90分
*   思路：广度优先搜索BFS
*/

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int x;
    int y;
    node(int x, int y) : x(x), y(y) {}
};

const int M = 105, N = 105;
char canvas[M][N];
bool visit[M][N];
int m, n, q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

//初始化visit数组
void initVisit()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visit[i][j] = false;
        }
    }
}

//打印画布
void printCanvas()
{
    for (int y = n-1; y >= 0; y--)
    {
        for (int x = 0; x < m; x++)
        {
            cout << canvas[x][y];
        }
        cout << endl;
    }
}

//判断是否可以填充
bool canFill(int x, int y)
{
    //超过画布边界
    if (x < 0 || x > m || y < 0 || y > n)
    {
        return false;
    }
    //碰到线段
    char c = canvas[x][y];
    if (c == '-' || c == '|' || c == '+')
    {
        return false;
    }
    return true;
}

//广度优先搜索填充空白
void bfs(int startX, int startY, char c)
{
    initVisit();
    queue<node> que;
    que.push(node(startX, startY));
    visit[startX][startY] = true;
    while (!que.empty())
    {
        //队头出队，画在画布上
        node cur = que.front();
        que.pop();
        canvas[cur.x][cur.y] = c;
        //上下左右尝试入队
        for (int i = 0; i < 4; i++)
        {
            int x = cur.x + dx[i];
            int y = cur.y + dy[i];
            if (canFill(x, y) && !visit[x][y])
            {
                que.push(node(x, y));
                visit[x][y] = true;
            }
        }
    }
}

//画线
void drawLine(int x1, int y1, int x2, int y2)
{
    int sx, lx;
    int sy, ly;
    if (x1 > x2)
    {
        sx = x2;
        lx = x1;
    }
    else
    {
        sx = x1;
        lx = x2;
    }
    if (y1 > y2)
    {
        sy = y2;
        ly = y1;
    }
    else
    {
        sy = y1;
        ly = y2;
    }
    if (sx == lx)
    {
        for (int y = sy; y <= ly; y++)
        {
            if (canvas[sx][y] == '-')
            {
                canvas[sx][y] = '+';
            }else{
                canvas[sx][y] = '|';
            }
        }
    }
    else
    {
        for (int x = sx; x <= lx; x++)
        {
            if (canvas[x][sy] == '|')
            {
                canvas[x][sy] = '+';
            }else{
                canvas[x][sy] = '-';
            }
        }
    }
}

int main()
{
    cin >> m >> n >> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            canvas[i][j] = '.';
        }
    }
    for (int i = 0; i < q; i++)
    {
        int opt;
        cin >> opt;
        //画线段操作
        if (opt == 0)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            drawLine(x1, y1, x2, y2);
        }
        //填充操作
        else
        {
            int x, y;
            char c;
            cin >> x >> y >> c;
            bfs(x, y, c);
        }
    }
    printCanvas();
    return 0;
}