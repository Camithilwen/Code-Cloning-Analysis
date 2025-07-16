#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e5 + 9;
const int LOG = 40;
const int MOD = (int)1e9 + 7;

int dp[N][LOG];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  dp[0][0] = 1;
  int s;
  for(int i = 1; i <= n; i ++ ){
    s = 0;
    for(int j = 0 ; j < LOG; j ++ ){
      s += dp[i - 1][j];
      s %= MOD;
      dp[i][j] = s;
    }
  }
  int cnt;
  int ans = 1;
  for(int i = 2; i * i <= m ; i ++ ){
    if(m % i != 0) continue;
    cnt = 0;
    while(m % i == 0){
      cnt ++ ;
      m /= i;
    }
    ans = (ans * 1ll * dp[n][cnt]) % MOD;
  }
  if(m != 1) ans = (ans * 1ll * dp[n][1]) % MOD;
  cout << ans << "\n";
  return 0;
}