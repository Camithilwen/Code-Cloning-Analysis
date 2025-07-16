#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define lowbit(x) (x)&(-x)
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define per(i,a,b) for (int i=a;i>=b;i--)
#define maxd 998244353
typedef long long ll;
const int N=100000;
const double pi=acos(-1.0);
int n,a[400];
ll dp[310][90050][2];

int read()
{
	int x=0,f=1;char ch=getchar();
	while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
	while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}

int main()
{
	n=read();ll sum=0;
	rep(i,1,n) {a[i]=read();sum+=a[i];}
	dp[0][0][0]=1;dp[0][0][1]=1;
	rep(i,1,n)
	{
		rep(j,0,sum)
		{
			dp[i][j][0]=dp[i-1][j][0];
			dp[i][j][1]=(dp[i-1][j][1]*2)%maxd;
			if (j>=a[i])
			{
				dp[i][j][0]=(dp[i][j][0]+dp[i-1][j-a[i]][0])%maxd;
				dp[i][j][1]=(dp[i][j][1]+dp[i-1][j-a[i]][1])%maxd;
			}
		}
	}
	ll ans=1;
	rep(i,1,n) ans=(ans*3)%maxd;
	rep(i,(sum+1)/2,sum)
	{
		ans=(ans-dp[n][i][1]*3)%maxd;
		if (i*2==sum)
		{
			ans=(ans+dp[n][i][0]*3)%maxd;
		}
	}
	ans=(ans%maxd+maxd)%maxd;
	printf("%lld",ans);
	return 0;
}
