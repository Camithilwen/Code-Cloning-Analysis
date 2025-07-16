#include<bits/stdc++.h>

using namespace std;

inline int read()
{
    char ch=getchar(); int f=1,x=0;
    while (ch<'0' || ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
    while (ch>='0' && ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
    return f*x;
}

int n,m,a,b,c,sum,dis[17][17],v[1<<15],f[1<<15][17];

signed main()
{
    n=read(); m=read();
    const int N=1<<n;
    for (int i=1;i<=m;i++)
    {
        a=read(); b=read();
        sum+=dis[a][b]=dis[b][a]=read();
    }
    for (int i=1;i<N;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (!(i>>j&1)) continue;
            for (int k=0;k<j;k++)
            {
                if (!(i>>k&1)) continue;
                v[i]+=dis[j+1][k+1];
            }
        }
    }
    memset(f,-1,sizeof(f));
    f[1][1]=0;
    for (int i=1;i<N;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (!(i>>j&1) || !~f[i][j+1]) continue;
            for (int k=0;k<n;k++)
            {
                if (i>>k&1 || !dis[j+1][k+1]) continue;
                f[i|(1<<k)][k+1]=max(f[i|(1<<k)][k+1],f[i][j+1]+dis[j+1][k+1]);
            }
            int tot=((N-1)^i)|(1<<j);
            for (int k=tot;k;k=(k-1)&tot)
            {
                if (!(k>>j&1)) continue;
                f[i|k][j+1]=max(f[i|k][j+1],f[i][j+1]+v[k]);
            }
        }
    }
    return !printf("%d\n",sum-f[N-1][n]);
}