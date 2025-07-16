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
const int inf = 1e9 + 7;
const int N = 6e3 + 5;
const double eps = 1e-9;
int n, mod;
int add(int x, int y) { return x+y < mod ? x+y : x+y-mod; }
int mul(int x, int y) { return x*1ll*y % mod; }
int dp[N][2*N], fac[N];

int main() {
  scanf("%d %d", &n, &mod);
  dp[0][3*n] = 1;
  for (int i = 1; i <= 3*n; i++) {
    for (int j = 0; j <= 6*n; j++) {
      if (j > 0)
        dp[i][j] = add(dp[i-1][j-1], dp[i][j]);
      if (i > 1)
        dp[i][j] = add(dp[i][j], mul(dp[i-2][j+1], i-1));
      if (i > 2)
        dp[i][j] = add(dp[i][j], mul(dp[i-3][j], mul(i-1,i-2)));
    }
  }
  int ans = 0;
  for (int i = 3*n; i <= 6*n; i++)
    ans = add(ans, dp[3*n][i]);
  printf("%d\n", ans);
  return 0;
}
