#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int main() {
	int n, m; cin >> n >> m;
	vector<ll>x(n), y(m); for (auto&& xx : x)cin >> xx;for (auto&& yy : y)cin >> yy;
	sort(x.begin(), x.end());sort(y.begin(), y.end());
	ll a = 0, b = 0;
	for (int i = 0; i < n; i++)a -= x[i] * (n - 1 - i - i);
	for (int i = 0; i < m; i++)b -= y[i] * (m - 1 - i - i);
	cout << (a % mod) * (b % mod) % mod << endl;
	return 0;
}