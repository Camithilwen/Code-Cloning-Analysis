#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<vector>
#include<functional>
using namespace std;
typedef long long LL;
inline LL read()
{
	LL kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}
LL a[2000222],dp[4],n,sum[2000222];
#define P(x) (x%3+3)%3
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		sum[i]=sum[i-1];
		if(i&1)sum[i]+=a[i];
	}
	dp[1]=0;dp[2]=max(a[1],a[2]);
	for(int i=3;i<=n;++i)
	{
		LL now,pre1,pre2;
		now=P(i);pre1=P(i-1);pre2=P(i-2);
		dp[now]=0;
		if(i&1)
		{
			dp[now]=max(dp[pre1],dp[pre2]+a[i]);
		}
		else
		{
			dp[now]=max(sum[i],dp[pre2]+a[i]);
		}
	}
	printf("%lld\n",dp[P(n)]);
}