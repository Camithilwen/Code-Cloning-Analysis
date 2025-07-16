#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, k;
  cin >> n >> k;
  vector<double> ps(n + 1);
  ps[0] = 0;
  double t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    ps[i + 1] = (t + 1) / 2 + ps[i];
  }

  double result = 0;
  for (int i = k; i <= n; ++i) {
    result = max(result, ps[i] - ps[i - k]);
  }

  cout << std::fixed << std::setprecision(10) << result << endl;
  return 0;
}