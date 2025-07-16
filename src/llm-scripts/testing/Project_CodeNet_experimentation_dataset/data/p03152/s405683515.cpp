#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 1000000007;

int solve() {
	int N, M; cin >> N >> M;
	ll r = 0, c = 0;
	vector<bool> nr(N*M, false), nc(N*M, false);
	for (int i = 0; i < N; i++) {
		int x; cin >> x; x--; if (nr[x]) return 0;
		nr[x] = true;
	}
	for (int i = 0; i < M; i++) {
		int x; cin >> x; x--; if (nc[x]) return 0;
		nc[x] = true;
	}
	ll res = 1;
	for (int i = N * M - 1; i >= 0; i--) {
		if (nr[i]) r++;
		if (nc[i]) c++;
		if (nr[i] && nc[i]) continue;
		else if (nr[i]) res *= c;
		else if (nc[i]) res *= r;
		else res *= (r * c - (N * M - 1 - i));
		res %= mod;
	}
	return res;
}

int main() {
	cout << solve() << endl;
}