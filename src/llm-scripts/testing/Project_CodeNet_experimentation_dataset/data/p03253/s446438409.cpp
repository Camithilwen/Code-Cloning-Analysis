#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

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
  ll n, m;
  cin >> n >> m;

  vector<ll> divisor(0);
  for (int i = 2; i*i <= m; i++){
    if (m % i == 0){
      int t = 0;
      while (m % i == 0){
        m /= i;
        t++;
      }
      divisor.push_back(t);
    }
  }
  if (m != 1){
    divisor.push_back(1);
  }


  ll ans = 1;
  for (int i = 0; i < divisor.size(); i++){
    ans = ans * nck(n + divisor[i] - 1, divisor[i]) % MOD;
  }
  cout << ans << endl;
  

  return 0;
}

