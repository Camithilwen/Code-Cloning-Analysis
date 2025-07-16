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
  vi b = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  vi dp(n + 1, -1);
  dp[0] = 0;
  rep(j, n) rep(i, m) {
    if(dp[j] == -1) continue;
    int nj = j + b[a[i]];
    if(nj <= n) dp[nj] = max(dp[nj], dp[j] + 1);
  }
  int j = n;
  string ans = "";
  while(j) {
    int num = 0;
    rep(i, m) {
      int nj = j - b[a[i]];
      if(nj >= 0 && dp[nj] == dp[j] - 1) num = max(num, a[i]);
    }
    ans.push_back((char)(num + '0'));
    j -= b[num];
  }
  cout << ans << endl;
}