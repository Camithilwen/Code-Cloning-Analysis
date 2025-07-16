#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }


void solve() {
	int n, s;
	cin >> n >> s;
	set<pair<int, ll>> all;
	for (int i = 0; i < n; ++i) {
		int x, p;
		cin >> x >> p;
		all.insert({x, p});
	}

	ll ans = 0;
	int fl = -1;
	while (true) {
		if (all.begin()->ff > s) {
			ans += (--all.end())->ff - s;
			break;
		}
		if ((--all.end())->ff < s) {
			ans += s - all.begin()->ff;
			break;
		}

		if ((all.begin())->ss < (--all.end())->ss) {
			auto tmp = *all.begin();
			all.erase(all.begin());
			auto tmp2 = *--all.end();
			all.erase(--all.end());
			if (fl != 1) {
				ans += tmp2.ff - tmp.ff;
				fl = 1;
			}
			tmp2.ss += tmp.ss;
			all.insert(tmp2);
		} else {
			auto tmp = *all.begin();
			all.erase(all.begin());
			auto tmp2 = *--all.end();
			all.erase(--all.end());
			if (fl != 2) {
				ans += tmp2.ff - tmp.ff;
				fl = 2;
			}
			tmp.ss += tmp2.ss;
			all.insert(tmp);
		}
		//cerr << ans << endl;
	}

	cout << ans << "\n";
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}