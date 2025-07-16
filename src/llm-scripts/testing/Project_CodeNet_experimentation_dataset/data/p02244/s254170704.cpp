#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int vis[10],ans[10],vis1[10];
int a[100],b[100],k=0;
char mp[10][10];
struct note
{
    int x,y;
} l[1000];
int check(int x,int y)
{
    for(int i=0; i<k; i++)
    {
        if(l[i].x==x||l[i].y==y||abs(x-l[i].x)==abs(y-l[i].y))
            return 0;
    }
    return 1;
}
void pri()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            mp[i][j]='.';
    }
    for(int i=0; i<k; i++)
        mp[l[i].x][l[i].y]='Q';
    for(int i=1; i<9; i++)
    {
        for(int j=1; j<9; j++)
            printf("%c",mp[i][j]);
        printf("\n");
    }
}
void dfs(int x)
{
    if(x>8)
    {
        pri();
        return;
    }
    else if(vis[x]==0)
    {
        for(int j=1; j<=8; j++)
        {
            if(vis1[j]==0&&check(x,j))
            {
                l[k].x=x;
                l[k++].y=j;
                vis1[j]=1;
                dfs(x+1);
                vis1[j]=0;
                k--;
            }
        }
    }
    else
        dfs(x+1);
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(vis,0,sizeof(vis));
        memset(vis1,0,sizeof(vis1));
        k=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            vis[a[i]+1]=1;
            vis1[b[i]+1]=1;
            l[k].x=a[i]+1;
            l[k++].y=b[i]+1;
        }
        dfs(1);
    }
    return 0;
}

