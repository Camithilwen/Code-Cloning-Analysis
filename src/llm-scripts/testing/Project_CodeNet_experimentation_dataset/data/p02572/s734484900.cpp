#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int main() {
	fast;
	ll n;
	cin >> n;
	vector<ll> v(n);
	ll sum = 0;
	for(ll i=0;i<n;i++) {
		cin >> v[i];
		sum += v[i];
	}
	sum -= v[0];
	ll ans = 0;
	for(ll i=0;i<n-1;i++) {
		ans = (ans + ((sum % MOD) * (v[i] % MOD)) % MOD) % MOD;
		sum -= v[i + 1];
	}
	cout << ans << endl;
}
