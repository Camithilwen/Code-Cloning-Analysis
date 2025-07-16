/// IN THE NAME OF METAL
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define sz(x)                       (ll) x.size()
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second

ll Pow(ll a, ll b, ll md, ll ans = 1) {
    for (; b; b >>= 1, a = a * a % md)
        if (b & 1)
            ans = ans * a % md;
    return ans % md;
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 998244353;
ll n, k, fact[MAXN], inv[MAXN], res[MAXN];

ll C(ll x, ll y) {
    if (x > y) return 0;
    return fact[y] * inv[x] % MOD * inv[y - x] % MOD;
}

int main() {
    fact[0] = inv[0] = 1;
    for (ll i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = Pow(fact[i], MOD - 2, MOD);
    }
    scanf("%lld%lld", &k, &n);
    for (ll i = 2; i <= 2 * k; i++) {
        ll ans = 0;
        for (ll j = 0; j <= i / 2; j++) {
            if (j & 1) {
                ans = (ans - C(n - j - j, k + n - j * 2 - 1) * C(j, i / 2) % MOD + MOD) % MOD;
            } else {
                ans = (ans + C(n - j - j, k + n - j * 2 - 1) * C(j, i / 2) % MOD) % MOD;
            }
        }
        res[i] = ans;
        if (i <= k + 1) printf("%lld\n", res[i]);
        else printf("%lld\n", res[k + k + 2 - i]);
    }
    return 0;
}

