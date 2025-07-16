#include<bits/stdc++.h>
using namespace std;
struct _IO{_IO(){ios::sync_with_stdio(0);cin.tie(0);}}_io;

typedef long long ll;
typedef long double db;
typedef unsigned long long ull;
typedef vector<int> vi; typedef vector<vi> vii;
typedef pair<int, int> pi;
typedef tuple<int, int, int> t3;
typedef map<int, int> mi;
#define fi first
#define se second
#define vt vector
#define be begin()
#define ed end()
#define sz size()
#define cl clear()
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define lb(v, x) lower_bound(v.begin(), v.end(), x)
#define lbi(v, x) (lb(v, x) - v.begin())
#define tp(t, x, y) t x, y; tie(x, y)
#define tp3(t, x, y, z) t x, y, z; tie(x, y, z)
#define mp make_pair
#define mt make_tuple
#define co const
#define fc(x) for(int x = 1, _end = ri(); x <= _end; x++)
void uni(vi &v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }

db rd() { db x; cin >> x; return x; }
ll ri() { ll x; cin >> x; return x; }
string rs() { string s; cin >> s; return s; }
pi rpi() { pi x; cin >> x.fi >> x.se; return x; }
vi rvi(int n, int f = 0) { vi v(n + f); for (int i = f; i < v.size(); i++) cin >> v[i]; return v; }
vii rvii(int n, int m, int f = 0) { vii v(n + f, vi(n + f)); for (int i = f; i < v.size(); i++) for (int j = f; j < v[0].size(); j++) cin >> v[i][j]; return v; }
void pr() {}; template <class T, class ...U> void pr(T x, U ...y) { cout << x << ' ', pr(y...); }
void prl() { cout << '\n'; }; template <class T, class ...U> void prl(T x, U ...y) { cout << x << ' ', prl(y...); }
void pr(const vi &v, int f = 0) { for (int i = f; i < v.size(); i++) cout << v[i] << ' '; }
void prl(const vi &v, int f = 0) { pr(v, f); cout << '\n'; }
void pr(const pi &x) { cout << x.fi << ' ' << x.se; };
void prl(const pi &x) { pr(x); cout << '\n'; }

#define rep(i, l, r) for (int i = l; i < r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)

const int N = 2e5 + 5, M = 1e9 + 7;

int fa[N];
int fi(int x) {
  return !fa[x] || fa[x] == x ? x : fa[x] = fi(fa[x]);
}

vi g[N];
map<int, vi> cnt;
bool vis[N];
void dfs(int u) {
  vis[u] = 1;
  cnt[fi(u)].pb(u);
  for (auto &v : g[u]) {
    if (!vis[v]) dfs(v);
  }
}

int main() {
  int n = ri(), a = ri(), b = ri();
  rep(i, 0, a) {
    int x = ri(), y = ri();
    fa[fi(x)] = fi(y);
  }
  rep(i, 0, b) {
    int u = ri(), v = ri();
    g[u].pb(v);
    g[v].pb(u);
  }
  vi ans(n + 1);
  rep(i, 1, n + 1) {
    if (!vis[i]) {
      cnt.clear();
      dfs(i);
      for (auto &p : cnt) {
        for (auto &v : p.se) {
          ans[v] = p.se.sz;
        }
      }
    }
  }
  pr(ans, 1);
}
