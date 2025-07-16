#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << endl;
}
const int mod = 1e9 + 7;

vector<ll> fac(MAX), finv(MAX), inv(MAX);

void comInit(){
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(ll i=2; i<MAX; i++){
		fac[i] = fac[i-1]*i % mod;
		inv[i] = mod - inv[mod%i] * (mod/i) % mod;
		finv[i] = finv[i-1] * inv[i] % mod;
	}
}


ll com(ll n, ll k){
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

int main(){
	ll n,x; cin >> n >> x;
	comInit();
	vl a(n); rep(i,n) cin >> a[i];
	sort(rall(a));
	vvl dp(n+1,vl(x+1,0));
	dp[0][x] = 1;
	rep(i,n){
		rep(j,x+1){
			dp[i+1][j%a[i]] += inv[n-i] * dp[i][j];
			dp[i+1][j] += ((n-1-i)*inv[n-i])%mod * dp[i][j];
			dp[i+1][j%a[i]] %= mod;
			dp[i+1][j] %= mod;
		}
	}
	ll ans = 0;
	rep(i,x+1){
		ans += dp[n][i] * fac[n] % mod * i;
		ans %= mod;
	}
	cout << ans << endl;
}