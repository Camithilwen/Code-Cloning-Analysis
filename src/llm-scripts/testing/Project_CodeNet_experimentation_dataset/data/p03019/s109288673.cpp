#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long x;
  cin >> n >> x;
  vector<long long> b(n), l(n), u(n);
  long long loss = 0;
  for (int i = 0; i < n; i++) {
    cin >> b[i] >> l[i] >> u[i];
    loss += b[i] * l[i];
  }
  vector<long long> value(n);
  for (int i = 0; i < n; i++) {
    value[i] = x * u[i] - b[i] * (u[i] - l[i]);
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return value[i] > value[j];
  });
  vector<long long> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + value[order[i]];
  }
  long long ans = (long long) 9e18;
  for (int it = 0; it < n; it++) {
    int i = order[it];
    for (long long coeff : {l[i], u[i]}) {
      int low = 0, high = n;
      while (low <= high) {
        int mid = (low + high) >> 1;
        long long cur = loss;
        if (coeff == u[i]) {
          cur += b[i] * (u[i] - l[i]);
        }
        long long can_get = pref[mid];
        long long vals = mid;
        if (it < mid) {
          can_get -= value[i];
          vals -= 1;
        }
        can_get += x * coeff;
        if (can_get >= cur) {
          can_get -= x * coeff;
          long long need = 0;
          if (can_get < cur) {
            need = (cur - can_get + coeff - 1) / coeff;
          }
          ans = min(ans, vals * x + need);
        }
        if (low == high) {
          break;
        }
        if (can_get >= cur) {
          high = mid;
        } else {
          low = mid + 1;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}