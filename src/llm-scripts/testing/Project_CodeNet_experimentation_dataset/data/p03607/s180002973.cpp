#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];

	if (n == 1) {
		cout << 1;
		return 0;
	}

	sort(a.begin(), a.end());
	int ans = 0;
	rep(i,n - 1) {
		if (a[i] != a[i + 1]) ans++;
		else i++;
		if (i == n - 2) ans++;
	}
	cout << ans;
	return 0;
}
