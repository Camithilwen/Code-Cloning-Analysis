#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e18
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],dp[maxn][5],n,pre[maxn];

int main()
{
	n=read(); rep(i,1,n) a[i]=read();
	rep(i,1,n) rep(j,0,3) dp[i][j]=-inf;
	dp[1][0]=a[1]; dp[2][1]=a[2]; dp[3][2]=a[3];
	for(int i=3;i<=n;i++)
	{
		dp[i][0]=dp[i-2][0]+a[i];
		dp[i][1]=max(dp[i-2][1],dp[i-3][0])+a[i];
		if(i>=4) dp[i][2]=max(max(dp[i-2][2],dp[i-3][1]),dp[i-4][0])+a[i];
	}
	if(n%2==1) cout<<max(max(dp[n][2],dp[n-1][1]),dp[n-2][0])<<endl;
	else cout<<max(dp[n][1],dp[n-1][0])<<endl;
	return 0;
}