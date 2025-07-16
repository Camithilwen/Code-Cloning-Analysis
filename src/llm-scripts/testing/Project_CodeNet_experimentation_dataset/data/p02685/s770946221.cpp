#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define ff first
#define ss second
#define pb push_back
#define sz size()
#define mp make_pair
#ifndef ONLINE_JUDGE 
#include "/home/asif/Codes/Library/debug.h"
#endif
/*--------------------------------------------------------------------*/

const int N = 2e5 + 5;
const int MOD = 998244353;

namespace nCr {
  ll factorial[N], invFactorial[N];
  ll ncr(ll n, ll r){
    return (( (factorial[n] * invFactorial[r]) % MOD) * invFactorial[n - r]) % MOD;
  }
  void init(){
    invFactorial[1] = 1;
    for(int i = 2;i < N;i++)invFactorial[i] = MOD - (MOD / i) * invFactorial[MOD % i] % MOD;
    factorial[0] = factorial[1] = invFactorial[0] = 1;
    for(int i = 2; i < N; i++){
      factorial[i] = (factorial[i - 1] * i) % MOD;
      invFactorial[i] = (invFactorial[i - 1] * invFactorial[i]) % MOD;
    }
  }
}

ll bigmod(ll a, ll p){
  if(p == 0) return 1LL;
  ll ret = bigmod(a, p / 2);
  ret *= ret;
  ret %= MOD;
  if(p & 1) ret = (ret * a) % MOD;
  return ret;

}

int main() {

  ll n, m, k;
  cin >> n >> m >> k; 

  nCr::init();

  ll ans = 0LL;
  for(int i = 0; i <= k; i++){
    ans += (((nCr::ncr(n - 1, i) * bigmod(m - 1, n - i - 1)) % MOD) * m) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}