#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;
typedef pair<int, int> ii;

ii p[100005];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> p[i].l >> p[i].r;
	int l = 0, r = 1e9;
	int x, y;
	for (int i = 0; i < N; ++i) {
		if (p[i].l > l) {
			l = p[i].l;
			x = i;
		}
		if (p[i].r < r) {
			r = p[i].r;
			y = i;
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ans = max(max(p[i].r - p[i].l + 1, 0), ans);
	}
	ans += max(r - l + 1, 0);
	if (x == y) {		
		cout << ans << '\n';
		return 0;
	}

	sort(p, p + N, [](const ii& a, const ii& b) { return a.r < b.r || (a.r == b.r && a.l > b.l); });
	int s = 0;
	for (int i = 0; i < N - 1; ++i) {
		s = max(p[i].l, s);
		ans = max(max(r - s + 1, 0) + max(p[i + 1].r - l + 1, 0), ans);
	}
	cout << ans << '\n';
}