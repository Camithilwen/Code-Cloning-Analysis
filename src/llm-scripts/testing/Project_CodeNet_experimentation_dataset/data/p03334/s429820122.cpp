#include<bits/stdc++.h>
#define MN 600
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
pair<int,int> q[MN+5];
int n,d,D,s[MN+5][MN+5],vis[MN+5][MN+5],num[4],top;
void Mark(int x,int y,int c,int S)
{
    if(S) s[x][y]|=c;vis[x][y]=1;
    for(int j=1;j<=top;++j)
        for(int dx=-1;dx<=1;dx+=2) for(int dy=-1;dy<=1;dy+=2)
        {
            int nx=x+dx*q[j].first,ny=y+dy*q[j].second;
            if(nx>0&&ny>0&&nx<=n<<1&&ny<=n<<1&&!vis[nx][ny]) Mark(nx,ny,c,S^1);
        }
}
void Solve(int d,int c)
{
    top=0;
    for(int i=0;i*i<=d;++i)
    {
        int j=d-i*i,flag=-1;
        for(int k=0;k*k<=j;++k) if(k*k==j) flag=k;
        if(flag>=0) q[++top]=make_pair(i,flag);
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n<<1;++i) for(int j=1;j<=n<<1;++j) if(!vis[i][j]) Mark(i,j,c,0);
}
int main()
{
    n=read();d=read();D=read();
    Solve(d,1);Solve(D,2);
    for(int i=1;i<=n<<1;++i) for(int j=1;j<=n<<1;++j) ++num[s[i][j]];
    for(int k=0;k<4;++k) if(num[k]>=n*n)
    {
        int left=n*n;
        for(int i=1;i<=n<<1;++i) for(int j=1;j<=n<<1;++j)
            if(s[i][j]==k&&left) --left,printf("%d %d\n",i-1,j-1);
        return 0;
    }
    return 0;
}