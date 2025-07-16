#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 998244353;

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	ll ans = 1;
	vector<int> d(n);
	for (int& i : d) {
		cin >> i;
	}
	sort(d.begin() + 1, d.end());
	vector<int> cnt(n + 1);
	for (int i = 1; i < n; i++) {
		cnt[d[i - 1]]++;
		if (d[i] == 0) {
			ans = 0;
			break;
		}
		ans = ans * cnt[d[i] - 1] % mod;
	}
	cout << ans << endl;
	return 0;
}
