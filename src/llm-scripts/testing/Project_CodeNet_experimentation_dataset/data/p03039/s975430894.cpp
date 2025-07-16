#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// nCr mod p(n<p)をキビキビ計算する
// 構築:O(n), クエリ:O(1)
struct combination_mod {
    using lint = long long int;
    int sz;
    lint mod;
    vector<lint> fac;
    vector<lint> finv;
    combination_mod(int _sz, lint _mod) : sz(_sz), mod(_mod) {
        fac.assign(sz + 1, 1);
        finv.assign(sz + 1, 1);
        vector<lint> inv(sz + 1, 1);
        for (int i = 2; i <= sz; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    lint query(int n, int r) {
        return fac[n] * (finv[r] * finv[n - r] % mod) % mod;
    }
};

lint n, m, k;

int main() {
    cin >> n >> m >> k;
    lint mod = 1e9 + 7;
    combination_mod comb(m * n, mod);
    lint c = comb.query(m * n - 2, k - 2);
    lint ans = 0;
    for (lint i = 0; i < n; i++) {
        for (lint j = 0; j < m; j++) {
            lint M = (j * (j + 1) + (m - j) * (m - j - 1)) / 2;
            M %= mod;
            lint cand = 0;
            cand += M * n % mod;
            cand += i * (i + 1) / 2 % mod * m % mod;
            cand += (n - i) * (n - i - 1) / 2 % mod * m % mod;
            cand %= mod;
            cand *= c;
            cand %= mod;
            ans = (ans + cand) % mod;
        }
    }
    ans = (((lint)1e+9 + 8) / 2 * ans) % mod;
    cout << ans << endl;
}