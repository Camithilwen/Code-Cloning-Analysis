#pragma GCC optimize ("Ofast")
#include "bits/stdc++.h"
	
#define PI 3.141592653589793
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
// Use for file I/O;
#define FIN string _fname = "paintbarn"; \
			string _is = _fname + ".in", _os = _fname + ".out"; \
			freopen(_is.c_str(), "r", stdin); \
			freopen(_os.c_str(), "w", stdout);

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e9 + 10;
const ll INF2 = 3e18 + 10;
const int MOD = 1e9 + 7;
const ld EPS = 1e-4;

const int LOGN = 19;
const int MAXN = 305;


inline void add_self(int &a, int b) {
	a = (a + b) % MOD;
}

ll dp[1 << 16];
ll t[1 << 16];
ll p[16][16];
int a[16];

int main() {
	FAST;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}
	for (int i = 0; i < (1 << n); i++) dp[i] = -INF2;

	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if ((mask >> i) & 1) {
				for (int j = i + 1; j < n; j++) {
					if ((mask >> j) & 1) {
						t[mask] += p[i][j];
					}
				}
			}
		}
	}

	dp[0] = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		int b = 0;
		for (int i = 0; i < n; i++) {
			if (!((mask >> i) & 1)) {a[b] = i; b++;}
		}
		for (int m = 1; m < (1 << b); m++) {
			int nmask = 0;
			for (int i = 0; i < b; i++) {
				if ((m >> i) & 1) {nmask += 1 << a[i];}
			}
			dp[nmask | mask] = max(dp[nmask | mask], dp[mask] + t[nmask]);
		}
	}
	cout << dp[(1 << n) - 1];

}