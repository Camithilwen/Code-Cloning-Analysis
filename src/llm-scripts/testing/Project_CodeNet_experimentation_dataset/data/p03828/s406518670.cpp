#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC052 C - Factors of Factorial
// 2020.06.13

ll MOD = 1e9+7;

map<ll, ll> PrimeFac(ll n){
  map<ll, ll> mp;
  ll cnt = 0;
  while(n%2 == 0){
    n /= 2;
    cnt++;
  }
  if(cnt != 0) mp[2] = cnt;
  for(ll i = 3; i*i <= n; i += 2){
    cnt = 0;
    while(n%i == 0){
      n /= i;
      cnt++;
    }
    if(cnt != 0) mp[i] = cnt;
  }
  if(n != 1) mp[n] = 1;
  return mp;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  if(N == 1){
    cout << 1 << endl;
    return 0;
  }
  map<ll, ll> res;
  for(ll i = 2; i <= N; i++){
    map<ll, ll> tmp;
    tmp = PrimeFac(i);
    for(auto j : tmp){
      res[j.first] += j.second;
      res[j.first] %= MOD;
    }
  }
  ll ans = 1;
  for(auto i : res){
    ans = (ans*(i.second+1))%MOD;
  }
  ans %= MOD;
  cout << ans << endl;
}