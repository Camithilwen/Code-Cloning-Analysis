#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const int MAX = 510000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
long long COM(int n, int k){
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll mypow(ll a, ll b){
  ll res = 1;
  a %= mo;
  while (b)
  {
    if (b & 1)
      res = res * a % mo;
    a = a * a % mo;
    b >>= 1;
  }
  return res;
}
int main()
{
ll n ;
cin >> n ;
ll a , b , c , d ;
cin >> a >> b >> c >> d ;
COMinit();
vector<vector<ll>> dp(b-a+2, vector<ll>(n+1,0) );

dp[0][0]=1;
rep(i,b-a+1)rep(j,n+1){
  ll te=dp[i][j];
  for (ll k = 0; k <= d && j+k*(i+a)<=n ; k++)
  {
    if(te==0)break;
    if(k){
      te*=COM(n-j-(k-1)*(i+a),i+a);
      te%=mo;
      te*=mypow(k,mo-2);
      te%=mo;
    }
    te%=mo;
    if(k==0 || k>=c)dp[i+1][j+k*(i+a)]=(dp[i+1][j+k*(i+a)]+te)%mo;
  }
  
}

cout << dp[b-a+1][n]%mo << endl;
return 0;
}