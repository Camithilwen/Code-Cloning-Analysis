#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
//O(k)愚直,nは大きいがkがそうでもないときに思い出す
long long modpow(long long x,long long n,long long mod){
    long long res = 1;
    while(n > 0) {
        if(n & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return res;
}
long long modinv(long long x, long long mod){
     return modpow(x, mod - 2, mod); }
long long modcomb(long long n,long long r,long long mod){
    long long numerator = 1;
    for(long long i = 0; i < r; i++) {
        (numerator *= (n - i)) %= mod;
    }
    long long denominator = 1;
    for(long long i = 1; i <= r; i++) {
        (denominator *= i) %= mod;
    }
    denominator = modinv(denominator, mod);
    return numerator * denominator % mod;
}
int main(){
    ll n, k;
    cin >> n >> k;
    cout << n - k + 1 << endl;
}