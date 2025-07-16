/*
[arc102] E - Stop. Otherwise...
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_Z = 2000 * 2 + 2;
const ll MOD = 998244353;

int K, N;
int fact[MAX_Z + 1];
int ifac[MAX_Z + 1];
int pow2[MAX_Z + 1];

void prepare() {
    int inv[MAX_Z + 1];
    fact[1] = fact[0] = 1;
    ifac[1] = ifac[0] = 1;
    inv[1] = 1;
    for (int i = 2; i <= MAX_Z; i++) {
        fact[i] = 1LL * i * fact[i - 1] % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        ifac[i] = 1LL * ifac[i - 1] * inv[i] % MOD;
    }

    pow2[0] = 1;
    for (int i = 1; i <= MAX_Z; i++) {
        pow2[i] = (2LL * pow2[i - 1]) % MOD;
    }
}

int comb(int n, int r) {
    if (n < 0 || r < 0 || n < r) {
        return 0;
    }
    return (1LL * fact[n] * ifac[n - r]) % MOD * ifac[r] % MOD;
}
int hcomb(int n, int r) {
    if (n == 0 && r == 0) {
        return 1;
    }
    return comb(n + r - 1, r);
}

ll solve(int t) {
    ll ans = 0;

    int p = 0;
    for (int j = 1; j <= K; j++) {
        if (j < t - j && t - j <= K) p++;
    }

    for (int q = 0; q <= min(N, p); q++) {
        ll c = (1LL * pow2[q] * comb(p, q)) % MOD;
        if (t % 2 == 0) {
            (c *= ((hcomb(K - 2 * p + q - 1, N - q) +
                    hcomb(K - 2 * p + q - 1, N - q - 1)) %
                   MOD)) %= MOD;
        } else {
            (c *= hcomb(K - 2 * p + q, N - q)) %= MOD;
        }
        (ans += c) %= MOD;
    }

    return ans;
}

int main() {
    cin >> K >> N;

    prepare();

    for (int t = 2; t <= 2 * K; t++) {
        cout << solve(t) << endl;
    }

    return 0;
}
