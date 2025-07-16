#include <bits/stdc++.h>
 
using namespace std;
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileio freopen("in.in", "r", stdin),freopen("out.out", "w", stdout);
#define ll long long int
#define FF first
#define SS second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define pss printf
#define MOD 998244353
#define INF 1e18
#define eps 0.00001
#define endl '\n'
#define debug(n1) cout<<n1<<endl

int n,k;
ll dp[2005][2005];
ll pre[2005];
ll dp1[2005][2005];

int rec(int i,int j)
{
	return dp[i][j];
}

int rec1(int i,int j)
{
	if(j==0)
		return 1;
	if(i==0)
		return (j==0);
	if(dp1[i][j]!=-1)
		return dp1[i][j];
	int an=(rec1(i-1,j)+rec1(i,j-1))%MOD;
	return dp1[i][j]=an;
}

int main()
{
	SPEED;		
	cin>>k>>n;
	dp[0][0]=1;
	pre[0]=1;
	for(int j=1;j<=n;j++)
		pre[j]=(pre[j-1]+dp[0][j])%MOD;
	for(int i=1;i<=k;i++)
	{
		dp[i][0]=1;
		for(int j=1;j<=n;j++)
			dp[i][j]=(dp[i-1][j]+2*pre[j-1])%MOD;
		pre[0]=dp[i][0];
		for(int j=1;j<=n;j++)
			pre[j]=(pre[j-1]+dp[i][j])%MOD;
	}
	memset(dp1,-1,sizeof dp1);
	for(int i=2;i<=2*k;i++)
	{
		ll ans=0;
		int moves=0;
		if(i%2)
		{
			if(i<=k)
				moves=i/2;
			else
				moves=i/2-(i-k)+1;
			for(int j=0;j<=n;j++)
			{
				ll x=rec(moves,j);
				ll y=rec1(k-2*moves,n-j);
				ans=(ans+x*y)%MOD;
			}
		}
		else
		{
			if(i<=k)
				moves=(i-1)/2;
			else
				moves=(i-1)/2 - (i-k-1);
			for(int j=0;j<=n;j++)
			{
				ll x=rec(moves,j);
				ll y=rec1(k-2*moves-1,n-j);
				ans=(ans+x*y)%MOD;
				y=0;
				if(n-j-1>=0)
					y=rec1(k-2*moves-1,n-j-1);
				ans=(ans+x*y)%MOD;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}