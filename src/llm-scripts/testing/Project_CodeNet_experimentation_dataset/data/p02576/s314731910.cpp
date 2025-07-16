#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;


	int n, x, t;
	cin >> n >> x >> t;
	int count = t, orig = x;
	while (x < n) {
		count += t;
		x += orig;
	}
	cout << count;
	return 0;
}