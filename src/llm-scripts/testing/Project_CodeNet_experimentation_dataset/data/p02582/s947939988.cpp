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


	string s;
	cin >> s;
	int count = 0, max_count = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'R')
			count++;
		else {
			count = 0;
		}
		max_count = max(count, max_count);
	}
	cout << max_count;
	return 0;
}