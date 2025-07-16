#include<bits/stdc++.h>
#define re register
using namespace std;
template <typename T>inline void read(T &x)
{
	x=0;int f=1;char c=getchar();
	for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
const int maxn=1e5+5;
struct edge
{
	int to,nxt;
}e[maxn<<1];
int n,k,head[maxn],cnt;
int a[maxn],rem[maxn],ans;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int u)
{
	for(re int i=head[u];i!=0;i=e[i].nxt)
	{
		int v=e[i].to;
		dfs(v);
		if(rem[v]==k-1&&u!=1) 
		{
			ans++;
			rem[v]=-1;
		}
		rem[u]=max(rem[u],rem[v]+1);
	}
}
int main()
{
	read(n),read(k);
	for(re int i=1;i<=n;++i)
		read(a[i]);
	if(a[1]!=1) ++ans;
	for(re int i=2;i<=n;++i)
		add(a[i],i);
	dfs(1);
	printf("%d",ans);
	return 0;
}