#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int N=1e5+5;
int a[N],b[N],d[N],p[N],ans[N],vis[N],st[N],tt=0,n,m;ll k;
void dfs(int u){if(!vis[u])vis[u]=1,st[++tt]=u,dfs(p[u]);}
main()
{
    scanf("%lld",&n);for(int i=1;i<=n;i++)scanf("%lld",&a[i]),d[i]=a[i]-a[i-1];
    scanf("%lld%lld",&m,&k);
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=m;i++)scanf("%lld",&b[i]),swap(p[b[i]],p[b[i]+1]);
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        tt=0;dfs(i);
        for(int j=1;j<=tt;j++)ans[st[j]]=d[st[(j+k-1)%tt+1]];
    }
    for(int i=1;i<=n;i++)printf("%lld.0\n",ans[i]+=ans[i-1]);
}
