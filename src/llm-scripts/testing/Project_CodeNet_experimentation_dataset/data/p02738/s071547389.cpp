#include <bits/stdc++.h>
#define pb push_back
#define pll pair <ll, ll>
#define mp make_pair
#define pyshnapyshnakaa ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define x first
#define y second
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define plll pair <pair <ll, ll>, ll>
#define pllll pair <pair <ll, ll>, pair <ll, ll> >
#define psl pair <string, ll>
#define all(a) a.begin(), a.end()

typedef long long ll;

typedef long double ld;

using namespace std;

ll n, m, k, t;

const ll maxn = 6e3 + 100;
const ll shift = 2e3;

ll mod;

inline ll step(ll a, ll x) {
    if (x == 0) {
        return 1;
    }
    if (x % 2 == 1) {
        return step(a, x - 1) * a % mod;
    }
    ll t = step(a, x / 2);
    return t * t % mod;
}

inline ll del(ll a, ll b) {
    return a * step(b, mod - 2) % mod;
}

ll D[maxn][2 * maxn + 200]; /// s, 1 - 2

ll F[maxn];

ll R[maxn];

int main() {
    ll q, w, e, a, b, d;
    cin >> n >> mod;
    n *= 3;
    for (q = 1; q <= n; q++) {
        R[q] = del(1, q);
    }
    F[0] = 1;
    for (q = 1; q < maxn; q++) {
        F[q] = (F[q - 1] * q) % mod;
    }
    D[0][shift] = F[n];
    for (q = 0; q < n; q++) {
        for (w = 0; w < maxn * 2 + 100; w++) {
            for (e = 1; e <= 3; e++) {
                ll nw = w;
                if (e == 1) {
                    nw = nw + 1;
                }
                if (e == 2) {
                    nw = nw - 1;
                }
                if (q + e > maxn || nw > 3 * maxn || q + e < 0 || nw < 0) {
                    continue;
                }
                // D[q + e][nw] += del(D[q][w], q + e);
                D[q + e][nw] += D[q][w] * R[q + e] % mod;
                D[q + e][nw] %= mod;
            }
        }
    }
    ll ans = 0;
    for (q = 0; q < 2 * maxn + 200; q++) {
        if (q - shift >= 0) {
            ans += D[n][q];
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}
