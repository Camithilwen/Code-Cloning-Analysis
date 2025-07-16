#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXN 200006
using namespace std;
int u,v,deep[MAXN],n,m,sum[MAXN],vis[MAXN],ok;
long long a,q,p,ans;
vector<int> road[MAXN];
void DFS(int x,int father)
{
	vis[x]=1;
	sum[x]=1;
	deep[x]=deep[father]+1;
	for(int i=0;i<(int)road[x].size();i++)
	{
		int nex=road[x][i];
		if(nex==father) continue;
		if(vis[nex])
		{
			if((deep[nex]+deep[x])%2==0) ok=0;
			continue;
		}
		DFS(nex,x);
		sum[x]+=sum[nex];
	}
}
int main()
{
	//freopen("squared.in","r",stdin);
	//freopen("squared.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		road[u].push_back(v);
		road[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		ok=1;
		DFS(i,0);
		if(sum[i]==1) a++;
		else 
		{
			if(ok==0) p++;
			else q++;
		}
	}
	ans=a*a+2*a*(n-a)+p*p+p*q*2+2*q*q;
	printf("%lld",ans);
}