#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  int n, m;
  cin >> n >> m;
  vi a(m);
  rep(i, m) cin >> a[i];
  sort(all(a), greater<int>());
  vi v = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  vi dp(n + 10, -1);
  dp[0] = 0;
  rep(i, n) rep(j, m) {
    if(dp[i] == -1) continue;
    dp[i + v[a[j]]] = max(dp[i + v[a[j]]], dp[i] + 1);
  }
  string ans;
  int i = n;
  while(i) {
    for(int j : a) {
      if(i - v[j] >= 0 && dp[i - v[j]] == dp[i] - 1) {
        i -= v[j];
        ans += char('0' + j);
        break;
      }
    }
  }
  cout << ans << endl;
}