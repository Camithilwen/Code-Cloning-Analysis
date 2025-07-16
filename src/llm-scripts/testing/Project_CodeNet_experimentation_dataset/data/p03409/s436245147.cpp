#include <bits/stdc++.h>
#define ri register
#define int long long
using namespace std; const int N=210;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,book[N],g[N];
int f[N][N],res;
struct Node { int x,y; }a[N],b[N];
int DFS(int x)
{
    for(ri int i=1;i<=n;i++)
    {
        if(!book[i]&&f[x][i])
        {
            book[i]=1;
            if(g[i]==-1 || DFS(g[i]))
            {
                g[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
signed main()
{
    n=read();
    for(ri int i=1;i<=n;i++) a[i].x=read(), a[i].y=read();
    for(ri int i=1;i<=n;i++) b[i].x=read(), b[i].y=read();
    for(ri int i=1;i<=n;i++)
    for(ri int j=1;j<=n;j++)
    if(a[i].x<b[j].x && a[i].y<b[j].y) f[i][j]=1;
    memset(g,-1,sizeof(g));
    for(ri int i=1;i<=n;i++)
    {
        memset(book,0,sizeof(book));
        if(DFS(i)) res++;
    }
    printf("%lld\n",res);
    return 0;
}