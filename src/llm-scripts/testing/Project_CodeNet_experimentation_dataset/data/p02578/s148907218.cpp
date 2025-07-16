#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mp  make_pair
#define pb  push_back
#define endl "\n"
#define rep(i,a,n) for(int i=a;i<n;i++)
const int mod = 1e9 + 7;
void solve() {
	int n;
	cin >> n;
	int a[n];
	rep(i, 0, n) {
		cin >> a[i];
	}
	int s = 0;
	rep(i, 1, n) {
		if (a[i] < a[i - 1]) {
			s += a[i - 1] - a[i];
			a[i] = a[i - 1];
		}
	}
	cout << s << endl;
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int t;
	t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
