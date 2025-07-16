#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll modpow(ll a,ll n,ll mod){
  if(n == 0) return 1LL;
  if(n % 2 == 0){
    ll d = modpow(a,n/2,mod) % mod;
    return (d*d) % mod;
  }
  return (a % mod) * (modpow(a,n-1,mod) % mod) % mod;
}

int main(){
  ll n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  ll sum = 0;
  ll times = 0;
  while(times < 65){
    ll cnt1 = 0,cnt0 = 0;
    ll b_sum = 0;
    for(int i = 0; i < n; i++){
      if(a[i] % 2 == 1) cnt1++;
      a[i]/=2;
    }
    cnt0 = n-cnt1;
    b_sum = cnt0*cnt1%MOD;
    ll res = modpow(2,times,MOD)*b_sum;
    sum += res%MOD;
    sum %= MOD;
    times++;
  }
  cout << sum << endl;
  return 0;
}
