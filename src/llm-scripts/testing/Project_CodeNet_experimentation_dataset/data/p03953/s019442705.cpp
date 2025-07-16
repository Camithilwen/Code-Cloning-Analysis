#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
using namespace std;
const int N=1e5+100;
int n,m,k,a[N],b[N],f[N],c[N];
int fa[N][64],sum[N];
signed main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&f[i]);
	scanf("%lld%lld",&m,&k);
	for (int i=1;i<=m;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) b[i]=i;
	for (int i=1;i<=m;i++) swap(b[a[i]],b[a[i]+1]);
	for (int i=1;i<=n;i++) fa[i][0]=b[i];
	for (int j=1;j<=62;j++)
	{
		for (int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	}
	for (int i=1;i<=n;i++)
	{
		int cnt=k,x=i;
		for (int j=62;j>=0;j--)
		{
			if (cnt>=(1ll<<j))
			{
				cnt-=(1ll<<j);
				x=fa[x][j];
			}
		}
		if (x==1) c[i]=f[x];
		else c[i]=f[x]-f[x-1];
	}
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+c[i];
	for (int i=1;i<=n;i++)
	{
		double ans=sum[i];
		printf("%.12lf\n",ans);
	}
}