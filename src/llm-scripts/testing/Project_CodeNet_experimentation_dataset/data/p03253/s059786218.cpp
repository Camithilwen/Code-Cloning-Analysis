#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int MAX = 410000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
//invの要素にはiの逆元が格納されている
//前処理
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;//i!(mod MOD)を計算
        inv[i] = MOD - inv[MOD%i]* (MOD / i) % MOD;//iの逆元を計算
        finv[i] = finv[i - 1] * inv[i] % MOD;//i!(mod MOD)の逆元を計算
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;//nCk = n!/(k!*(n-k)!)を計算
}
//例のアレ
long long nPm(int n, int m){
    if(n < m) return 0;
    if(n < 0 || m < 0) return 0;
    return fac[n] * finv[n - m] % MOD;
}
map<long long, long long> divide(long long n){//素因数分解
    map<long long, long long> res;
    for(long long i = 2; i * i <= n; i++){
        while(n % i == 0){
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}
int main(){
    int N;
    long long M;
    cin >> N >> M;
    COMinit();
    map<long long, long long> m = divide(M);
    long long ans = 1;
    for(auto v: m){
        ans = ans * COM(v.second + N - 1, v.second) % MOD;
    }
    cout << ans << endl;
}