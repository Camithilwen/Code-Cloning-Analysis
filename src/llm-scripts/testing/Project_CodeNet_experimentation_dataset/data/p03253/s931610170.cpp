#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

vector < ll > fact(N);

ll pwr(ll a, ll b){
  ll res = 1;
  while(b > 0){
    if(b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

ll inv(ll a){
  return pwr(a, mod - 2);
}

ll comb(int n, int r){
  return (((fact[n] * inv(fact[n - r]) % mod) * inv(fact[r])) % mod);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  fact[0] = 1;
  for(int i = 1; i < N; i++) fact[i] = (i * fact[i - 1]) % mod;

  int n, m;
  cin >> n >> m;

  ll ans = 1;
  for(int i = 2; i <= sqrt(m); i++){
    if(m % i == 0){
      int cnt = 0;
      while(m % i == 0){
        cnt++;
        m /= i;
      }
      ans = (ans * comb(n + cnt - 1, n - 1)) % mod;
    }
  }
  if(m > 1){
    ans = (ans * n) % mod;
  }

  cout << ans << '\n';
}
