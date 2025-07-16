#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

const int MAX_k = 200010;
const int mod = 998244353;
ll com[MAX_k];
ll fac[MAX_k], inv[MAX_k], finv[MAX_k];

void cominit(int n){
  com[0] = 1;
  com[1] = n;
  fac[0] = 1;
  fac[1] = n;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  rep(i, 2, MAX_k){
    fac[i] = fac[i-1]*(n-i+1) %mod;
    inv[i] = mod - inv[mod%i]*(mod/i) %mod;
    finv[i] = finv[i-1]*inv[i] %mod;
    com[i] = fac[i]*finv[i] %mod;
  }
}

ll modPow(int a, int n, int mod){
  if(n == 0)
    return 1;
  if(n%2 == 0){
    ll t = modPow(a, n/2, mod);
    return t*t%mod;
  }
  ll t = modPow(a, n-1, mod);
  return a*t%mod;
}

int main(){
  int n, m, k;
  cin >> n >> m >> k;
  
  ll ans = 0;
  
  cominit(n-1);
  
  rep(i, 0, k+1){
    ll t = m;
    t = t*com[i]%mod;
    t = t*modPow(m-1, n-i-1, mod)%mod;
    ans = (ans + t)%mod;
  }
  
  cout << ans << endl;
  
  return 0;
  
}