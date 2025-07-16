#include "bits/stdc++.h"
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
#define pb push_back
#define ins insert
#define f first
#define s second	
#define db 0
#define EPS (1e-7)    //0.0000001 the value
#define PI (acos(-1))
#define MAXN (300006)
#define MAXK 26
#define MAXX 15000006
#define ll long long int 
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
#define FOR(ii, ss, ee) for(ll ii = ss; ii < ee; ++ii)
#define space " "
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ((ll)x.size())
#define ph push
#define btinpct(x) __builtin_popcountll(x)
#define p2(x) (1LL<<(x))
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
typedef pair <ll, ll> pi;
typedef pair <ll, pi> spi;
typedef pair <pi, pi> dpi;
inline ll rand(ll x, ll y) { ++y; return (rng() % (y-x)) + x; } //inclusivesss
ll n, A[MAXN], dp[302*302], dp2[302*302];
const ll MOD=998244353;
ll qexp(ll x, ll e) {
	if(e==0) return 1;
	ll half = qexp(x,e/2);
	half *= half;
	half %= MOD;
	if(e%2) half *= x;
	half %= MOD;
	return half;
}
int main()
{
	cin>>n; FOR(i,0,n) cin>>A[i];
	ll sum=accumulate(A,A+n,0);
	dp[0]=1;dp2[0]=1;
	for(ll i=0;i<n;i++) {
		for(ll j=sum;j>=0;j--) {
			// dp[j] = dp[j] + (dp[j]*2)%MOD; dp[j] %= MOD;
			dp[j] *= 2; dp[j] %= MOD;
			if(j>=A[i])dp[j] += dp[j-A[i]]; dp[j] %= MOD;
			if(j>=A[i])dp2[j] += dp2[j-A[i]]; dp2[j] %= MOD;
		}
	}
	ll ans = qexp(3,n-1); 
	for(ll i=(sum+1)/2;i<=sum;++i) {
		ans -= (dp[i]);
		ans += MOD;
		ans %= MOD;
	}
	if(sum%2==0) {
		ans += dp2[sum/2];
		ans %= MOD;
	}
	cout<<(ans*3LL)%MOD<<'\n';
}
