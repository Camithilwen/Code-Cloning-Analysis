#include <bits/stdc++.h>
using namespace std;

const int64_t MAX = 510000;
const int64_t MOD = 1000000007;

int64_t fac[MAX], finv[MAX], inv[MAX];
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
int64_t COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  int64_t N,M,K;
  cin>>N>>M>>K;

  COMinit();
  int64_t ans=0;
  for(int i=0;i<N;++i){
    for(int j=0;j<M;++j){
      if(i!=0 && j!=0) ans += 2*(i+j)*(M-j)*(N-i);
      else ans += (i+j)*(M-j)*(N-i); 
      ans %= MOD;
    }
  }
  ans *= COM(N*M-2,K-2);
  cout<<ans%MOD<<endl;
}