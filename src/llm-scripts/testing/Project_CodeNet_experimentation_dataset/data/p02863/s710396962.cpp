#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T>
using field = vector<vector<T>>;

template<class T> inline bool chmax(T& a,T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n,t;
  cin >> n >> t;
  vector<P> data(n);
  rep(i,0,n) {
    int a,b;
    cin >> a >> b;
    data[i] = P(a,b);
  }
  sort(data.begin(), data.end());
  field<int> dp(n+1,vector<int>(t+1,0));
  int ans = 0;
  rep(i,0,n) {
    int a = data[i].first, b = data[i].second;
    rep(j,0,t) {
      chmax(dp[i+1][j],dp[i][j]);
      if (j+a < t) {
        chmax(dp[i+1][j+a],dp[i][j]+b);
      }
    }
    chmax(ans,dp[i][t-1]+b);
  }
  cout << ans << endl;
  return 0;
}
