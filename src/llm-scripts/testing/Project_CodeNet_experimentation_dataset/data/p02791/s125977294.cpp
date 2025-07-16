#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e9 + 5;
#define INF 100000000000
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;
const int MAXN = 201+5;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
	ll n;
	cin >> n;
	ll a[n];
	for(ll i=0; i<n; i++){
		cin >> a[i];
	}
	ll ans = 1;
	ll mini = a[0];
	for(ll i=1; i<n; i++){
		if(mini>a[i]){
			ans++;
			mini=a[i];
		}
	}
	cout << ans << "\n";
	return 0;
}

//^-^