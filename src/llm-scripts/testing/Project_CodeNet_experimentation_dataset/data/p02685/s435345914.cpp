#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

const int MOD=998244353;
const int MAX=200005;

long long fac[MAX], finv[MAX], inv[MAX];

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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  ll n,m,k;
  cin>>n>>m>>k;
  COMinit();
  
  ll ans=0;
  ll a=m;
  rep(i,n-1-k) a=a*(m-1)%MOD;
  rep(i,k+1){
    ans=(ans+COM(n-1,k-i)*a%MOD)%MOD;
    a=a*(m-1)%MOD;
  }
  cout<<ans<<endl;
  return 0;
}
