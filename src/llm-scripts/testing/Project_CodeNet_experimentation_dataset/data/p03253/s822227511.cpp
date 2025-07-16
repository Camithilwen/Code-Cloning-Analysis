#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
const long long MAX = 10000000;
const long long MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (long long i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        //そのまま計算すると負の値になるのでMODを足す
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long COM(long long n, long long k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
    COMinit();
    long long a, b;
    cin >> a >> b;
    map<long long, long long> v;
    long long tmpb = b;
    for(long long i=2;i*i<=b;i++) {
        while(tmpb % i == 0) {
            tmpb /= i;
            v[i] += 1;
        }
    }
    if(tmpb!=1) v[tmpb] += 1;
    long long ans = 1;
    for(auto m:v) {
        //cout << m.first << " " << m.second << endl;
        ans = (ans * COM(m.second+a-1, a-1))%MOD;
    }
    cout << ans << endl;
} 
/*
2 2 3


a1b2 b1b2 c1c2
a1+b1+b2 = 2
a2+b2+c2 = 1
*/