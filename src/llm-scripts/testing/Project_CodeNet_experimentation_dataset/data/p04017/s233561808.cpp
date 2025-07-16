#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;
const int N = 100100;

int n, x[N], L, Q, dp[N][17];

void calc() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 17; j++)
			dp[i][j] = inf;
	for (int i = 1; i <= n; i++) {
		auto it = upper_bound(x + 1, x + 1 + n, x[i] + L);
		it--;
		dp[i][0] = it - x;
	}
	for (int j = 1; j < 17; j++)
		for (int i = 1; i <= n; i++) 
			dp[i][j] = dp[dp[i][j - 1]][j - 1];			
}

int get(int l, int r) {
	if (l > r) swap(l, r);
	int ll = 1, rr = n - 1, res = r - l;
	while (ll <= rr) {
		int mid = ll + rr >> 1, cur = l;
		for (int i = 0; i < 17; i++)
			if (mid & (1 << i)) cur = dp[cur][i];
		if (cur >= r) {
			res = mid;
			rr = mid - 1;
		} else ll = mid + 1;
	}
	return res;
}

int main() {
	cin >> n;
	fill(x, x + N, inf);
	for (int i = 1; i <= n; i++) 
		cin >> x[i];
	cin >> L >> Q;
	calc();
	while (Q--) {
		int l, r;
		cin >> l >> r;
		cout << get(l, r) << '\n';
	}
}
