#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;
ll power(ll n, ll k){
  ll res = 1;
  while(k > 0){
    if (k & 1) 
      res = res * n % MOD;
    n = n * n % MOD;
    k >>= 1;
  }
  return res;
}

ll genfact(ll n, ll k){

  ll res = 1;
  k--;
  while (k >= 0){
    res = (res * (n - k)) % MOD;
    k--;
  }

  return res;
}

ll inv(ll n){
  return power(n, MOD - 2);
}

ll fact(ll n){
  return genfact(n, n - 1);
}

ll nck(ll n, ll k){
  if (k == 0)
    return 1;
  if (n <= 0)
    return 0;

  return ((genfact(n, k) % MOD) * inv(fact(k))) % MOD;
}

int main(void){
  ll n, m, k;
  cin >> n >> m >> k;
  
  ll ans = 0;

  ll t = nck(n*m-2,k-2);
  for (ll j = 1; j < m; j++){
    ans += j*(m-j) % MOD * n % MOD *n % MOD * t % MOD;
    ans = (ans % MOD);
  }
  for (ll i = 1; i < n; i++){
    ans += i*(n-i) % MOD * m % MOD *m % MOD * t % MOD;
    ans = (ans % MOD);
  }
  cout << ans << endl;

  return 0;
}
