#include <bits/stdc++.h>

using namespace std;

// [l, r)
int cnt_w(vector<int> &csum, int l, int r) { return csum[r] - csum[l]; }
int cnt_e(vector<int> &csum, int l, int r) {
  return (r - l) - (csum[r] - csum[l]);
}

int main(int argc, const char *argv[]) {
  int n;
  string s;
  cin >> n >> s;

  vector<int> csum(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    csum[i] = csum[i - 1];
    if (s[i - 1] == 'W') {
      csum[i]++;
    }
  }

  int ans;
  for (int i = 0; i < n; ++i) {
    int cnt = cnt_w(csum, 0, i) + cnt_e(csum, i + 1, n);
    if (i == 0 || ans > cnt) {
      ans = cnt;
    }
  }

  cout << ans << '\n';

  return 0;
}