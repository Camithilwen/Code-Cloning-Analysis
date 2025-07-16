#include <cstdio>
#include <cmath>
using namespace std;
const int N=1e5+5;
const int E=N<<1;
const int mod=1e9+7;
int n,u,v;
int a[N],b[N];
int d1[N],d2[N];
int h[N],nx[E],to[E];
int ec;
int ans;
void ae(int u,int v)
{
	ec++;
	nx[ec]=h[u];
	to[ec]=v;
	h[u]=ec;
}
void dfs(int u,int f,int d[])
{
	d[u]=d[f]+1;
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=f)
			dfs(to[i],u,d);
}
int main()
{
	scanf("%d%d%d",&n,&u,&v);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		ae(a[i],b[i]);
		ae(b[i],a[i]);
	}
	dfs(u,0,d1);
	dfs(v,0,d2);
	for (int i=1;i<=n;i++)
		if (d1[i]<d2[i]&&d2[i]-2>ans)
			ans=d2[i]-2;
	printf("%d\n",ans);
	return 0;
}