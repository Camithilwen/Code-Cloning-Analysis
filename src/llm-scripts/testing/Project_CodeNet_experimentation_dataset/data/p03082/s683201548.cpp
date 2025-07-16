#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_X 200005

const int MAX = 510000;
const int MOD = 1000000007;
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

long long FINV(int n){
    if (n < 0) return 0;
    return finv[n];
}

ll dp[MAX_X];

int main() {
    int n, x;
    cin >> n >> x;
    int a[n];
    rep(i,n)cin >> a[i];
    sort(a,a+n);

    COMinit();

    int ite = lower_bound(a,a+n,x+1) - a;
    ite = n - ite;

    dp[x] = COM(n, ite) * fac[ite] % MOD;

    drep(i,MAX_X){
        if(dp[i] == 0)continue;
        if(i < a[0])break;
        drep(j,n){
            if(a[j] > i)continue;
            int after = i % a[j];
            int nn = 0;
            int kk = 0;
            rep(k,n){
                if(a[k] <= i){
                    nn++;
                    if(after < a[k])kk++;
                }
            }
            nn--;
            kk--;
            // cout << i << ' ' << a[j] << ' ' << after << ' ' << kk << ' ' << dp[i] * COM(nn, kk) << endl;
            dp[after] += dp[i] * COM(nn, kk) % MOD * fac[kk];
            dp[after] %= MOD;
        }
    }

    ll ans = 0;
    rep(i,a[0]){
        ans += dp[i] * i;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}

