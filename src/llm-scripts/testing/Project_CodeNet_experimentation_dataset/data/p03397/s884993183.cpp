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
const ll maxn=3e5+10, maxm=1e6+10, lg=21, mod=1e9+7, inf=1e18;

string s;
ll n,dp[maxn][3][3],ans;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>s;
	dp[0][0][0]=1;
	for(int i=0;i<SZ(s);i++)for(int t0=0;t0<3;t0++)for(int t1=0;t1<3;t1++){
		if(s[i]!='0'){
			if(t0) (dp[i+1][t0-1][t1]+=dp[i][t0][t1])%=mod;
			else (dp[i+1][t0][min(t1+1,2)]+=dp[i][t0][t1])%=mod;
		}
		if(s[i]!='1'){
			if(t0>1) (dp[i+1][t0-1][t1]+=dp[i][t0][t1])%=mod;
			else (dp[i+1][t0+1][t1]+=dp[i][t0][t1])%=mod;
		}
	}
	for(int t0=0;t0<3;t0++)for(int t1=t0;t1<3;t1++) (ans+=dp[SZ(s)][t0][t1])%=mod;
	cout<<ans;
	
	return 0;
}
