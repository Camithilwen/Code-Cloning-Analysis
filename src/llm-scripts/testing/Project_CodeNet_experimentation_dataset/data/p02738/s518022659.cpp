/*	
	Over ice, I'm freezing
	Beautiful eyes, deceiving
	We may die this evening
	Coughing, wheezing, bleeding...
*/	
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("Os")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=2e3+10, maxm=2e3+10, lg=18, mod=1e9+7, inf=1e18;

ll n,dp[3*maxn][maxn],M;

void add(ll &x,ll y){
	x+=y;
	if(x>=M) x-=M;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>M;
	dp[0][0]=1;
	for(int i=0;i<3*n;i++)for(int j=0;j<=n;j++){
		add(dp[i+1][j],dp[i][j]);
		add(dp[i+2][j+1],dp[i][j]*(i+1)%M);
		add(dp[i+3][j+1],dp[i][j]*(i+1)%M*(i+2)%M);
	}
	ll ans=0; for(int i=0;i<=n;i++) ans+=dp[3*n][i];
	cout<<ans%M;
	
	return 0;
}


