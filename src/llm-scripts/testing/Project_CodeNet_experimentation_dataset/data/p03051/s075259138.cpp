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
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#define debug(x) cerr << #x << ':' << (x) << '\n'
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000010;
constexpr ll INF = 1000000000000000010;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

constexpr ll mod = 1000000007;
const int sz = 1 << 20;

ll modpow(ll a, ll b, ll m = mod) {
	ll ans = 1;
	a %= m;
	while (b) {
		if (b & 1) ans = ans * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	int now = 0;
	vector<int> a(n), x(n), zero(n);
	vector<vector<int>> pl(sz, vector<int>());
	rep(i, n) {
		cin >> a[i];
		now ^= a[i];
		x[i] = now;
		int pre = 0;
		if (i) pre = zero[i - 1];
		if (now == 0) pre++;
		zero[i] = pre;
		pl[now].pb(i);
	}
	if (now == 0) {
		ll ans = modpow(2, pl[0].size() - 1);
		for (int num = 1; num < sz; num++) {
			vector<int> vec;
			int s = pl[num].size();
			if (s == 0) continue;
			rep(i, s - 1) {
				vec.pb(1);
				vec.pb(zero[pl[num][i + 1]] - zero[pl[num][i]]);
			}
			vec.pb(1);
			vector<vector<ll>> dp(2 * s, vector<ll>(2));
			dp[0][0] = 1;
			rep(i, 2 * s - 1) {
				dp[i + 1][0] += dp[i][0];
				if (i % 2 == 1) {
					dp[i + 1][0] += dp[i][1] * vec[i];
				}
				dp[i + 1][1] += dp[i][1];
				if (i % 2 == 0) {
					dp[i + 1][1] += dp[i][0] * vec[i];
				}
				dp[i + 1][0] %= mod;
				dp[i + 1][1] %= mod;
			}
			ans += dp[2 * s - 1][1];
		}
		ans %= mod;
		cout << ans << '\n';
	}
	else {
		int num = now;
		vector<int> vec;
		int s = pl[num].size();
		rep(i, s - 1) {
			vec.pb(1);
			vec.pb(zero[pl[num][i + 1]] - zero[pl[num][i]]);
		}
		vector<vector<ll>> dp(2 * s - 1, vector<ll>(2));
		dp[0][0] = 1;
		rep(i, 2 * s - 2) {
			dp[i + 1][0] += dp[i][0];
			if (i % 2 == 1) {
				dp[i + 1][0] += dp[i][1] * vec[i];
			}
			dp[i + 1][1] += dp[i][1];
			if (i % 2 == 0) {
				dp[i + 1][1] += dp[i][0] * vec[i];
			}
			dp[i + 1][0] %= mod;
			dp[i + 1][1] %= mod;
		}
		cout << dp[2 * s - 2][0] << '\n';
	}
}