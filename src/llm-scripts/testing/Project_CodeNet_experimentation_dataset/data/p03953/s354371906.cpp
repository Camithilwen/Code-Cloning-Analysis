#include<bits/stdc++.h>
using namespace std;
int n,m,pos[100010],p[100010],to[100010],w[100010],ans[100010];
long long u[100010],k;
bool v[100010];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int o[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&pos[i]);
	for(int i=1;i<n;++i) p[i]=i;
	scanf("%d",&m); scanf("%lld",&k);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		swap(p[x-1],p[x]);
	}
	for(int i=1;i<n;i++) to[p[i]]=i;
	for(int i=1;i<n;i++)
	{
		if(v[i]) continue;
		v[i]=1;
		int cnt=1; o[cnt]=i;
		for(int j=to[i];j!=i;j=to[j])
		{
				v[j]=1;
				o[++cnt]=j;
		}
		int yy=k%cnt;
		for(int j=1;j<=cnt;j++) {
			ans[o[j]]=o[(j+yy)>cnt?j+yy-cnt:j+yy];
		}
	}
	for(int i=1;i<n;++i) w[ans[i]]=i;
	u[n]=pos[n];
	
	for(int i=n-1;i>=1;i--) u[i]=u[i+1]-pos[w[i]+1]+pos[w[i]];
	for(int i=1;i<=n;i++) printf("%lld\n",u[i]);
	return 0;
}