/*
*   用时 66分
*   得分 100分
*/
#include <cstdio>
#include <iostream>
#include <list>

using namespace std;
const int MAX_X = 2560, MAX_Y = 1440;
int mapp[MAX_X][MAX_Y];

int n,m;

struct window
{
    int x1,x2,y1,y2;
    int id;
    window(int x1,int y1,int x2,int y2,int id):x1(x1),y1(y1),x2(x2),y2(y2),id(id) {}
};

list<window> allWindow;

void clickMouse(int x,int y)
{
    int id = mapp[x][y];
    list<window>::iterator it;
    for(it=allWindow.begin(); it!=allWindow.end(); it++)
    {
        if(it->id==id)
        {
            break;
        }
    }
    if(it==allWindow.end())
    {
        printf("IGNORED\n");
    }
    else
    {
        printf("%d\n",id);
        //splice将it所指元素接合到end之前
        allWindow.splice(allWindow.end(),allWindow,it);
    }
}

void fillMapp()
{
    //先要清除mapp内容
    for(int x=0; x<MAX_X; x++)
    {
        for(int y=0; y<MAX_Y; y++)
        {
            mapp[x][y] = 0;
        }
    }
    //然后填充mapp
    list<window>::iterator it;
    for(it=allWindow.begin(); it!=allWindow.end(); it++)
    {
        for(int x=it->x1; x<=it->x2; x++)
        {
            for(int y=it->y1; y<=it->y2; y++)
            {
                mapp[x][y] = it->id;
            }
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    int x1,x2,y1,y2;
    int x,y;
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        allWindow.push_back(window(x1,y1,x2,y2,i+1));
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&x,&y);
        fillMapp();
        clickMouse(x,y);
    }
    return 0;
}
