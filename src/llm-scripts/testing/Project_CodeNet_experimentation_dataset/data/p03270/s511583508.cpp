#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 998244353;
const int MAX = 510000;
const int MOD = 998244353;
long long fac[MAX], finv[MAX], inv[MAX];
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
int main()
{
ll k , n ;
cin >> k >> n ;
vector<ll> ans(2*k-1);
COMinit();
for (ll i = 2; i <= 2*k; i++)
{
  ll kk;
  if(i<k+1)kk=i-1;
  else kk=2*k+1-i;
  if(i%2){
    rep(j,kk/2+1){
      ll te=COM(kk/2,j)*mypow(2,j);
      te%=mo;
      te*=COM(n-j+j+k-kk-1,j+k-kk-1);
      te%=mo;
      ans[i-2]+=te;
      ans[i-2]%=mo;
    }
  }
  else{
    rep(j,kk/2+1){
      ll te=COM(kk/2,j)*mypow(2,j);
      te%=mo;
      te*=COM(n-j+j+k-kk-1,j+k-kk-1);
      te%=mo;
      ans[i-2]+=te;
      ans[i-2]%=mo;
    }
    rep(j,kk/2+1){
      ll te=COM(kk/2,j)*mypow(2,j);
      te%=mo;
      te*=COM(n-j+j+k-kk-1-1,j+k-kk-1);
      te%=mo;
      ans[i-2]+=te;
      ans[i-2]%=mo;
    }
  }
}

for(auto a:ans){
  cout << a << endl;
  
}
return 0;
}