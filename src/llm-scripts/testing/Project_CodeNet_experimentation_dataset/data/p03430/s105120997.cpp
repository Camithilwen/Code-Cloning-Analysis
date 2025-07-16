#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 305;
int dp[N][N][N];

int main(){
  fastIO;
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();
  for(int i = 0 ; i < n; i ++ ){
    dp[i][i][0] = 1;
    if(i + 1 < n){
      if(s[i] == s[i + 1]){
        dp[i][i + 1][0] = 2;
      }
      else{
        dp[i][i + 1][0] = 1;
        dp[i][i + 1][1] = 2;
      }
    }
  }
  int r;
  int cost;
  for(int len = 3; len <= n; len ++ ){
    for(int l = 0 ; l + len - 1 < n; l ++ ){
      r = l + len - 1;
      for(int t = 0 ; t <= k ; t ++ ){
        dp[l][r][t] = max(dp[l][r-1][t], dp[l+1][r][t]);
        cost = (s[l] != s[r]);
        if(t - cost >= 0){
          dp[l][r][t] = max(dp[l][r][t], dp[l+1][r-1][t - cost] + 2);
        }
      }
    }
  }
  int ans = 0;
  for(int t = 0 ;t <= k ; t ++ ) ans = max(ans, dp[0][n-1][t]);
  cout << ans << "\n";
  return 0;
}