#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 60);

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> dp(2, -INF);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    vector<ll> ndp(2, -INF);
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        int d = (j ^ k ? -a[i] : a[i]);
        ndp[k] = max(ndp[k], dp[j] + d);
      }
    }
    dp = move(ndp);
  }
  cout << dp[0] << endl;
  return 0;
} 