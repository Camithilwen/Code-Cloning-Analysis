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
	int t = 1;
	// cin >> t;
    while(t--) {
		int n, x, t;
		cin >> n >> x >> t;
		int ans = (n / x) * t;
		if(n % x != 0) ans += t;
		cout << ans << endl;
    }
}
