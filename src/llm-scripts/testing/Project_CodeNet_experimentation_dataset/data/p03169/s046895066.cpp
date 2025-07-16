#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 305;
ld dp[N][N][N];
bool mark[N][N][N];
int n;

ld solve(int t1, int t2, int t3) {
	int t0 = n - (t1 + t2 + t3);
	if (t0 == n)
		return 0;
	ld &ans = dp[t1][t2][t3];
	if (mark[t1][t2][t3])
		return ans;
	mark[t1][t2][t3] = 1;
	ans = 1;
	if (t1)
		ans += solve(t1 - 1, t2, t3) * ((ld) t1 / n);
	if (t2)
		ans += solve(t1 + 1, t2 - 1, t3) * ((ld) t2 / n);
	if (t3)
		ans += solve(t1, t2 + 1, t3 - 1) * ((ld) t3 / n);
	ans /= (1 - ((ld)t0 / n));
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t[4] = {};
	cin >> n;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		t[a]++;
	}
	cout << fixed << setprecision(12) << solve(t[1], t[2], t[3]);
	return 0;
}
