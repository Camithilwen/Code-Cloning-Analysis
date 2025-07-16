#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 200010 };
const ll MOD { 998244353 }, oo { 1LL << 62 };

ll fs[MAX];

ll st[MAX][2];

void precomp()
{
    fs[0] = fs[1] = 1;

    for (ll i = 2; i < MAX; ++i)
        fs[i] = (fs[i - 1] * i) % MOD;
}

ll mod_pow(ll a, ll n)
{
    ll res = 1, base = a;

    while (n)
    {
        if (n & 1)
            res = (res * base) % MOD;

        base = (base * base) % MOD;
        n >>= 1;
    }

    return res;
}

ll inv(ll N)
{
    return mod_pow(N, MOD - 2);
}

ll C(ll N, ll M)
{
    auto res = (fs[N] * inv(fs[N - M])) % MOD;
    res = (res * inv(fs[M]) % MOD);

    return res;
}


ll solve(ll N, ll M, ll K)
{
    auto ans = mod_pow(M - 1, N - 1);
    ans = (ans * M) % MOD;

#ifdef DEBUG
    cout << "--- ans = " << ans << endl;
#endif
    for (ll i = 1; i <= K; ++i)
    {
        ll res = (C(N - 1, i) * mod_pow(M - 1, N - 1 - i)) % MOD;
        res = (M * res) % MOD;
        ans = (ans + res) % MOD;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    precomp();

    ll N, M, K;
    cin >> N >> M >> K;

    auto ans = solve(N, M, K);

    cout << ans << '\n';

    return 0;
}
