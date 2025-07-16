#include <bits/stdc++.h>
using namespace std;

const int M = int(1e9 + 7);

signed main() {
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  vector<int> pre(N + 1); {
    for (int i = 0; i < N; ++i) {
      pre[i + 1] = pre[i] ^ A[i];
    }
    if (pre[N]) {
      static int dp[1 << 19][2][2][2];
      dp[1][0][1][1] = 1;
      for (int i = 1; i <= N; ++i) {
        for (int c = 0; c < 2; ++c) {
          if (pre[i] == 0) {
            (dp[i + 1][c][1][1] += dp[i][c][0][0]) %= M;
            (dp[i + 1][c][1][1] += dp[i][c][0][1]) %= M;
          } else if (pre[i] == pre[N]) {
            (dp[i + 1][c ^ 1][0][1] += dp[i][c][1][0]) %= M;
            (dp[i + 1][c ^ 1][0][1] += dp[i][c][1][1]) %= M;
          }
          (dp[i + 1][c][0][0] += dp[i][c][0][0]) %= M;
          (dp[i + 1][c][1][0] += dp[i][c][1][0]) %= M;
          (dp[i + 1][c][0][0] += dp[i][c][0][1]) %= M;
          (dp[i + 1][c][1][0] += dp[i][c][1][1]) %= M;
        }
      }
      int ans = (dp[N + 1][0][0][1] + dp[N + 1][1][0][1]) % M;
      cout << ans << endl;
      return 0;
    }
  }

  vector<int> pz(pre.size() + 1); {
    for (int i = 0; i < pre.size(); ++i) {
      pz[i + 1] = pz[i] + (pre[i] == 0);
    }
  }

  map<int, vector<int>> dp; {
    map<int, int> cnt;
    map<int, int> last;
    for (int i = 0; i < pre.size(); ++i) {
      if (pre[i]) {
        if (last.count(pre[i])) {
          int l = last.count(pre[i]) ? last[pre[i]] : 0;
          int cz = pz[i] - pz[l];
          if (cz) dp[pre[i]].push_back(cz);
        }
        ++cnt[pre[i]];
        last[pre[i]] = i;
      } else {
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
          dp[it->first].push_back(it->second);
        }
        cnt.clear();
      }
    }
  }

  int ans = 1; {
    for (int i = 1; i + 1 < pre.size(); ++i) {
      if (pre[i] == 0) ans = 2LL * ans % M;
    }
    for (auto it = dp.begin(); it != dp.end(); ++it) {
      auto s = it->second;
      vector<int> dpdp(2);
      dpdp[0] = 1;
      for (int i = 0; i < s.size(); ++i) {
        (dpdp[~i & 1] += 1LL * s[i] * dpdp[i & 1] % M) %= M;
      }
      (ans += dpdp[1]) %= M;
    }
  }

  cout << ans << endl;

  return 0;
}
