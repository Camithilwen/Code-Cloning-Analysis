#include<bits/stdc++.h>
using namespace std;
int n;
int D1,D2;
int get(int x,int y){return x*(n*2)+y;}
struct data{
    int to,nxt;
};
struct Graph{
    data mp[20000200];
    int head[500500],cnt;
    void link(int x,int y)
    {
        mp[++cnt].to=y;
        mp[cnt].nxt=head[x];
        head[x]=cnt;
    }
    int fl[2020][2],tf;
    int c[500500];
    void dfs(int x,int d)
    {
        c[x]=d;
        for(int i=head[x];i;i=mp[i].nxt)
            if(c[mp[i].to]==-1)
                dfs(mp[i].to,d^1);
    }
    void build(int D)
    {
        for(int i=0,j;i*i<=D;++i)
        {
            j=sqrt(D-i*i);
            if(i*i+j*j!=D)continue;
            fl[++tf][0]=i;fl[tf][1]=j;
            fl[++tf][0]=i;fl[tf][1]=-j;
            fl[++tf][0]=-i;fl[tf][1]=j;
            fl[++tf][0]=-i;fl[tf][1]=-j;
        }
        int u,x,y;
        for(int i=0;i<n*2;++i)
            for(int j=0;j<n*2;++j)
            {
                u=get(i,j);
                for(int p=1;p<=tf;++p)
                {
                    x=i+fl[p][0];y=j+fl[p][1];
                    if(x<0||x>=n*2||y<0||y>=n*2)continue;
                    link(u,get(x,y));
                }
            }
        memset(c,-1,sizeof(c));
        for(int i=0;i<n*2;++i)
            for(int j=0;j<n*2;++j)
                if(c[get(i,j)]==-1)dfs(get(i,j),0);
    }
}g1,g2;
int cnt[2][2];
int main()
{
    scanf("%d%d%d",&n,&D1,&D2);
    g1.build(D1);
    g2.build(D2);
    int x;
    for(int i=0;i<n*2;++i)
        for(int j=0;j<n*2;++j)
        {
            x=get(i,j);
            cnt[g1.c[x]][g2.c[x]]++;
        }
    int ou=1;
    for(int i=0;i<2&&ou<=n*n;++i)
        for(int j=0;j<2&&ou<=n*n;++j)
        {
            if(cnt[i][j]<n*n)continue;
            for(int p=0;p<n*2&&ou<=n*n;++p)
                for(int q=0;q<n*2&&ou<=n*n;++q)
                {
                    x=get(p,q);
                    if(g1.c[x]==i&&g2.c[x]==j)
                    {
                        ou++;
                        printf("%d %d\n",p,q);
                    }
                }
        }
    return 0;
}
