#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	vector<vector<ll>> cnt(62, vector<ll>(62, 0));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (find(s.begin(), s.end(), '.') == s.end()) s.push_back('.');
		int pos = 0;
		while (s[pos] != '.') pos++;
		s += string(10 - s.size() + pos, '0');
		ll y = 0;
		for (auto c : s) {
			if (isdigit(c)) y = y * 10 + c - '0';
		}
		int p2 = 0, p5 = 0;
		for (; y % 2 == 0; y /= 2, p2++);
		for (; y % 5 == 0; y /= 5, p5++);
		cnt[p2][p5]++;
	}
	ll ans = 0;
	for (int p2 = 0; p2 < 62; p2++) {
		for (int p5 = 0; p5 < 62; p5++) {
			for (int pp2 = 0; pp2 < 62; pp2++) {
				for (int pp5 = 0; pp5 < 62; pp5++)
					ans += cnt[p2][p5] * cnt[pp2][pp5] * (min(p2 + pp2, p5 + pp5) >= 18) *
					       (pair<int, int>{p2, p5} != pair<int, int>{pp2, pp5});
			}
		}
	}
	for (int p2 = 0; p2 < 62; p2++) {
		for (int p5 = 0; p5 < 62; p5++) ans += cnt[p2][p5] * (cnt[p2][p5] - 1) * (min(p2, p5) * 2 >= 18);
	}
	cout << ans / 2 << '\n';
}
