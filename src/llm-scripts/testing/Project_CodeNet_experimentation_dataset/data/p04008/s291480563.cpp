#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define maxn 100010
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,K,ans;
int head[maxn],nxt[maxn],to[maxn],tot;
void add(int u,int v)
{
    tot++;
    nxt[tot]=head[u];
    head[u]=tot;
    to[tot]=v;
}
int dep[maxn];
void dfs(int x,int las)
{
    for(int i=head[x];i;i=nxt[i])
    {
        dfs(to[i],x);
        dep[x]=max(dep[x],dep[to[i]]);
    }
    dep[x]++;
    if(dep[x]==K&&las!=1)  ans++,dep[x]=0;
}
int main()
{
    n=read();K=read();
    for(int i=1;i<=n;i++)
    {
        int x=read();
        if(i==1)  ans+=(x!=1);
        else{
            add(x,i);
        }
    }
    for(int i=head[1];i;i=nxt[i])  dfs(to[i],1);
    cout<<ans<<endl;
    return 0;
}