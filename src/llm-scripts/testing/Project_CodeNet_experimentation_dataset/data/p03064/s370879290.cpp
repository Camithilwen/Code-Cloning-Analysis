#include <bits/stdc++.h>
using namespace std;

using i32 = std::int_fast32_t;
using i64 = std::int_fast64_t;

#define REP(i, stop) FOR(i, 0, stop)
#define FOR(i, start, stop) for (int i = start, i##_len = stop; i < i##_len; ++i)
#define RREP(i, n) for (int i = n; i-- > 0;)

i32 M = 998244353;
i32 dp[90310];
i32 dq[90310];

signed main() {
  i32 n;
  scanf("%d", &n);
  vector<i32> A(n);
  i32 sum = 0;
  REP(i, n) {
    scanf("%d", &A[i]);
    sum += A[i];
  }
  i32 lim = (sum - 1) / 2;
  dp[0] = 1;
  dq[0] = 1;
  REP(i, n) {
    RREP(t, 90000) {
      (dp[t + A[i]] += dp[t]) %= M;
      (dp[t] *= 2) %= M;
      (dq[t + A[i]] += dq[t]) %= M;
    }
  }
  i32 ans = 1;
  REP(i, n) {
    ans = (ans * 3) % M;
  }
  FOR(t, lim + 1, 90000) {
    ans = (ans - dp[t] * 3) % M;
  }
  if (sum % 2 == 0) {
    ans = (ans + dq[sum / 2] * 3) % M;
  }
  ans = (ans + M) % M;
  printf("%d\n", ans);
}