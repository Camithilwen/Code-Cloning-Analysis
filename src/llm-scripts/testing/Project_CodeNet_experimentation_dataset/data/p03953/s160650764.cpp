#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+7;
LL jmp,a,k,n,m,x[N],y[N],p[N],g[N],siz[N],tot,cnt,sum;
bitset <N> vis;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]),p[i]=i;
	for(int i=1;i<=n;i++)y[i]=x[i]-x[i-1];
	scanf("%lld%lld",&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&a);
		swap(p[a],p[a+1]);
	}
	for(int i=1;i<=n;i++)if(!vis[i])
	{
		++cnt;int res=i;
		while(!vis[res])
			g[res]=cnt,vis[res]=1,res=p[res],++siz[cnt];
	}
	for(int i=1;i<=n;i++)
	{
		jmp=k%siz[g[i]];
		int res=i;
		if(jmp)while(jmp--)res=p[res];
		sum+=y[res];
		printf("%lld.0\n",sum);
	}
} 