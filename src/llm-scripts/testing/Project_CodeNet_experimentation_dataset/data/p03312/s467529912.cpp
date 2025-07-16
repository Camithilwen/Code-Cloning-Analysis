#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

typedef pair < db, db > pdd;
typedef pair < db, ld > pdl;
typedef pair < ld, db > pld;
typedef pair < ld, ld > ldp;

typedef pair < ll, ll > pll;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < int, int > pii;

#define F first
#define S second

#define en end()
#define bg begin()

#define rev reverse
#define mp make_pair
#define pb push_back

#define y1 y1234567890
#define um unordered_map

#define all(x) x.bg, x.en
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)

#define sqr(x) ((x + 0ll) * (x))
#define sqrd(x) ((x + 0.0) * (x))

#define forn(i, n) for (int i = 1; i <= n; i++)

const ll inf = (ll)1e18;
const ll mod = (ll)1e9 + 7;

const db eps = (db)1e-9;
const db pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 200500;

int n;
ll p[N];

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//srand(time(NULL));

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		p[i] = p[i - 1] + x;
	}

	ll ans = inf;

	for (int i = 2, pl = 1, pr = 2; i < n; i++) {
		while (pl + 1 < i && abs(p[pl + 1] - (p[i] - p[pl + 1])) <= abs(p[pl] - (p[i] - p[pl])))
			pl++;
		while (pr + 1 < n && abs(p[pr + 1] - p[i] - (p[n] - p[pr + 1])) <= abs(p[pr] - p[i] - (p[n] - p[pr])))
			pr++;
		ans = min(ans, max({p[pl], p[i] - p[pl], p[pr] - p[i], p[n] - p[pr]}) - min({p[pl], p[i] - p[pl], p[pr] - p[i], p[n] - p[pr]}));
	}

	cout << ans;
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
