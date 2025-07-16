#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 100010
#define int long long
using namespace std;
int num[N];
signed main()
{
	int n,m,v,p;
	scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	sort(num+1,num+n+1);
	reverse(num+1,num+n+1);
	int sum=0,ans=p;
	for(int i=p+1;i<=n && num[i]+m>=num[p];i++)
	{
		int d=n-(i-p);
		if(v<=d) ++ans;
		else
		{
			int res=(1ll*(v-d)*m-sum-1)/(i-p)+1;
			if(num[p]+res<=num[i]+m) ++ans;
		}
		sum+=num[p]-num[i];
	}
	printf("%lld\n",ans);
	return 0;
}
