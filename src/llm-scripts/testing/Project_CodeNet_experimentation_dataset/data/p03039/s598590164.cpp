#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;




// a^n mod を計算する
long int modpow(long int a, long int n, long int mod) {
    long int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

long int modcomb(long int a, long int b, long int mod){
    long int res = 1;
    for(long int i = a; i > a - b; i--){
        res *= i % mod;
        res %= mod;
    }
    res %= mod;
    for(long int i = 1; i <= b; i++){
        long int i_inv = modpow(i, mod - 2, mod);
        res *= i_inv % mod;
        res %= mod;
    }
    res %= mod;
    // cout << res << endl;
    return res;
}



int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll mod = 1000000007;
    ll combx = modcomb(n * m - 2, k - 2, mod);
    ll comby = modcomb(n * m - 2, k - 2, mod);
    ll ans = 0;
    rep(i, n){
        ans += (((((i * (n - i)) % mod) * m) % mod * m) % mod) * combx;
        ans %= mod;
    }
    rep(i, m){
        ans += (((((i * (m - i)) % mod) * n) % mod * n) % mod) * comby;
        ans %= mod;
    }
    cout << ans << endl;
}