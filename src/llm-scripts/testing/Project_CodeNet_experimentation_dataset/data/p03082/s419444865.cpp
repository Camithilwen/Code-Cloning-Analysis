#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#include <ctime>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 1LL << 62
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

ll pow_mod(ll a, ll b, ll m){
    ll ret = 1;
    while (b > 0) {
        if (b & 1) {
            ret = ret * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ret;
}

ll inv_mod(ll a, ll m){
    return pow_mod(a, m - 2, m);
}

const int MAX_M = 100001;

ll f[MAX_M];

void calc() {
    f[0] = 1;
    rep(i, 1, MAX_M) {
        f[i] = f[i - 1] * i;
        f[i] %= mod;
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    calc();
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(all(A));
    reverse(all(A));
    
    vector<ll> dp(MAX_M);
    vector<ll> tmp(MAX_M);
    dp[X] = 1;
    rep(i, N) {
        tmp.assign(MAX_M, 0);
        ll inv = inv_mod(N - i, mod);
        rep(j, MAX_M) {
            tmp[j % A[i]] += dp[j] * inv % mod;
            tmp[j % A[i]] %= mod;
            tmp[j] += (dp[j] * inv % mod) * (N - i - 1) % mod;
            tmp[j] %= mod;
        }
        dp = tmp;
    }
    
    ll ans = 0;
    rep(i, MAX_M) {
        ans += dp[i] * i;
        ans %= mod;
    }
    ans *= f[N];
    ans %= mod;
    output(ans);
    
    return 0;
}

