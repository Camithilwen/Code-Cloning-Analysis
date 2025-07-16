#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 7, mod = 1e9 + 7;

int POW(int a, int b, int mod) {
	a %= mod; int r = 1;
	for(int i = b; i > 0; i >>= 1) {
		if(i & 1) r = (r * a) % mod;
		a = (a * a) % mod;
	}
	return r;
}

int f[N], n, dp[10001][1001];

vector <tuple <int, int, int> > v;

vector <int> nxt;


int g(int lft, int idx) {
	if(idx >= v.size()) {
		return (lft == 0 ? f[n] : 0);
	}
	if(~dp[idx][lft]) {
		return dp[idx][lft];
	}
	int res = g(lft, idx + 1);
	int x, y, z; tie(x, y, z) = v[idx];
	if(x * y <= lft) {
		res += g(lft - x * y, nxt[idx]) * z % mod;
		res %= mod;
	}
	return dp[idx][lft] = res;
}



int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);

	f[0] = 1;
	for(int i = 1; i < N; i++) {
		f[i] = (f[i - 1] * i) % mod;
	}

	int a, b, c, d; cin >> n >> a >> b >> c >> d;

	for(int i = a; i <= b; i++) {
		int k = POW(f[i], mod - 2, mod), p = 1;
		for(int j = 1; j <= c; j++) {
			p = (p * k) % mod;
		}
		for(int j = c; j <= d; j++) {
			if(i * j <= n) {
				v.push_back(make_tuple(i, j, (p * POW(f[j], mod - 2, mod)) % mod));
			}
			p = (p * k) % mod;
		}
		while(nxt.size() < v.size()) {
			nxt.push_back(v.size());
		}
	}
	memset(dp, -1, sizeof dp);
	cout << g(n, 0) << endl;
}