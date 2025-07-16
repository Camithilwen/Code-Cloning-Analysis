#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int const MOD = 998244353;

long long modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    ll MAX = 0;
    vector<ll> D(N, 0);
    rep(i, N) {
        ll d;
        cin >> d;

        if ((i == 0 && d != 0) || (i != 0 && d == 0)) {
            cout << 0 << endl;
            return 0;
        }

        MAX = max(MAX, d);
        ++D[d];
    }

    ll ans = 1;
    rep(i, MAX + 1) {
        if (i == 0) continue;

        if (D[i] == 0) {
            ans = 0;
            break;
        }

        ans = (ans * modpow(D[i - 1], D[i])) % MOD;
    }

    cout << ans << endl;
}