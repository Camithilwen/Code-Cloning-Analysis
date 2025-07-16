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

const int mod = 998244353;
const int N = 1e5+23;

int h[N];

long long binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}

void solve() {
  int n; scanf("%d", &n);
  for (int d, i = 0; i < n; ++i) {
    scanf("%d", &d);
    if (!i && d) {
      puts("0");
      return;
    }
    ++h[d];
  }
  if (h[0] > 1) {
    puts("0");
    return;
  }
  long long ans = 1;
  for (int i = 0; i < n-1; ++i) {
    if (!h[i] && h[i+1]) {
      puts("0");
      return;
    }
    (ans *= binpow(h[i], h[i+1])) %= mod;
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
