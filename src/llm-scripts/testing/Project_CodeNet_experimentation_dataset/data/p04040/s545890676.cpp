#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

inline void normal(ll &a) { if (a >= MOD) a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) {normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) {normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) {normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; } //if MOD is prime, modPow(b, p % (MOD-1))
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }


const int mx = 1e6 + 9;

ll f[mx];

ll ncr(ll n, ll r) {
    return modDiv(f[n], modMul(f[r], f[n - r]));
}

ll total_path(ll r, ll c) {
    return ncr(r + c - 2, r - 1);
}

int main() {
    f[0] = 1;
    for (int i = 1; i < mx; i++) f[i] = modMul(i, f[i - 1]);
    ll h, w, a, b; cin >> h >> w >> a >> b;
    ll ttl = 0;

    for (ll i = 1; i <= h - a; i++) {
        ll temp = modMul(total_path(i, b), total_path(h - i + 1, w - b));
        ttl = modAdd(ttl, temp);
    }

    cout << ttl << endl;
}