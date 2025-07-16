#include <bits/stdc++.h>

using namespace std;
using i64 = std::int_fast64_t;

const int MOD = 1000000007;

template <typename T>
ostream &operator<<(ostream &os, const std::vector<T> &vec) {
  for (const auto &e : vec) os << e << (&e == &vec.back() ? "\n" : " ");
  return os;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, W, K;
  cin >> H >> W >> K;

  vector<vector<i64>> dp(H + 1, vector<i64>(W + 1, 0));
  dp[0][0] = 1;
  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      for (int bit = 0; bit < (1 << (W - 1)); bit++) {
        auto check = [bit, W]() -> bool {
          for (int b = 0; b < W - 2; b++) {
            if ((bit >> b) & 1 && (bit >> (b + 1)) & 1) return false;
          }
          return true;
        };

        if (!check()) continue;

        int nw = w;
        if ((bit >> w) & 1) {
          nw++;
        } else if (w > 0 && (bit >> (w - 1)) & 1) {
          nw--;
        }

        dp[h + 1][nw] = (dp[h + 1][nw] + dp[h][w]) % MOD;
      }
    }
  }

  cout << dp[H][K - 1] << '\n';
  return 0;
}
