#include <iostream>
using namespace std;
const int MAX = 500;

int main() {
	int n, m, Q;
	cin >> n >> m >> Q;
	int S[MAX+1][MAX+1] = {};
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		S[l][r]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			S[i][j] += S[i][j-1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			S[i][j] += S[i-1][j];
		}
	}
	auto sum_rect = [&](int x0, int y0, int x1, int y1) {
		return S[x1][y1] - S[x0-1][y1] - S[x1][y0-1] + S[x0-1][y0-1];
	};
	for (int query = 0; query < Q; query++) {
		int p, q;
		cin >> p >> q;
		int ans = sum_rect(p, p, q, q);
		cout << ans << endl;
	}
	return 0;
}