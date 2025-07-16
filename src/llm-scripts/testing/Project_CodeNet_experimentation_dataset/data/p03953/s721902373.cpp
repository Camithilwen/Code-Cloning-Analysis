#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define llong long long
int n,m;
int pos[200200];
int nxt[200200];
llong K;

bool vis[200200];
int sta[200200],top;

double ans[100100];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&pos[i]),nxt[i]=i;
    for(int i=n;i;--i)pos[i]-=pos[i-1];
    scanf("%d%lld",&m,&K);
    int xx;
    for(int i=1;i<=m;++i)
        scanf("%d",&xx),swap(nxt[xx],nxt[xx+1]);
    for(int i=1;i<=n;++i)
        if(!vis[i])
        {
            xx=i; top=0;
            while(!vis[xx]) vis[xx]=1,sta[top++]=xx,xx=nxt[xx];
            for(int j=0;j<top;++j)
                ans[sta[j]]=pos[sta[(K+j)%top]];
        }
    for(int i=1;i<=n;++i)
    {
        ans[i]+=ans[i-1];
        printf("%.1lf ",ans[i]);
    }
    puts("");
    return 0;
}
