// FUCKED UP FUCKED UP FUCKED UP FUCKED UP FUCKED UP
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define MP make_pair

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=3e2+10, maxm=5e4+10, lg=21, mod=998244353, inf=1e18;

string s;
ll k,n,cnt,a[maxn],d[maxn],dp[maxn][maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>s>>k;
	for(char c:s) (c=='0' ? cnt++:a[n++]=cnt);
	k=min(k,n);
	for(int i=0;i<n;i++) d[a[i]]++;
	dp[cnt+1][0][0]=1;
	for(int i=cnt+1;i;i--)for(int j=0;j<=k;j++)for(int k=0;k<=n;k++)if(dp[i][j][k])for(int t=0;t<=d[i-1]+k;t++) (dp[i-1][j+max(0ll,d[i-1]-t)][d[i-1]+k-t]+=dp[i][j][k])%=mod;
	ll ans=0;
	for(int i=0;i<=k;i++) ans+=dp[0][i][0];
	cout<<ans%mod;
	
	return 0;
}



 
