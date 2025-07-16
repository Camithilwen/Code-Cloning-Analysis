#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

// For modular arithmetic when a modular is specified per input case.
// Verified: ABC129F
struct ModInt {
 private:
  static int64 M;
  int64 x;
 public:
  static void SetMod(int64 mod) {
    M = mod;
  }
  ModInt(int64 input_x) : x(input_x % M) {}
  ModInt() : x(0) {}
  int64 Value() { return x; }
  inline ModInt operator+(ModInt o) {
    ModInt r(*this); r += o; return r;
  }
  inline ModInt operator-(ModInt o) {
    ModInt r(*this); r -= o; return r;
  }
  inline ModInt operator* (ModInt o) {
    ModInt r(*this); r *= o; return r;
  }
  inline void operator+= (ModInt o) { x = (x + o.x) % M; }
  inline void operator-= (ModInt o) { x = (x + M - o.x) % M; }
  inline void operator*= (ModInt o) { x = (x * o.x) % M; }
};
int64 ModInt::M = 1;  // Do not forget to add this line.

template<typename T>
vector<vector<T>> MakeVector2D(int d1, int d2, T default_value) {
  return vector<vector<T>>(d1, vector<T>(d2, default_value));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int m;
  cin >> m;
  ModInt::SetMod(m);

  const int BASE = n;
  auto dp = MakeVector2D<ModInt>(3 * n + 1, 2 * n + 1, ModInt(0));
  dp[0][BASE] = 1;
  for (int i = 0; i < 3 * n; i++) {
    for (int k = 0; k <= 2 * n; k++) {
      if (dp[i][k].Value() == 0) continue;
      // Size 1
      dp[i + 1][min(k + 1, 2 * n)] += dp[i][k];

      // Size 2
      if (k > 0 && i + 2 <= 3 * n) {
        dp[i + 2][k - 1] += dp[i][k] * (i + 1);
      }

      // Size 3
      if (i + 3 <= 3 * n) {
        dp[i + 3][k] += dp[i][k] * (i + 1) * (i + 2);
      }
    }
  }

  ModInt ans = 0;
  for (int k = BASE; k <= 2 * n; k++) {
    // cout << dp[3 * n][k].Value() << endl;
    ans += dp[3 * n][k];
  }
  cout << ans.Value() << endl;
}