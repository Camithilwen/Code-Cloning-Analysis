#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005, mod = 998244353;
ll fac[MX], inv[MX];
int n, k;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p >>= 1;
	}
	return res;
}

ll comb (int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * inv[k] % mod * inv[n-k] % mod;
}

// n espacios, k numeros
ll f (int n, int k) {
	if (!n) return 1;
	return comb(n + k - 1, n);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fac[0] = inv[0] = 1;
	for (ll i = 1; i < MX; i++) {
		fac[i] = i * fac[i-1] % mod;
		inv[i] = pot(fac[i], mod - 2);
	}

	cin >> k >> n;
	for (int i = 2; i <= 2 * k; i++) {
		ll res = 0;
		int a = 0, b = 0, mit = 0;

		for (int j = 1; j <= k; j++) {
			if (2 * j == i) mit = 1;
			else if (1 <= i - j && i - j <= k) a++;
			else b++;
		}

		a /= 2;

		for (int j = 0; j <= a; j++) {
			res += comb(a, j) * pot(2, j) % mod *
				(f(n - j, j + b) + mit * f(n - j - 1, j + b)) % mod;
			res %= mod;
		}

		cout << res << endl;
	}

	return 0;
}
