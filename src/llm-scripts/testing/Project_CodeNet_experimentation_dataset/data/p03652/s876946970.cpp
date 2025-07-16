#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> a(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> a[i][j]; --a[i][j];
		}
	}

	int ans = -1;
	for (int n = 1; n <= N; ++n) {
		vector<bool> sports(M, true);
		vector<int> join(N, 0);
		while (true) {
			bool ok = true;
			vector<int> cnt(M, 0);
			for (int i = 0; i < N; ++i) {
				while (join[i] <= M) {
					if (join[i] == M) {
						ok = false;
						break;
					}
					if (sports[ a[i][join[i]] ]) {
						++cnt[ a[i][join[i]] ];
						break;
					}
					++join[i];
				}
			}
			if (!ok) { break; }
			for (int i = 0; i < M; ++i) {
				if (cnt[i] > n) {
					ok = false;
					sports[i] = false;
				}
			}
			if (ok) {
				ans = n;
				break;
			}
		}
		if (ans > 0) { break; }
	}
	cout << ans << endl;

	return 0;
}
