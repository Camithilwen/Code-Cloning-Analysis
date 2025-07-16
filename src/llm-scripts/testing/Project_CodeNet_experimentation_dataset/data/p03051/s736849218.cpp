#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
#define PB push_back
#define EB emplace_back
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define MOD 1'000'000'007

#define N 512345
int n; 
int a[N];
int b[N]={};
map<int, vector<int>> mp;
vi v;
ll dp[N][2];

ll chk(int x, int y){
	v.clear();
	vi u = mp[x];
	REP(i, (int)u.size()-1){
		v.EB(b[u[i+1]]-b[u[i]]);
	}
	dp[v.size()][0]=0;
	dp[v.size()][1]=1;
	for(int i=v.size()-1; i>=0; i--){
		dp[i][0] = dp[i+1][0] + dp[i+1][1]*v[i];
		dp[i][0] %= MOD;
		dp[i][1] = y + dp[i+1][0] + dp[i+1][1]*(v[i]+1);
		dp[i][1] %= MOD;
	}
	DEBUG("chk(%d)\n", x);
	REP(i, (int)v.size()+1) DEBUG("%2d ", i); DEBUG("\n");
	REP(i, (int)v.size())   DEBUG("%2d ", v[i]); DEBUG("\n");
	REP(i, (int)v.size()+1) DEBUG("%2lld ", dp[i][0]); DEBUG("\n");
	REP(i, (int)v.size()+1) DEBUG("%2lld ", dp[i][1]); DEBUG("\n");
	return dp[0][1];
}

int main(){
	scanf("%d", &n);
	REP(i, n) scanf("%d", a+i);
	FOR(i, 1, n) a[i]^=a[i-1];
	REP(i, n) b[i+1]=b[i]+(a[i]==0?1:0);
	REP(i, n) if(a[i]) mp[a[i]].EB(i);

	REP(i, n) DEBUG("%2d ", i); DEBUG("\n");
	REP(i, n) DEBUG("%2d ", a[i]); DEBUG("\n");

	ll ans = 0;
	if(a[n-1]){
		ans+=chk(a[n-1], 0);
		ans%=MOD;
	}else{
		for(auto p:mp){
			ans+=chk(p.first, 1);
			ans%=MOD;
		}
		ll pw = 1;
		REP(i, b[n]-1) pw*=2, pw%=MOD;
		ans+=pw;
		ans%=MOD;
	}
	printf("%lld\n", ans);
}
