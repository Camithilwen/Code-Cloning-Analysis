#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef vector<double> VD;
typedef vector<VD> VVD;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

const ll mod = 998244353;
const int N = 2500010;
ll fact[N], invf[N];

ll add(ll x, ll y){
    return (x+y)%mod;
}

ll mul(ll x, ll y){
    return (x%mod)*(y%mod)%mod;
}

ll powll(ll x, ll y){
    x %= mod;
    ll res = 1LL;
    while(y){
        if (y & 1LL)
            res *= x;
        res %= mod;
        x = (x*x) % mod;
        y >>= 1LL;
    }
    return res;
}

ll divll(ll x, ll y){
    return (x * powll(y,mod-2)) % mod;
}

ll nPr(ll n, ll r){
    if (n < r || r < 0) return 0;
    return mul(fact[n], invf[n-r]);
}

ll nCr(ll n, ll r){
    if (n < r || r < 0) return 0;
    return mul(mul(fact[n], invf[r]), invf[n-r]);
}

int main() {
    ll n, m;
    cin >> n >> m;
    fact[0] = invf[0] = 1;
    FOR(i,1,N-1){
        fact[i] = (fact[i-1] * i) % mod;
    }
    invf[N - 1] = divll(1, fact[N - 1]);
    FORR(i,N-1,1){
        invf[i - 1] = (invf[i] * i) % mod;
    }

    ll ans = 0;
    REP(x,m+1){
        if ((3 * m - x) % 2) continue;
        ll tmp = (nCr(n, x) * nCr(n + (3 * m - x) / 2 - 1, n - 1)) % mod;
        ans = (ans + tmp) % mod;
    }
    REP(i,m){
        ll tmp = (n * nCr(n + i - 2, n - 2)) % mod;
        ans = (ans - tmp + mod) % mod;
    }
    cout << ans << endl;

    return 0;
}
