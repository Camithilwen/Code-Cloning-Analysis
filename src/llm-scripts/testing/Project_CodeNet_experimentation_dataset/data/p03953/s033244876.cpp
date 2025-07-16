#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100010
using namespace std;
typedef long long ll;
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
ll K;
int a[maxn],d[maxn],vis[maxn],id[maxn];
int p[maxn],top;
ll ans[maxn];
int main()
{
    n=read();
    for(int i=1;i<=n;i++)  a[i]=read();
    for(int i=1;i<=n;i++)  d[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++)  id[i]=i;
    m=read();K=read();
    for(int i=1;i<=m;i++)
    {
        int x=read();
        swap(id[x],id[x+1]);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            top=0;
            for(int j=i;!vis[j];j=id[j])  vis[j]=1,p[++top]=j;
            for(int j=1;j<=top;j++)  ans[p[j]]=d[p[(K+j-1)%top+1]];
        }
    }
    for(int i=1;i<=n;i++)  ans[i]+=ans[i-1];
    for(int i=1;i<=n;i++)  printf("%lld\n",ans[i]);
    puts("");
    return 0;
}