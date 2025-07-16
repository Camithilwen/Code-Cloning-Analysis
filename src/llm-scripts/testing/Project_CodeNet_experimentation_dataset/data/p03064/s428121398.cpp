#include <iostream>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

int n;
int a[305];
ll dp[305][90005];
ll dp2[305][90005];

ll p(ll a, ll x) {
  ll res = 1;
  while(x > 0) {
    if(x & 1) res = res * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return res;
}

int main() {
  cin >> n;
  int sum = 0;
  int maxa = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    maxa = max(maxa,a[i]);
  }

  dp[0][0] = 1;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i * maxa; j++) {
      if(dp[i][j] == 0) continue;
      dp[i+1][j] = (dp[i+1][j] + dp[i][j] * 2) % mod;
      dp[i+1][j+a[i]] = (dp[i+1][j+a[i]] + dp[i][j]) % mod;
			 
    }
  }
  dp2[0][0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i * maxa; j++) {
       if(dp2[i][j] == 0) continue;
      dp2[i+1][j] = (dp2[i+1][j] + dp2[i][j]) % mod;
      dp2[i+1][j+a[i]] = (dp2[i+1][j+a[i]] + dp2[i][j]) % mod;
    }
  }

  ll ans = p(3,n);
  for(int i = 0; i <= n * maxa; i++) {
    if(i >= sum - i) {
      ans = (ans + mod - dp[n][i] * 3 % mod) % mod;
    }
    if(i == sum - i) {
      ans = (ans + dp2[n][i] * 3 % mod) % mod;
    }
  }
  if(ans < 0 ) cout << ans + mod << endl;
  else 
  cout << ans << endl;
}
				 
  
  


  
  
