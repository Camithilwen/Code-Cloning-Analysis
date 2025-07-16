#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define MOD_1_000_000_007 (1000000007)
#define IINF (1<<28)
#define LINF (1LL<<60)
#define rep(i, n)      REP(i, 0, (n))
#define repc(i, n)     REPC(i, 0, (n))
#define REP(i, n, m)   for (int i = (int)(n); i <  (int)(m); i++)
#define REPC(i, n, m)  for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
#define yesno(cond)       YESNO((cond), "Yes", "No")
#define YESNO(cond, a, b) cout << ((cond) ? (a) : (b)) << "\n"

namespace solver {
  using namespace std;
  typedef long long ll;

  int N, as[16][16];
  ll sum[1<<16], dp[1<<16];

  void init() {
    cin >> N;
    rep(i, N) rep(j, N) {
      cin >> as[i][j];
    }
  }

  void build_sum() {
    rep(i, 1<<N) {
      sum[i] = 0;
      if(__builtin_popcount(i) <= 1) continue;
      int j = i & -i;
      int k = i & ~j;
      sum[i] = sum[k];
      rep(l, N) if((k >> l) & 1) {
        sum[i] += as[l][__builtin_ffs(j)-1];
      }
    }
  }

  void solve() {
    build_sum();
    rep(i, 1<<N) {
      dp[i] = sum[i];
      if(__builtin_popcount(i) <= 2) continue;
      int j = i;
      do {
        int k = i & ~j;
        if(j != 0 || k != 0) {
          dp[i] = max(dp[i], dp[j] + dp[k]);
          j = (j - 1) & i;
        }
      } while(j != i);
    }
    cout << max(0LL, dp[(1<<N)-1]) << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}