#include <bits/stdc++.h>
using namespace std;
int col[100005];
vector<int> v[100005];
bool dfs(int node,int c)
{
	if (col[node]!=-1)
	return (col[node]==c);
	col[node]=c;
	bool ok=1;
	for (int u:v[node])
	ok&=dfs(u,!c);
	return ok;
}
int main()
{
	int n,m,c=0,b=0;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(col,-1,sizeof(col));
	int nn=n;
	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		if (v[i].empty())
		{
			ans+=2*nn-1;
			nn--;
			continue;
		}
		if (col[i]==-1)
		{
			c++;
			b+=dfs(i,0);
		}
	}
	printf("%lld",ans+1LL*c*c+1LL*b*b);
}