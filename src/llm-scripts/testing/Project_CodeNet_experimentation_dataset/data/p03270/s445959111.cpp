#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const double EPS = 1e-10;
bool used[4001];
ll fact[4001], inv_fact[4001];
ll comb(ll n, ll k) {
	if (n < k) return 0;
	ll ret = fact[n];
	(ret *= inv_fact[k]) %= MOD;
	(ret *= inv_fact[n - k]) %= MOD;
	return ret;
}
ll mod_pow(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		ll x = mod_pow(a, b / 2);
		return (x*x) % MOD;
	}
	return (a*mod_pow(a, b - 1)) % MOD;
}
int main() {
	int K, N;
	cin >> K >> N;
	fact[0] = 1;
	inv_fact[0] = 1;
	for (int i = 1; i <= 4000; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		inv_fact[i] = (inv_fact[i - 1] * mod_pow(i, MOD - 2)) % MOD;
	}
	for (int i = 2; i <= 2 * K; i++) {
		memset(used, 0, sizeof(used));
		int x = 0, y = 0;
		for (int j = 1; j <= K; j++) {
			if (used[j]) continue;
			used[j] = 1;
			if (1 <= i - j && i - j <= K) {
				if (!used[i - j]) {
					used[i - j] = 1;
					y++;
				}
			}
			else {
				x++;
			}
		}
		ll ans = 0;
		for (int j = 0; j <= min(N, y); j++) {
			ll t = comb(y, j);
			(t *= mod_pow(2, j)) %= MOD;
			(t *= comb(N + x - 1, N - j)) %= MOD;
			(ans += t) %= MOD;
		}
		if (i % 2 == 0) {
			for (int j = 0; j <= min(N - 1, y); j++) {
				ll t = comb(y, j);
				(t *= mod_pow(2, j)) %= MOD;
				(t *= comb(N + x - 2, N - 1 - j)) %= MOD;
				(ans += t) %= MOD;
			}
		}
		cout << ans << endl;
	}
}