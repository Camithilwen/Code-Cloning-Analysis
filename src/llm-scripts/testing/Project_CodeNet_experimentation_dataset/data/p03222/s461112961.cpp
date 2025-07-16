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

const int mod = 1e9+7;
const int N = 123;

long long p[N];
int H, W, K;
long long dp[N][8];

bool check(int x) {
  int prev = 0;
  while (x) {
    if ((x&1) && prev) return false;
    prev = x&1;
    x >>= 1;
  }
  return true;
}

long long rek(int h, int pos) {
  if (h == H) return pos == (K-1);
  long long &ret = dp[h][pos];
  if (ret != -1) return ret;
  ret = 0;
  for (int j = 0; j < 3; ++j) {
    if (pos == 0 && j == 1) continue;
    if (pos == W-1 && j == 2) continue;
    long long cur = 0;
    int lmt = pos-1;
    if (j == 1) --lmt;
    for (int i = 0; i < (1 << max(lmt, 0)); ++i) {
      if (!check(i)) continue;
      ++cur;
    }
    long long cur2 = 0;
    lmt = W-1-pos-1;
    if (j == 2) --lmt;
    for (int i = 0; i < (1 << max(lmt, 0)); ++i) {
      if (!check(i)) continue;
      ++cur2;
    }
    cur *= cur2;
    if (j == 1) {
      ret = (ret + cur*rek(h+1, pos-1)%mod) % mod;
    } else if (j == 2) {
      ret = (ret + cur*rek(h+1, pos+1)%mod) % mod;
    } else {
      ret = (ret + cur*rek(h+1, pos)%mod) % mod;
    }
  }
  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d%d", &H, &W, &K);
  printf("%lld", rek(0, 0));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
