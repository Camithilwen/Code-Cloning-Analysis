#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, m, d;
	cin >> n >> m >> d;
	cout << fixed << setprecision(20);
	double ans = 0;
	for (int i = 0; i < m - 1; i++) {
		ans += (double)((double)(2 * n - 2 * d) / n) / n;
	}
	if (d == 0)ans *= 0.5;
	cout << ans << endl;
}