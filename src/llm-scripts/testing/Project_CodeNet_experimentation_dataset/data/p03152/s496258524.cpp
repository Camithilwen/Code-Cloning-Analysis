#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	const Int MOD = 1e9 + 7;
	int N, M;
	cin >> N >> M;
	vector<int> a(N), b(M);
	vector<Int> cnt_a(1000010, 0), cnt_b(1000010, 0);
	bool ok = true;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		++cnt_a[a[i]];
		if (cnt_a[a[i]] > 1) { ok = false; }
	}
	for (int i = 0; i < M; ++i) {
		cin >> b[i];
		++cnt_b[b[i]];
		if (cnt_b[b[i]] > 1) { ok = false; }
	}
	if (!ok) {
		cout << 0 << endl;
		return 0;
	}

	Int ans = 1;
	for (int i = N * M; i > 0; --i) {
		if (cnt_a[i] == 0 && cnt_b[i] == 0) {
			Int tmp = cnt_a[i + 1] * cnt_b[i + 1] % MOD;
			tmp = (tmp + MOD - (N * M - i)) % MOD;
			(ans *= tmp) %= MOD;
		} else if (cnt_a[i] != 1 || cnt_b[i] != 1) {
			if (cnt_a[i] > 0) {
				(ans *= cnt_b[i + 1]) %= MOD;
			} else {
				(ans *= cnt_a[i + 1]) %= MOD;
			}
		}

		cnt_a[i] += cnt_a[i + 1];
		cnt_b[i] += cnt_b[i + 1];
	}
	cout << ans % MOD << endl;

	return 0;
}
