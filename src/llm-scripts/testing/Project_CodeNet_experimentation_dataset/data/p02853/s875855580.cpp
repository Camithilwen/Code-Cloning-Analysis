#include <iostream>
#include <cstring>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <numeric>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <climits>
#include <bitset>
#include <utility>


using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//最大公約数
ll gcd(ll x, ll y) {
    ll tmp = 0;
    if (x < y){
        tmp=x;
        x=y;
        y=tmp;
    }
    while (y > 0) {
        ll r = x % y;
        x = y;
        y = r;
        }
    return x;
}

//最大公倍数
ll lcm(ll x,ll y){
    return x/gcd(x,y)*y;
}

const int MAX = 1e6+1;
const ll MOD = 1e9+7;

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


//階乗
ll kaijo(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
        sum%=1000000000+7;
    }
    return sum;
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

//sieve(MAX);でベクトルIsPrimeに「MAXまでの数値の素数の真偽」を格納する。
vector<bool> IsPrime;
void sieve(size_t max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    } 
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(size_t i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(size_t j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}

struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) { }
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x) {
        return -par[root(x)];
    }
};

ll count(int n, int a){
    ll bunshi = 1;
    for(int i = 0; i < a; i++){
        bunshi*=(n-i);
        bunshi%=MOD;
    }
    ll bunbo = 1;
    for(int i = 1; i < a+1; i++){
        bunbo*=i;
        bunbo%=MOD;
    }
    bunbo = modpow(bunbo,MOD-2,MOD);
    // cout<<(bunshi*bunbo)%MOD<<endl;
    return (bunshi*bunbo)%MOD;
}

// 約数列挙。約数をvector<ll>で返す。計算量はsqrt(n)。
vector<ll> divisor(ll n) {
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
        ret.push_back(i);
        if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

// ここから開始
int main(){
    int x,y;
    cin>>x>>y;
    int a[3] = {300000,200000,100000};
    ll ans = 0;
    if(0<x&&x<4){
        ans+=a[x-1];
    }
    if(0<y&&y<4){
        ans+=a[y-1];
    }
    if(x==1&&y==1){
        ans+=400000;
    }
    cout<<ans<<endl;
    return 0;
}
