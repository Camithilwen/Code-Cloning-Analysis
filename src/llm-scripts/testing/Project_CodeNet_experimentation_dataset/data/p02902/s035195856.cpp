//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define trav(x,a) for (const auto& x: a)
#define sz(x) (int)(x).size()
#define mem(a,v) memset((a), (v), sizeof (a))
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int _i = 0; _i < (n); _i++) ni(a[_i])
#define nal(a, n) for (int _i = 0; _i < (n); _i++) nl(a[_i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int N = 1e6 + 5;
const double eps = 1e-9;
vi adj[N];
int dp[N], par[N];

int main() {
  int n, m; scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    adj[u].pb(v);
  }
  int len = inf, idx = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      dp[j] = inf;
    deque<int> pq; pq.pb(i);
    dp[i] = 0;
    int mn = inf;
    while (sz(pq)) {
      int u = pq.front(); pq.pop_front();
      trav(v, adj[u]) {
        if (v == i)
          mn = min(mn, dp[u]+1);
        if (dp[v] > dp[u] + 1) {
          dp[v] = dp[u] + 1;
          pq.pb(v);
        }
      }
    }
    if (mn < len) {
      len = mn, idx = i;
    }
  }
  if (idx < 0)
    return !printf("-1\n");
  for (int j = 1; j <= n; j++)
    dp[j] = inf;
  deque<int> pq; pq.pb(idx);
  dp[idx] = 0;
  int c = 0;
  while (sz(pq)) {
    int u = pq.front(); pq.pop_front();
    c++;
    int d = dp[u];
    if (c == 1)
      dp[u] = inf;
    trav(v, adj[u]) {
      if (dp[v] > d + 1) {
        dp[v] = d + 1;
        par[v] = u;
        pq.pb(v);
      }
    }
  }
  vi ans;
  int u = idx;
  do {
    ans.pb(u);
    u = par[u];
  } while (u != idx);
  printf("%d\n", sz(ans));
  trav(v, ans) printf("%d\n", v);
  return 0;
}
