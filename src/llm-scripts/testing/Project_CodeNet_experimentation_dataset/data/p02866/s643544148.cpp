#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <set>
#include <functional>
#include <list>

#define MOD (1000000000 + 7)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> tup;
const int MAX = 3000000;

long long fac[MAX], finv[MAX], inv[MAX];

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}
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

map<ll,ll> prime;//素因数分解でそれぞれの素数がいくつ出てきたかを保存するmap

//O(√n)
//整列済み(mapはkeyで自動で整列される)
void prime_factorize(ll n){
    if(n<=1) return;
    ll l=sqrt(n);
   for(ll i=2;i<=(ll)(l);i++) { //
        if(n%i==0){
            prime_factorize(i);prime_factorize(ll(n/i));return;
        }
    }
    //mapでは存在しないkeyの場合も自動で構築される
    prime[n]++;return;
} 

vector<ll> divisor;
void list_divisor(ll n) {
    divisor.clear();
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            divisor.push_back(i);
            if(i*i != n) divisor.push_back(n/i);
        }
    }
    sort(divisor.begin(), divisor.end());
}

int main() {
    ll N;
    cin >> N;

    vector<ll> D(N, 0);
    map<ll, ll> m;
    ll maxv = 0;
    for(ll i = 0; i < N; i++) {
        cin >> D[i];
        m[D[i]]++;
        maxv = max(maxv, D[i]);
    }

    if(D[0] != 0 || m[0] >= 2) {
        cout << 0 << endl;
        return 0;
    }

    ll ret = 1;
    for(ll i = 1; i <= maxv; i++) {
        ret = (ret % 998244353) *  modpow(m[i-1], m[i], 998244353);
    }

    cout << ret%998244353 << endl;
}
