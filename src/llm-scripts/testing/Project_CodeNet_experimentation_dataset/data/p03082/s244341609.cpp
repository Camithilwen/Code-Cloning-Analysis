#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD =1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////
ll fac[MAX], finv[MAX], inv[MAX];

void Pinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

ll P(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * finv[n-k] % MOD;
}


int main() {
	Pinit();

	ll N, X;
	cin >> N >> X;

	vector<ll> S(N + 1);
	repn(i, N) cin >> S[i];

	vector<ll> dp(X + 1,0);
	vector<ll> lb(X + 1);

	sort(++S.begin(), S.end());

	rep(K, X+1) {
		auto itr = upper_bound(++S.begin(), S.end(), K);
		lb[K] = distance(S.begin(), itr) - 1;

		
		if (lb[K] == 0) { dp[K] = K; }

		else {
			repn(i, lb[K]) {
				ll l = K % S[i];
				ll t = dp[l] * P(lb[K]-1, lb[K]-1-lb[l]) % MOD;
				dp[K] = (dp[K] + t) % MOD;
			}
		}

		//cout << K << lb[K] << dp[K] << endl;
	}

	ll ans = dp[X] * P(N, N-lb[X]) % MOD;

	cout << ans;

	system("PAUSE");
}
