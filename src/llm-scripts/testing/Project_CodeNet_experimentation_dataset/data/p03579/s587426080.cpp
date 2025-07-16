#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=100005;
int n,m;
int head[MAXN];
struct node
{
    int from;
    int to;
    int next;
}edge[MAXN<<1];
int edge_cnt;
void add_edge(int fr,int to)
{
    edge[++edge_cnt].from=fr;
    edge[edge_cnt].to=to;
    edge[edge_cnt].next=head[fr];
    head[fr]=edge_cnt;
}
int col[MAXN];
bool flag;
void dfs(int x)
{
    for(int i=head[x];i;i=edge[i].next)
    {
        int u=edge[i].to;
        if(col[u]==-1)
        {
            col[u]=col[x]^1;
            dfs(u);
        }
        else if(col[x]==col[u]) flag=1;
    }
}
bool check()
{
    for(int i=1;i<=n;i++) col[i]=-1;
    for(int i=1;i<=n;i++)
    {
        if(col[i]==-1)
        {
            col[i]=0;
            dfs(i);
        }
    }
    return !flag;
}
long long ans;
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        add_edge(u,v),add_edge(v,u);
    }
    if(check()) 
    {
        int temp=0;
        for(int i=1;i<=n;i++) 
        {
            if(col[i]) temp++;
        }
        ans=temp*(n-temp)-m;
    }
    else ans=n*(n-1)/2-m;
    cout<<ans<<endl;
    // system("pause");
    return 0;
}