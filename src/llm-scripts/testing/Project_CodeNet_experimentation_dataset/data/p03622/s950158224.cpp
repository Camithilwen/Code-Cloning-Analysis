#include<bits/stdc++.h>
#define fi first
#define se second
#define R register
#define mp make_pair
#define pb push_back
#define LL long long
#define Ldb long double
#define pii pair<int, int>
using namespace std;
const int N = 1e6 + 10;
const int mod = 998244353;

template <typename T> void read(T &x) {
	int f = 0;
	R char c = getchar();
	while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
	for (x = 0; c >= '0' && c <= '9'; c = getchar())
		x = x * 10 - '0' + c;
	if (f) x = -x;
}

int Qpow(int x, int p) {
	int ans = 1;
	while (p) {
		if (p & 1) ans = 1LL * ans * x % mod;
		x = 1LL * x * x % mod;
		p >>= 1;
	}
	return ans;
}

int Inv(int x) {
	return Qpow(x, mod - 2);
}

// ------------------------------------------

int n, m;
int inv[N], fac[N], fav[N];

int C(int x, int y) {
	return 1LL * fac[x] * fav[y] % mod * fav[x - y] % mod;
}

int main() {
	read(n); read(m);
	if (n > m) swap(n, m);
	fac[0] = fav[0] = 1;
	inv[1] = fac[1] = fav[1] = 1;
	for (int i = 2; i <= n + m; ++i) {
		inv[i] = 1LL * -mod / i * inv[mod % i] % mod +mod;
		fac[i] = 1LL * fac[i - 1] * i % mod;
		fav[i] = 1LL * fav[i - 1] * inv[i] % mod;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int tmp = 1LL * C(i * 2 - 1, i) * C(n + m - i * 2, n - i) % mod;
		ans = (ans + tmp >= mod) ? (ans + tmp - mod) : (ans + tmp);
	}
	ans = (n - 1LL * ans * Inv(C(n + m ,n))) % mod;
	ans = n + m - ans;
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}
