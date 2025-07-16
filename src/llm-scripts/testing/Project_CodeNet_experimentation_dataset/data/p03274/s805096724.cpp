#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

int main() {
	int n, k;

	cin >> n >> k;
	vector<int> x(n);
	rep(i, n)
		cin >> x[i];

	int ans=INT_MAX;
	for (int i = 0;i < n - k + 1;++i) {
		int l = x[i];
		int r = x[i + k - 1];
		int m = min(abs(l), abs(r)) + abs(l - r);
		ans = min(ans, m);
	}

	cout << ans << endl;
}