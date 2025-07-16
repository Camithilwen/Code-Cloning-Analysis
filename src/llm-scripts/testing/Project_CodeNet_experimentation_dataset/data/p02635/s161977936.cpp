#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, m, n) for (int i = (m); i < (n); i++)

constexpr long long mod = 998244353;

int main() {
  string s; int k; cin >> s >> k;
  k = min<int>(k, count(s.begin(), s.end(), '1'));
  vector<int> a = { 0 };
  for (auto c : s) if (c == '1') a.back()++; else a.push_back(0);
  reverse(a.begin(), a.end());
  int n = a.size();

  static long long dp[305][305][305]; // i, kx, carry

  dp[0][0][0] = 1;
  rep(i, n) rep(kx, k+1) rep(carry, k+1) {
    if ((dp[i][kx][carry] %= mod) == 0) continue;
    rep2(fw, 1, a[i]+1) dp[i+1][kx][carry+fw] += dp[i][kx][carry];
    rep(take, carry+1) dp[i+1][kx+take][carry-take] += dp[i][kx][carry];
  }

  long long res = 0;
  rep(kx, k+1) res += dp[n][kx][0];
  cout << res % mod << "\n";
}