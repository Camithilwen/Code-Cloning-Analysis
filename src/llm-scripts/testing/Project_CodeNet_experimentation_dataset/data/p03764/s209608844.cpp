#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  const long long mod = 1e9 + 7;
  int x[2];
  cin >> x[0] >> x[1];
  static long long line[2][100000] = {};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < x[i]; j++) {
      cin >> line[i][j];
    }
  }
  long long sum[2] = {};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < x[i]; j++) {
      sum[i] += line[i][j] * j;
      sum[i] = (sum[i] % mod + mod) % mod;
      sum[i] -= line[i][j] * (x[i] - 1 - j);
      sum[i] = (sum[i] % mod + mod) % mod;
    }
  }
  cout << sum[0] * sum[1] % mod << endl;
  return 0;
}