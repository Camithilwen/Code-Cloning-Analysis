#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void _inc(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void _dec(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int _binpow(int x, int p) {
    int res = 1;
    int tmp = x;
    while (p > 0) {
        if (p & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        p >>= 1;
    }
    return res;
}

const int N = 3e6 + 5;

int fact[N];
int rfact[N];

void precalc() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = _mul(fact[i - 1], i);
    }
    rfact[N - 1] = _binpow(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        rfact[i] = _mul(rfact[i + 1], i + 1);
    }
}

inline int CNK(int n, int k) {
    if (n < k) {
        return 0;
    }
    return _mul(fact[n], _mul(rfact[n - k], rfact[k]));
}

inline int F(int n, int k) {
    return CNK(n + k - 1, k);
}

int main() {

    precalc();

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m;

    cin >> n >> m;

    int res = 0;

    for (int i = m & 1; i <= m; i += 2) {
        _inc(
            res,
            _mul(
                CNK(n, i),
                F(n, (3 * m - i) / 2)
            )
        );
    }

    _dec(
        res,
        _mul(
            n,
            F(n, m - 1)
        )
    );

    cout << res << "\n";

    return 0;
}