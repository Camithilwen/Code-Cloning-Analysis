#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

ll a[16][16];
ll v[1 << 16]; // value of that submask
ll dp[1 << 16];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; read(n);
	rep(i, 0, n) rep(j, 0, n) read(a[i][j]);

	for (int b = 0; b < (1 << n); b++) {
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if ((b >> i & 1) && (b >> j & 1))
			v[b] += a[i][j];
	}

	dp[0] = 0;
	for (int i = 1; i <= n; i++) for (int j = 0; j < (1 << n); j++) if (__builtin_popcount(j) == i) {
		dp[j] = v[j];
		for (int k = j; k > 0; k = (k - 1) & j) {
			chmax(dp[j], dp[j ^ k] + v[k]);
		}
	}

	write(dp[(1 << n) - 1]);
}
