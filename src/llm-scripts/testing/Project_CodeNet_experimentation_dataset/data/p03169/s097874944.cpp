#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 305;
ld dp[N][N][2];
int n, t[4];

void table() {
	for (int t3 = 0; t3 <= t[3]; t3++){
		int pr1 = t3 % 2, pr2 = (pr1 + 1) % 2;
		for (int t2 = 0; t2 <= n; t2++)
			for (int t1 = 0; t1 <= n; t1++) {
				int t0 = n - (t1 + t2 + t3);
				ld &ans = dp[t1][t2][pr1];
				if (t0 == n)
					ans = 0;
				else {
					ans = 1;
					if (t1)
						ans += dp[t1 - 1][t2][pr1] * ((ld) t1 / n);
					if (t2)
						ans += dp[t1 + 1][t2 - 1][pr1] * ((ld) t2 / n);
					if (t3)
						ans += dp[t1][t2 + 1][pr2] * ((ld) t3 / n);
					ans /= (1 - ((ld) t0 / n));
				}
			}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		t[a]++;
	}
	table();
	cout << fixed << setprecision(12) << dp[t[1]][t[2]][t[3] % 2];
	return 0;
}
