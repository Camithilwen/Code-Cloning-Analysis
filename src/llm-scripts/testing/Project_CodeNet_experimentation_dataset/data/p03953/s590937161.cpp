#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5e5;
int x[N],opt[N],id[N],p[N],vis[N],n,m,tmp[N];
long long s[N],K;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",x+i),id[i]=i;
    for(int i=n;i>=1;i--)x[i]-=x[i-1];
    scanf("%d%lld",&m,&K);
    for(int i=1;i<=m;i++)scanf("%d",opt+i),swap(id[opt[i]],id[opt[i]+1]);
    for(int i=1;i<=n;i++)p[id[i]]=i;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        int u=i,len=0;tmp[0]=u;vis[u]=1;
        while(p[u]!=i)u=p[u],tmp[++len]=u,vis[u]=1;
        ++len;
        for(int i=0;i<len;i++)p[tmp[i]]=tmp[(i+K)%len];
    }
    for(int i=1;i<=n;i++)id[p[i]]=i;
    
    for(int i=1;i<=n;i++)s[i]=s[i-1]+x[id[i]],printf("%.1lf\n",(double)s[i]);
}