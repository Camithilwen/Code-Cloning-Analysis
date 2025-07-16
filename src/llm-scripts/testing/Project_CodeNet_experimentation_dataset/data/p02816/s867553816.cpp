#include <bits/stdc++.h>
using namespace std;

const int mul[2] = {233, 19260817};
const int mod[2] = {998244353, 1000000007};

#define pb push_back

int n;
vector <int> a, b, na, nb, pw[2], hsh[2];
int get(int l, int r, int k) {return (hsh[k][r] + mod[k] - 1LL * pw[k][r - l] * hsh[k][l] % mod[k]) % mod[k];}

int main() {
	ios :: sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; ++ i) {int x; cin >> x; a.pb(x);}
	for (int i = 0; i < n; ++ i) {int x; cin >> x; b.pb(x);}
	for (int i = 0; i < n; ++ i) na.pb(a[i] ^ a[(i + 1) % n]);
	for (int i = 0; i < n; ++ i) na.pb(na[i]);
	for (int i = 0; i < n; ++ i) nb.pb(b[i] ^ b[(i + 1) % n]);
	int hb[2];
	for (int k = 0; k < 2; ++ k) {
		pw[k].pb(1); for (int i = 1; i <= n * 2; ++ i) pw[k].pb(1LL * mul[k] * pw[k].back() % mod[k]);
		hsh[k].pb(0); for (int i = 0; i < n * 2; ++ i) hsh[k].pb((1LL * mul[k] * hsh[k].back() + na[i]) % mod[k]);
		hb[k] = 0; for (int i = 0; i < n - 1; ++ i) hb[k] = (1LL * mul[k] * hb[k] + nb[i]) % mod[k];
	}
	for (int i = 0; i < n; ++ i)
		if (get(i, i + n - 1, 0) == hb[0] && get(i, i + n - 1, 1) == hb[1] && na[i + n - 1] == nb[n - 1])
			cout << i << " " << (a[i] ^ b[0]) << "\n";
	return 0;
}