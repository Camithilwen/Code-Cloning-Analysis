#pragma target("avx")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef unordered_map<ll, ll> U_MAP;
typedef priority_queue<ll> pq;
typedef priority_queue<ll, vector<ll>, greater<ll>> rpq;
const int INF = 1e9, MOD = 1e9 + 7, ohara = 1e6 + 10;
const ll LINF = 1e18;

#define rep(i, n) for (ll(i) = 0; (i) < (int)(n); (i)++)
#define rrep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout << (x) << endl
#define doublecout(a) cout << fixed << setprecision(15) << a << endl;
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back

//------ Believe yourself as a genius!!!!!! ------

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
// int dy[]={-1,0,1,-1,1,-1,0,1};int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"), s;
ll n, cnt, ans, a[ohara], b[ohara], c, d, tmp, m, h, w, x, y, sum, k, q;
ll color[ohara];
V g[ohara];

bool dfs(ll v, ll c) {
  color[v] = c;
  rep(i, Size(g[v])) {
    if (color[g[v][i]] == c) return false;
    if (color[g[v][i]] == 0 && !dfs(g[v][i], -c)) return false;
  }
  return true;
}

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    g[a[i]].p_b(b[i]);
    g[b[i]].p_b(a[i]);
  }
  int ok = 1;
  rep(i, n) {
    if (color[i] == 0) {
      if (!dfs(i, 1)) {
        ok = 0;
        break;
      }
    }
    if (!ok) break;
  }
  if (!ok) {
    ans = n * (n - 1) / 2;
  } else {
    ll cou1 = 0, cou2 = 0;
    rep(i, n) {
      if (color[i] == 1)
        cou1++;
      else
        cou2++;
    }
    ans = cou1 * cou2;
  }
  Cout(ans - m);
  return 0;
}