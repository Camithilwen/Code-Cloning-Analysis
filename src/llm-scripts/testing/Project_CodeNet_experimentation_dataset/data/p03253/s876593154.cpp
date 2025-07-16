#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
//#define INF 1e18
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX]; //n!, 1/n!, 1/n

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(ll n, ll k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

map<ll,ll> prime_factor(ll n){
  map<ll,ll> res;
  for(ll i=2;i*i<=n;i++){
    while(n%i==0){
      ++res[i];
      n /= i;
    }
  }
  if(n!=1) res[n] = 1;
  return res;
}

int main(){
  ll n,m;
  cin >> n >> m;
  COMinit();
  ll ans=1;
  map<ll,ll> M = prime_factor(m);
  for(auto p : M){
    ll k = p.second;
    ans *= COM(n+k-1,k);
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}
