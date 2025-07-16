#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

const long long mod = 998244353;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n); cin >> a;
	map<int, int> m;
	for (int x : a) m[x]++;
	if (m[0] != 1 || a[0] != 0) {
		cout << "0\n";
		return 0;
	}
	int mx = *max_element(a.begin(), a.end());
	long long ans = 1;
	for (int i = 1; i <= mx; i++) {
		long long res = 1;
		for (int j = 0; j < m[i]; j++) {
			res *= m[i - 1];
			res %= mod;
		}
		ans *= res;
		ans %= mod;
	}
	cout << ans << '\n';
}
