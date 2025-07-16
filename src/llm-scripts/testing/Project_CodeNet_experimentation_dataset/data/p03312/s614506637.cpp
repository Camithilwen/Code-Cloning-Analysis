/// In The Name Of God

#include <bits/stdc++.h>

#define f first
#define s second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()

#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, l, r) for (int i = (l); i >= (r); i--)

#define Kazakhstan ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define nl '\n'
#define ioi exit(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (int)5e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

using namespace std;

int n;
int a[N];
ll p[N];

ll sum(int l, int r) {
	return p[r] - p[l - 1];
}
int left(int i) {
	int l = 2, r = i, ans = i;
	while (l <= r) {
		int mid = l + r >> 1;
		if (p[mid - 1] >= p[i] - p[mid - 1]) {
			ans = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return ans;
	// return {max(p[ans - 1], p[i] - p[ans - 1]), min(p[ans - 1], p[i] - p[ans - 1])};
}
int right(int i) {
	int l = i + 1, r = n - 1, ans = i + 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (p[mid] - p[i] <= p[n] - p[mid]) {
			ans = mid, l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return ans;
	// return {max(p[n] - p[ans], p[ans] - p[i]), min(p[n] - p[ans], p[ans] - p[i])};
}
ll ans = linf;
void upd (pair <ll, ll> x, pair <ll, ll> y) {
	ans = min(ans, max(x.f, y.f) - min(x.s, y.s));
}
void upd(ll x, ll y, ll z, ll w) {
	// cout << x << ' ' << y << ' ' << z << ' ' << w << nl;b
	ans = min(ans, max({x, y, z, w}) - min({x, y, z, w}));
}
int main() {
	#ifdef wws
		freopen ("in.txt", "r", stdin);
	#endif
	Kazakhstan
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
	}
	rep(i, 2, n - 1) {
		// i = 4;
		int l = left(i), r = right(i);
		// cout << l << ' ' << r << nl;
		upd(sum(l, i), sum(1, l - 1), sum(i + 1, r), sum(r + 1, n));
		if (l > 2) {
			upd(sum(l - 1, i), sum(1, l - 2), sum(i + 1, r), sum(r + 1, n));
			if (r + 2 <= n) {
				upd(sum(l - 1, i), sum(1, l - 2), sum(i + 1, r + 1), sum(r + 2, n));
			}
		}
		if (r + 2 <= n) {
			upd(sum(l, i), sum(1, l - 1), sum(i + 1, r + 1), sum(r + 2, n));
		}
		/* pair <ll, ll> l = left(i), r = right(i);
		cout << l.f << ' ' << l.s << nl;
		cout << r.f << ' ' << r.s << nl;
		l.f = max(l.f, r.f);
		l.s = min(l.s, r.s);
		ans = min(ans, l.f - l.s);
		break; */
		// break;/b/
	}
	cout << ans;
	ioi
}
