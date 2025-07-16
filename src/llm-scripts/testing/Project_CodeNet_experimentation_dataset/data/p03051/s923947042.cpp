#include <bits/stdc++.h>
using namespace std;

const int N = 550000;
const int MOD = 1e9 + 7;

int a[N], sum[N], cnt[N];
vector<int> pos[1 << 21];
int chk[1 << 21];

inline int modExp(int a, int n, int mod) {
	int ret = 1;
	while (n) {
		if (n & 1) ret = (long long)ret * a % mod;
		a = (long long)a * a % mod;
		n >>= 1;
	}
	return ret;
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] ^ a[i], cnt[i] = cnt[i - 1] + (sum[i] == 0);
	for (int i = 1; i <= n; i++) pos[sum[i]].push_back(i);
	if (sum[n] == 0) {
		int ans = 0;
		for (int i = 1; i <= n; i++) if (sum[i] && !chk[sum[i]]) {
			chk[sum[i]] = 1;
			int cnt0 = 1, cntg = 0;
			for (int j = pos[sum[i]].size() - 1; j >= 0; j--) {
				(cntg += cnt0) >= MOD && (cntg -= MOD);
				if (j) (cnt0 += (long long)cntg * (cnt[pos[sum[i]][j]] - cnt[pos[sum[i]][j - 1]]) % MOD) >= MOD && (cnt0 -= MOD);
			}
			(ans += cntg) >= MOD && (ans -= MOD);
		}
		(ans += modExp(2, cnt[n] - 1, MOD)) >= MOD && (ans -= MOD);
		cout << ans << "\n";
		return 0;
	} else {
		int cnt0 = 1, cntg = 0;
		for (int j = 0; j < pos[sum[n]].size(); j++) {
			(cntg += cnt0) >= MOD && (cntg -= MOD);
			if (j + 1 < pos[sum[n]].size()) (cnt0 += (long long)cntg * (cnt[pos[sum[n]][j + 1]] - cnt[pos[sum[n]][j]]) % MOD) >= MOD && (cnt0 -= MOD);
		}
		cout << cnt0 << "\n";
	}
	
	return 0;
}
