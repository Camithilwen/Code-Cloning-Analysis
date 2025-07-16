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
  cin >> n;
  vector<int> l(n * 2);
  rep(i, 0, n * 2) cin >> l[i];
  sort(l.begin(), l.end());

  int ans = 0;
  rep(i, 1, n * 2) {
    ans += min(l[i], l[i - 1]);
    i++;
  }

  cout << ans << endl;
}
