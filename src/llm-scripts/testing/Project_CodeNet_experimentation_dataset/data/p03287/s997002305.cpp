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

const int N = 1e5+23;

int a[N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  map<int, int> h;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if (i) a[i] += a[i-1];
    a[i] %= m;
    ++h[a[i]];
  }
  for (const auto &e: h) {
    if (e.first == 0) continue;
    ans += 1LL*e.second*(e.second-1)/2;
  }
  ans += 1LL*h[0]*(h[0]+1)/2;
  printf("%lld", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
