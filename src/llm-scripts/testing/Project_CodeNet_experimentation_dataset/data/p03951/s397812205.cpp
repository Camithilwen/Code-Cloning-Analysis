// Bismillahirrahmanirrahim
// by Batrrr Tolkynbayev
#include <bits/stdc++.h>
// skripi krasava
#define respa return 0
#define all(x) x.begin(), x.end()
#define sz size
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e5 + 17, M = N << 2, mod = 1e9 + 7; 

int tt = 1, n;
string s, t;

void solve () {
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++) {
		string f = s.substr(i, n - i);
		string h = t.substr(0, n - i);
		if (f == h) {
			cout << n + i; return;
		}
	}
	cout << (n << 1);
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cin >> tt;
	while (tt--) solve();
	respa;
}