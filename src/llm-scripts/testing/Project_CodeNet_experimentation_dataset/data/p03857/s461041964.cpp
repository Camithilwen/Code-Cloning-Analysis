#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=100000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define go(u,i) for (register int i=head[u];i;i=sq[i].nxt)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define eps 1e-8
struct node{int to,nxt;}sq[400200];
int all=0,head[200100],ans[200100];
int n,m1,m2,cnt=0;
pii col[200100];
bool vis[200100];
map<pii,int> mp;

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

void add(int u,int v)
{
	all++;sq[all].to=v;sq[all].nxt=head[u];head[u]=all;
}

void dfs(int u,int op)
{
	if (op==0) col[u].fir=cnt;else col[u].sec=cnt;
	vis[u]=1;
	go(u,i)
	{
		int v=sq[i].to;
		if (!vis[v]) dfs(v,op);
	}
}

void init(int m,int op)
{
	all=cnt=0;
	memset(head,0,sizeof(head));
	memset(vis,0,sizeof(vis));
	rep(i,1,m)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	rep(i,1,n)
		if (!vis[i]) {cnt++;dfs(i,op);}
}

int main()
{
	n=read();m1=read();m2=read();
	init(m1,0);init(m2,1);
	rep(i,1,n) mp[col[i]]++;
	rep(i,1,n) ans[i]=mp[col[i]];
	rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}
