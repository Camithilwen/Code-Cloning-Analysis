#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int64_t n, m, d;
	cin >> n >> m >> d;

	double ans;
	if (!d) {
		double p = (double)n / (n * n);
		ans = (double)p * (m - 1);
	}
	else {
		double p = (double)2 * (n - d) / (n * n);
		ans = (double)p * (m - 1);
	}

	cout << fixed << setprecision(10) << ans << endl;
}