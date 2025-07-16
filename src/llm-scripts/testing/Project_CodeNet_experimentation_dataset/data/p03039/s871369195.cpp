#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

ll modPow(ll a, ll n) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % MOD;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % MOD;
  ll t = modPow(a, n / 2);
  return (t * t) % MOD;
}
ll modComb(ll n,ll a){
  ll x=1,y=1;
  rep(i,a){
    x*=n-i;
    x%=MOD;
    y*=i+1;
    y%=MOD;
  }
  y=modPow(y,MOD-2);
  return (x*y)%MOD;
}

int main(){
  ll N,M,K,ans=0,x;
  cin >> N >> M >> K;
  x=modComb(N*M-2,K-2);
  rep(i,N){
    ll k;
    k=i*(N-i);
    k%=MOD;
    k*=M;
    k%=MOD;
    k*=M;
    k%=MOD;
    k*=x;
    k%=MOD;
    ans+=k;
    ans%=MOD;
  }
  rep(i,M){
    ll k;
    k=i*(M-i);
    k%=MOD;
    k*=N;
    k%=MOD;
    k*=N;
    k%=MOD;
    k*=x;
    k%=MOD;
    ans+=k;
    ans%=MOD;
  }
  cout << ans << endl;
}