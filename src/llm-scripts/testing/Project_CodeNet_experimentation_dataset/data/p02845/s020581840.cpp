#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> dp(n+1);
  dp[0] = 1;
  vector<int> clr(3, 0);
  rep(i, n) {
    int c = 0;
    rep(ci, 3) if (clr[ci] == a[i]) ++c;
    dp[i+1] = (ll)dp[i] * c % MOD;
    rep(ci, 3) {
      if (clr[ci] == a[i]) {
        clr[ci]++;
        break;
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}