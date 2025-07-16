#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

constexpr ll mod = 1000000007;
constexpr ll modsize = 2000;
vector<ll> fac(modsize);
vector<ll> inv(modsize);
vector<ll> facinv(modsize);

void modcalc() {
	if (modsize == 0) abort();
	fac[0] = 1; fac[1] = 1; inv[1] = 1;
	facinv[0] = 1; facinv[1] = 1;
	for (ll i = 2; i < modsize; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
}

ll modinv(ll a) {
	if (a == 0) abort();
	ll b = mod, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= mod;
	if (u < 0) u += mod;
	return u;
}

ll modpow(ll a, ll b) {
	ll ans = 1;
	a %= mod;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

ll modcomb(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

ll modperm(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[n - k] % mod;
}

ll modhom(ll n, ll k) {
	if (n < 0 || k < 0 || n == 0 && k > 0) return 0;
	if (n == 0 && k == 0) return 1;
	return fac[n + k - 1] * facinv[k] % mod * facinv[n - 1] % mod;
}

ll dp[1010][1010];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	
	modcalc();
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	dp[0][a] = 1;
	for (int j = a; j <= b; j++) {
		rep(i, n + 1) {
			dp[i][j + 1] += dp[i][j];
			if (dp[i][j + 1] > mod) dp[i][j + 1] -= mod;
			int st = i;
			for (int k = c; k <= d; k++) {
				if (i + j * k > n) break;
				dp[i + j * k][j + 1] += dp[i][j] * fac[n - i] % mod * modpow(facinv[j], k) % mod * facinv[n - i - j * k] % mod * facinv[k] % mod;
				if (dp[i + j * k][j + 1] > mod) dp[i + j * k][j + 1] -= mod;
			}
		}
	}
	cout << dp[n][b + 1] << endl;
}