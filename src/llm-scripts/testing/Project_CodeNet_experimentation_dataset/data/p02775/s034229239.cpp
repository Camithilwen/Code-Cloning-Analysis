#include <bits/stdc++.h>

#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rip return;
#define fo(i,a,b) for(int i = a ; a < b ? i <= b : i >= b ; i += (a < b ? 1 : -1))

#define F first
#define S second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using ld = long double;

const int mod = 1e9 + 7;
// const int mod = 998244353;
const ll inf = 2e9;
const ll INF = 1e18;
const ld EPS = 1e-7;

const int N = 1e6 + 55;

int dp[N], dp2[N];

int solve (string s) {
	s = "0" + s;
	int n = s.size();
	fo (i, 0, n + 1) {
		dp[i] = 0, dp2[i] = 0;
	}
	dp2[0] = 1;
	fo (i, 1, n) {
		int u = s[i - 1] - '0';
		dp[i] = min (dp[i - 1] + u, dp2[i - 1] + 10 - u);
		dp2[i] = min (dp2[i - 1] + 9 - u, dp[i - 1] + 1 + u);
	}
	return dp[n];
}

int to_int (string s) {
	int res = 0;
	for (char c : s) {
		res = res * 10 + c - '0';
	}
	return res;
}

int dig (int x) {
	int res = 0;
	while (x) res += x % 10, x /= 10;
	return res;
}

pair <int, int> brute (string s) {
	int u = to_int (s);
	int best = dig (u), sec = u;
	for (int v = u ; v <= 1e7 ; ++ v) {
		int cur = dig (v) + dig (v - u);
		if (cur < best) {
			sec = v;
			best = cur;
		}
		// best = min (best, dig (v) + dig (v - u));
	}
	return {best, sec};
}

int main () {
	// ios;
	// cout << fixed << setprecision (10);
	int tt = 1;
	// cin >> tt;
	while (tt-- || 0) {
		string s;
		cin >> s;
		// cout << brute (s).F << " " << brute (s).S << "\n";
		// if (solve (s) != brute (s).F) {
			// cout << "ERROR " << solve (s) << " " << brute (s).F << "\n\t" << brute (s).S << "\nERROR " << s << "\n";
			// return 0;
		// }
		cout << 
		solve(s);
		// cout << "\n";
	}
}


