#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;
const int MOD = 1e9+7;

int ans;
int n;
ll v[MAX], sum[MAX];

void solve() {
	cin >> n;
	for(int i=0; i<n; i++) cin >> v[i];
	ans = 0;
	for(int i=0; i<61; i++) {
		ll c1 = 0;
		for(int j=0; j<n; j++) c1 += (v[j] >> i)&1;
		ll sum = c1*(n-c1);
		for(int j=0; j<i; j++) sum = 2*sum % MOD;
		ans = (ans + sum) % MOD;
	}
	cout << ans%MOD << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

