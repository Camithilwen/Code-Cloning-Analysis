#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
template <typename T> using ord_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 123;
int n, a[N];
array <ll, 2> p[N], s[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int j = 1;
	ll pref = a[1], cur = a[1];
	for (int i = 2; i <= n; i++) {
		pref += a[i];
		while (abs(cur + a[j + 1] - (pref - cur - a[j + 1])) < abs(cur - (pref - cur)))
			cur += a[++j];
		p[i] = {cur, pref - cur};
		if (p[i][0] > p[i][1]) swap(p[i][0], p[i][1]);
	}
	ll suf = a[n];
	cur = a[n], j = n;
	for (int i = n - 1; i >= 1; i--) {
		suf += a[i];
		while (abs(cur + a[j - 1] - (suf - cur - a[j - 1])) < abs(cur - (suf - cur)))
			cur += a[--j];
		s[i] = {cur, suf - cur};
		if (s[i][0] > s[i][1]) swap(s[i][0], s[i][1]);
	}
	ll ans = 1e9 + 123;
	for (int i = 2; i <= n - 2; i++)
		ans = min(ans, max(p[i][1], s[i + 1][1]) - min(p[i][0], s[i + 1][0]));
	cout << ans;
}
