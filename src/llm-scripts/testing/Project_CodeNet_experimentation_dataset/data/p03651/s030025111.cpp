#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  int g = -1, m = 0;
  for (int a, i = 0; i < n; ++i) {
    scanf("%d", &a);
    m = max(m, a);
    if (g == -1) g = a;
    else g = __gcd(g, a);
  }
  if (k > m || k % g) puts("IMPOSSIBLE");
  else puts("POSSIBLE");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
