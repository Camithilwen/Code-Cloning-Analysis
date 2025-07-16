#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (1 << 17) + 10;
const int mod = 1e9 + 7;

int n, x, y, z, ans;
int lim, Haiku, dp[45][N];

ll PowMod(ll a, ll b) {
	ll res = 1 % mod;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int main() {
	cin >> n >> x >> y >> z;
	dp[0][0] = 1; lim = (1 << (x + y + z)) - 1;
	Haiku = (1 << (x - 1)) + (1 << (x + y - 1)) + (1 << (x + y + z - 1));
	// cout << n << " " << lim << endl;
	for(int i = 1;i <= n; ++i) {
		for(int S = 0;S <= lim; ++S) {
			if(!dp[i - 1][S]) continue;
			for(int j = 1;j <= 10; ++j) {
				int T = (((S << j) | (1 << (j - 1)))) & lim;
				if((T & Haiku) == Haiku) continue;
				dp[i][T] += dp[i - 1][S];
				dp[i][T] %= mod;
			}
		}
	}
	for(int i = 0;i <= lim; ++i) 
		ans = (ans + dp[n][i]) % mod;
	ans = (PowMod(10, n) - ans + mod) % mod;
	cout << ans << endl;
	return 0;
}