#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

double expected_value(int n) {
  return (double)((1 + n) * n / 2) / (double)n;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<double> ps(n + 1);
  vector<double> comsum(n + 1, 0);
  int p;
  rep(i, n) {
    cin >> p;
    ps[i + 1] = expected_value(p);
    comsum[i + 1] = comsum[i] + ps[i + 1];
  }
  double mm = 0;
  for (int i = k; i <= n; i++) {
    mm = max(comsum[i] - comsum[i - k], mm);
  }
  printf("%.6f\n", mm);
  return 0;
}
