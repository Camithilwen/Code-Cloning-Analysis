#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 2000000;
const int MOD = 998244353;
//
int fac[MAX], finv[MAX], inv[MAX];

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
int COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
signed main() {
 int n,m;
 cin>>n>>m;
 COMinit();
 int ans=n*COM(m+n-2,m)%MOD;
 for(int i=m;3*m-2*i>=0;i++){
     ans=(ans + (COM(i+n-1,i) +(MOD - n*COM(i-m+n-1,i-m)%MOD))*COM(n,3*m-2*i)%MOD)%MOD;
 }
 cout<<ans;
}
