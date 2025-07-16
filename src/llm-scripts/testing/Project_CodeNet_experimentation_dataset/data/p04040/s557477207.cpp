#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

namespace IO {
    template <typename _T>
    inline bool read (_T& x) {
        x = 0;
        _T y = 1;
        char c = getchar();
        while ((c < '0' || '9' < c) && c != EOF) {
            if (c == '-') y = -1;
            c = getchar();
        }
        if (c == EOF) return false;
        while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
        x *= y;
        return true;
    }

    template <typename _T>
    inline _T input () {
        _T x = 0, y = 1;
        char c = getchar();
        while ((c < '0' || '9' < c) && c != EOF) {
            if (c == '-') y = -1;
            c = getchar();
        }
        if (c == EOF) return 0;
        while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
        x *= y;
        return x;
    }
};
using namespace IO;

namespace modular {
    const int MOD = 1000000007;

    inline int add (int x, int y) { return (x += y) >= MOD ? x -= MOD : x; }

    inline void inc (int &x, int y) { (x += y) >= MOD ? x -= MOD : 0; }

    inline int mul (int x, int y) { return 1LL * x * y % MOD; }

    inline int qpow (int x, int y) {
        int ans = 1;
        for (; y; y >>= 1, x = mul(x, x)) if (y & 1) ans = mul(ans, x);
        return ans;
    }
};
using namespace modular;

#define reg register
#define MAX_N 200007
#define FIN(s) freopen(s, "r", stdin)
#define FOUT(s) freopen(s, "w", stdout)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define lep(i, l, r) for(int i = l; i < r; ++i)
#define irep(i, r, l) for(int i = r; i >= l; --i)
#define ilep(i, r, l) for(int i = r; i > l; --i)
typedef long long ll;

int N, M, A, B;
int fac[MAX_N], ifac[MAX_N];

inline int C (int x, int y) {
    if (x < y || y < 0) return 0;
    return mul(fac[x], mul(ifac[y], ifac[x - y]));
}

inline void init () {
    int MX = 200000;
    fac[0] = ifac[0] = 1;
    rep (i, 1, MX) fac[i] = mul(fac[i - 1], i);
    ifac[MX] = qpow(fac[MX], MOD - 2);
    irep (i, MX, 2) ifac[i - 1] = mul(ifac[i], i);
}

int main () {
#ifdef LOCAL
    FIN("in");
#endif
    init();
    read(N), read(M), read(A), read(B);
    int res = 0;
    rep (i, 1, B) inc(res, mul(C(N - A - 1 + i - 1, i - 1), C(A - 1 + M - i, M - i)));
    res = add(C(N + M - 2, N - 1), MOD - res);
    printf("%d\n", res);
    return 0;
}
