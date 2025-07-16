#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;

ll mpow(ll a, ll b) {
	ll res = 1;
	a %= mod;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
vector<int> fac, finv;
void factor(int N) {
	fac.resize(N); finv.resize(N);
	fac[0] = finv[0] = 1;
	rep(i, 1, N)fac[i] = 1LL * fac[i - 1] * i % mod;
	finv[N - 1] = mpow(fac[N - 1], mod - 2);
	for (int i = N - 2; i; --i) finv[i] = 1LL * finv[i + 1] * (i + 1) % mod;
}
int nCr(int n, int m) {
	if (m < 0 || n < m) return 0;
	return 1LL * (1LL * fac[n] * finv[m] % mod) * finv[n - m] % mod;
}


int main() {
	int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
	factor(200010);
	vector<vector<ll>> dp(n+10);
	rep(i, 0, n + 10) dp[i].resize(n + 10, 0);
	dp[0][0] = 1;
	rep(i, 0, n + 1)rep(j, 0, b - a + 2) {
		int idx = a + j;
		dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
		rep(k, c, d + 1) {
			int sum = idx * k + i;
			if (sum > n) break;
			ll base = nCr(n - i, idx * k);
			base = (1LL * base * fac[idx * k]) % mod;
			base = (1LL * base * mpow(finv[idx], k)) % mod;
			base = (1LL * base * finv[k]) % mod;
			dp[sum][j + 1] = (dp[sum][j + 1] + (dp[i][j] * base) % mod) % mod;
		}
	}
	printf("%lld", dp[n][b - a + 1]);
	return 0;
}
