/// IN THE NAME OF GUITAR
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<ll, ll> pll;

#define sz(x)                       (ll) x.size()
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define lc                          id << 1
#define rc                          lc | 1

ll Pow(ll a, ll b, ll md, ll ans = 1) {
    for (; b; b >>= 1, a = a * a % md)
        if (b & 1)
            ans = ans * a % md;
    return ans % md;
}
 
const ll MAXN = 2e3 + 20;
const ll INF  = 1e18;
const ll MOD  = 1e9 + 7;
ll L[MAXN], R[MAXN], A[MAXN][MAXN], ps[MAXN][MAXN], n, m, ans;
stack<ll> st;

int main() {
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (ll j = 1; j <= m; j++) {
			A[i][j] = (s[j - 1] == '#');
		}
	}
	for (ll i = 1; i < n; i++) {
		for (ll j = 1; j < m; j++) {
			ll cnt = A[i][j] + A[i + 1][j] + A[i][j + 1] + A[i + 1][j + 1];
			if (cnt & 1) ps[i][j] = 0;
			else ps[i][j] = ps[i - 1][j] + 1;
		}
	}
	ans = max(n, m);
	for (ll i = 1; i < n; i++) {
		while (sz(st)) st.pop();
		st.push(0);
		for (ll j = 1; j < m; j++) {
			while (sz(st) && ps[i][j] <= ps[i][st.top()]) st.pop(); 
			if (sz(st))
				L[j] = st.top();
			st.push(j);
		}
		while (sz(st)) st.pop();
		st.push(m);
		for (ll j = m - 1; j >= 1; j--) {
			while (sz(st) && ps[i][j] <= ps[i][st.top()]) st.pop();
			if (sz(st)) R[j] = st.top();
			st.push(j);
		}
		for (ll j = 1; j < m; j++) {
			ans = max(ans, (ps[i][j] + 1) * (R[j] - L[j]));
		}
	}
	printf("%lld\n", ans);
    return 0;
}
 