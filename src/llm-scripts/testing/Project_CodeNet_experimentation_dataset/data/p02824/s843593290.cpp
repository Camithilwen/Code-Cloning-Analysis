#include<bits/stdc++.h>
using namespace std;
int n,m,v,p,u,ans;
long long g,a[200005],sy,d,s[200005];
int main() 
{
	scanf("%d%d%d%d",&n,&m,&v,&p);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	g=a[n-p+1];
	for (int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	ans=p;
	for (int i=1;i<=n-p;i++)
	{
		if (g>a[i]+m)
			continue;
		sy=(long long)m*(long long)(v-1);
		d=(long long)m*(long long)(n-1);
		d-=s[n-p+1]-s[i-1]-(long long)(n-p-i+2)*a[i];
		if (sy<=d)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}