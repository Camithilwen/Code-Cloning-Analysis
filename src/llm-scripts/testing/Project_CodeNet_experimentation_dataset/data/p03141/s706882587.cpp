#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
ll n, a, b, res;
int main() {
	cin >> n;
	vector<ll> s(n);
	REP(i, n) {
		cin >> a >> b;
		s[i] = a + b;
		res -= b;
	}
	sort(s.rbegin(), s.rend());
	REP(i, n) res += s[i++];
	cout << res << '\n';
	return 0;
}