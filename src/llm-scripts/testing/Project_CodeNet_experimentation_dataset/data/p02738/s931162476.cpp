#include <bits/stdc++.h>

using namespace std;
#define int long long
int MOD;
void extgcd(int a, int b, int& x, int& y) {
	if (b != 0) {
		extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1;
		y = 0;
	}
}

int mod_inverse(int a, int m) {
	int x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}
int add(int& a, const int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
vector<int> fact;
vector<int> inv_fact;
vector<int> p2;
vector<int> inv_p2;
vector<int> inv_p6;
int C(int a, int b) {
	if (a < b || b < 0) return 0;

	return ((fact[a] * inv_fact[a - b]) % MOD) * inv_fact[b] % MOD;
}
int P(int a, int b) {
	if (a < b || b < 0) return 0;

	return ((fact[a] * inv_fact[a - b]) % MOD);
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N >> MOD;
	fact.resize(3 * N + 2, 1);
	inv_fact.resize(fact.size(), 1);
	p2.resize(3 * N + 2, 1);
	inv_p2.resize(3 * N + 2, 1);
	inv_p6.resize(3 * N + 2, 1);
	int inv2 = (MOD + 1) / 2;
	int inv6 = mod_inverse(6, MOD);
	for (int i = 1; i < fact.size(); i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		p2[i] = (p2[i - 1] * 2) % MOD;
		inv_fact[i] = mod_inverse(fact[i], MOD);
		inv_p2[i] = (inv_p2[i - 1] * inv2) % MOD;
		inv_p6[i] = (inv_p6[i - 1] * inv6) % MOD;
	}
	int res = 0;
	for (int n2 = 0; n2 <= 3 * N; n2++) {
		for (int n1 = 0; n1 <= 3 * N; n1++) {
			if (n2 * 2 + n1 > 3 * N) break;
			if (n2 > n1) continue;
			int n3 = 3 * N - n2 * 2 - n1;
			if (n3 % 3 != 0) continue;
			int ans = 1;
			n3 /= 3;

			ans = (ans * C(3 * N, n1)) % MOD;

			ans = (ans * P(3 * N - n1, n2 * 2)) % MOD;
			ans = (ans * inv_fact[n2]) % MOD;
			ans = (ans * inv_p2[n2]) % MOD;

			ans = (ans * fact[n3 * 3]) % MOD;
			ans = (ans * inv_fact[n3]) % MOD;
			ans = (ans * inv_p6[n3]) % MOD;
			ans = (ans * p2[n3]) % MOD;

			//cerr << n1 << " " << n2 << " " << n3 << " " << ans << endl;
			add(res, ans);
		}
	}
	cout << res << endl;
}