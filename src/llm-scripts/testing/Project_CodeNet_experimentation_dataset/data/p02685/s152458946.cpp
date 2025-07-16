#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

const int mod = 998244353;

int n;
int m;
int k;

long long inv[N];
long long fac[N];
long long finv[N];

void cominit(){
    fac[0] = fac[1] =1;
    finv[0] = finv[1] =1;
    inv[1] = 1;
    for(int i = 2; i < N; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i]= mod - inv[mod % i] * (mod / i) % mod;
        finv[i]= finv[i - 1] * inv[i] % mod;
    }
}

long long nCr(long long n , long long r){
    if(n < r)
        return 0;
    if(n < 0 || r < 0)
        return 0;
    return fac[n] * (finv[r] * finv[n - r] % mod) %mod;
}

int fastP(int b, int e){
    if(!e)
        return 1;
    if(e & 1)
        return b * 1ll * fastP(b * 1ll * b % mod, e >> 1) % mod;
    return fastP(b * 1ll * b % mod, e >> 1) % mod;
}

void mul(long long & a , long long b){
    a *= b;
    a %= mod;
}

int main(){
    scanf("%d%d%d" , &n , &m , &k);
    cominit();
    long long ways = 0;
    for(int i = 0; i <= k; i++){
        long long sofar = 1;
        mul(sofar , m);
        mul(sofar , fastP(m - 1 , n - 1 - i));
        mul(sofar , nCr(n - 1 , i));
        ways += sofar;
        ways %= mod;
    }
    printf("%lld\n" , ways);
}
