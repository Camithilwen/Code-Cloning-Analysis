#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 123;
int n;
ll a[N];
vector <ll> basis;

void add(ll x) {
	for (ll i : basis) {
		x = min(x, x ^ i);
	}
	if (x > 0) {
		basis.pb(x);
	}
}

int f(ll x) {
	for (int i = 59; i >= 0; i--) {
		if (x >> i & 1) {
			return i;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	ll t = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		t ^= a[i];
	}
	ll ans = t, rt = t ^ ((1ll << 60) - 1);
	for (int i = 1; i <= n; i++) {
		a[i] &= rt;
		add(a[i]);
	}
	sort(all(basis));
	reverse(all(basis));
	ll res = 0;
	for (ll i : basis) {
		if (res >> f(i) & 1) {
			continue;
		}
		res ^= i;
	}
	ans += 2 * res;
	cout << ans;
}
