#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;

  vector<int> w(n + 1, 0), e(n + 1, 0);
  rep(i, 0, n) {
    if (s[i] == 'W')
      w[i + 1] = w[i] + 1;
    else
      w[i + 1] = w[i];
  }

  repr(i, 0, n) {
    if (s[i] == 'E')
      e[i] = e[i + 1] + 1;
    else
      e[i] = e[i + 1];
  }

  int ans = 1e9;
  rep(i, 1, n + 1) {
    // test
    chmin(ans, w[i - 1] + e[i]);
  }

  cout << ans << endl;
}
