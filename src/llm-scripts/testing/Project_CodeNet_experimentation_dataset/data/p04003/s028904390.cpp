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

int n, m;

unordered_map <int, vector <int > > g[N];

unordered_map <int, int> d[N];

int c[N];

int main() {
	#ifdef IOI2018
		freopen ("in.txt", "r", stdin);
    freopen ("E.out", "w", stdout);
	#endif
	Kazakhstan
	cin >> n >> m;
	rep(i, 1, m) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a][c].pb(b);
    g[b][c].pb(a);
	}
	d[1][0] = 0;
	deque < pair <int, pair <int, int> > > st;
	st.pb({0, {1, 0}});
  vector <bool> was(n + 1, 0);
	while (sz(st)) {
		int dist = st.front().f;
		int v = st.front().s.f, last = st.front().s.s;
		st.pop_front();
    
    if (!was[v]) {
      for (auto it : g[v]) {
        int C = it.f;
        for (auto to : it.s) {
          if (!d[to].count(C) || d[to][C] > dist + 1) {
            d[to][C] = dist + 1;
            st.pb({d[to][C], {to, C}});
          }
        }
      }
      was[v] = 1;
    }
    if (sz(g[v][last])) {
      int C = last;
      for (auto to : g[v][last]) {
        if (!d[to].count(last) || d[to][last] > dist) {
          d[to][C] = dist;
          st.push_front({d[to][C], {to, C}});
        }
      }
      g[v][last].clear();
      g[v].erase(last);
    }
  }
  int ans = inf;
  for (auto it : d[n]) ans = min(ans, it.s);
  cout << (ans == inf ? -1 : ans);
	ioi
}
