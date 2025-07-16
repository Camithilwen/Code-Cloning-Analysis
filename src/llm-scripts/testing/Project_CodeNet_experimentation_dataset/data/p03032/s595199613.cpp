#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  rep(i, 0, n) cin >> v[i];

  ll ans = 0;
  rep(l, 0, k + 1) {
    rep(r, 0, k - l + 1) {
      if (l + r > n)
        continue;
      int d = k - l - r;
      ll now = 0;
      vector<int> s;
      rep(i, 0, l) {
        now += v[i];
        s.push_back(v[i]);
      }
      rep(i, n - r, n) {
        now += v[i];
        s.push_back(v[i]);
      }

      sort(s.begin(), s.end());
      rep(i, 0, d) {
        if (i >= s.size() || s[i] > 0)
          break;
        now -= s[i];
      }

      ans = max(ans, now);
    }
  }

  cout << ans << endl;
}
