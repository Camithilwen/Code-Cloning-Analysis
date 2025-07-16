#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+500;
int fa[N],dep[N],siz[N],stack[N],dfs_cnt,top,nid[N],tag[N<<1],a[N<<1],dfn[N],K,kfa[N],n;
int fst[N],nxt[N],to[N],mm;
void ade(int u,int v){to[++mm]=v,nxt[mm]=fst[u],fst[u]=mm;}
void dfs(int u)
{
    dep[u]=dep[fa[u]]+1;dfn[u]=++dfs_cnt;nid[dfs_cnt]=u;
    siz[u]=1;
    stack[++top]=u;
    if(dep[u]>=K)kfa[u]=stack[dep[u]-K+1];
    for(int i=fst[u];i;i=nxt[i])
    {
        int v=to[i];dfs(v);
        siz[u]+=siz[v];
    }
    --top;
}
void upd(int rot){a[rot]=0,tag[rot]=1;}
void build(int rot,int lt,int rt)
{
    if(lt==rt){a[rot]=nid[lt];return;}
    int mid=(lt+rt)>>1;
    build(rot<<1,lt,mid),build(rot<<1|1,mid+1,rt);
    a[rot]=dep[a[rot<<1]]>dep[a[rot<<1|1]]?a[rot<<1]:a[rot<<1|1];
}
void pushdown(int rot)
{
    if(tag[rot]){upd(rot<<1),upd(rot<<1|1),tag[rot]=0;}
}
void update(int rot,int lt,int rt,int lq,int rq)
{
    if(lt>=lq&&rt<=rq){upd(rot);return;}
    int mid=(lt+rt)>>1;pushdown(rot);
    if(lq<=mid)update(rot<<1,lt,mid,lq,rq);
    if(rq>mid)update(rot<<1|1,mid+1,rt,lq,rq);
    a[rot]=dep[a[rot<<1]]>dep[a[rot<<1|1]]?a[rot<<1]:a[rot<<1|1];   
}
int main()
{
    scanf("%d%d",&n,&K);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",fa+i);
        if(i!=1)ade(fa[i],i);
    }
    if(K==1)
    {
        int ans=0;
        for(int i=1;i<=n;i++)if(fa[i]!=1)++ans;
        cout<<ans<<endl;
        return 0;
    }
    int ans=0;if(fa[1]!=1)++ans;
    dfs(1);
    build(1,1,n);
    while(dep[a[1]]>K+1)
    {
        ++ans;int u=kfa[a[1]];
        update(1,1,n,dfn[u],dfn[u]+siz[u]-1);
    }
    cout<<ans<<endl;
}