#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
int n,L,Q,x[maxn],f[maxn][18],g[maxn][18];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	scanf("%d",&L);
	for(int i=1;i<=n;i++)
		f[i][0]=upper_bound(x+1,x+n+1,x[i]+L)-x-1;
	for(int j=1;j<=17;j++)
		for(int i=n;i;i--)
			f[i][j]=f[f[i][j-1]][j-1];
	for(int i=1;i<=n;i++)
		g[i][0]=lower_bound(x+1,x+n+1,x[i]-L)-x;
	for(int j=1;j<=17;j++)
		for(int i=1;i<=n;i++)
			g[i][j]=g[g[i][j-1]][j-1];
	int a,b;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&a,&b);
		int ans=0;
		if(a<b)
		{
			for(int i=17;i>=0;i--)
				if(f[a][i]<b) a=f[a][i],ans+=(1<<i);
		}
		else
		{
			for(int i=17;i>=0;i--)
				if(g[a][i]>b) a=g[a][i],ans+=(1<<i);
		}
		printf("%d\n",ans+1);
	}
	return 0;
}