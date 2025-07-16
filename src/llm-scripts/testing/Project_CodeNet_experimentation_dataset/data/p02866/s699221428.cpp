#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline int mul(int a, int b) {
  return (long long) a * b % md;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  int maxd = *max_element(d.begin(), d.end());
  vector<int> cnt(maxd + 1);
  for (int i = 0; i < n; i++) {
    cnt[d[i]]++;
  }

  if (d[0] != 0 || cnt[0] != 1) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 1; i <= maxd; i++) {
    if (cnt[i] == 0) {
      cout << 0 << '\n';
      return 0;
    }
  }

  int ans = 1;
  for (int i = 1; i <= maxd; i++) {
    for (int j = 0; j < cnt[i]; j++) {
      ans = mul(ans, cnt[i - 1]);
    }
  }
  cout << ans << '\n';
  return 0;
}
