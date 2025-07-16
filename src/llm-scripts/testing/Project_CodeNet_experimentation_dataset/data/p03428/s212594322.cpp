#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;



int main() {
	int n; cin >> n;
	vector<P> a(n);
	rep(i, 0, n) cin >> a[i].first >> a[i].second;
	rep(i, 0, n) {
		int idx = 0;
		double b[201];
		rep(j, 0, n) {
			if (i == j) continue;
			b[idx++] = atan2(a[j].second - a[i].second, a[j].first - a[i].first);
		}
		sort(b, b + idx);
		rep(j, 0, idx) b[j + idx] = b[j] + 2 * M_PI;
		double ans = 0;
		rep(j, 0, idx) ans = max(ans, M_PI - b[j + idx - 1] + b[j]);
		printf("%.12f\n", ans/2/M_PI);
	}
	return 0;
}
