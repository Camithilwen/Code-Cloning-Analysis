
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pint = pair<int, int>;

template <class T>
using vec = vector<T>;
template <class T>
using vec2 = vector<vec<T>>;
template <class T>
using vec3 = vector<vec2<T>>;

constexpr int INF = numeric_limits<int>::max();
constexpr ll INFL = numeric_limits<ll>::max();
//constexpr ll MOD = 1000000007; // 10^9+7
constexpr ll MOD = 998244353;

#define rep(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)

template <class T>
bool chmax(T &a, const T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

vector<long long> fac, finv, inv;

// テーブルを作る前処理
void COMinit(int max)
{
    fac.resize(max);
    finv.resize(max);
    inv.resize(max);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < max; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll modpow(ll x, ll n, const ll &mod)
{
    ll ret = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            (ret *= x) %= mod;
        }
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

ll N, M, K;

ll solve()
{
    ll ret = 0;
    for (int k = 0; k <= K; ++k)
    {
        ll a = 1;
        a *= M;
        a %= MOD;
        a *= modpow(M - 1, N - 1 - k, MOD);
        a %= MOD;
        a *= COM(N - 1, k);
        a %= MOD;
        ret += a;
        ret %= MOD;
    }
    return ret;
}

int main()
{
    COMinit(2 * 100000);
    cin >> N >> M >> K;
    cout << solve() << endl;
    return 0;
}
