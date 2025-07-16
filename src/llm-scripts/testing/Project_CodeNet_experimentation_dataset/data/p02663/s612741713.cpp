#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	cout << c * 60 + d - a * 60 - b - k << endl;
	return 0;
}