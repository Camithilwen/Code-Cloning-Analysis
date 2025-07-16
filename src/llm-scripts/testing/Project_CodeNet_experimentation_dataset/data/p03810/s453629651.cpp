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

int N;
int a[MAX_N];

inline void print (bool k, bool p) { puts(k ^ p ? "First" : "Second"); exit(0); }

void dfs (int p) {
    int cnt[2] = {0, 0};
    rep (i, 1, N) cnt[a[i] & 1]++;
    rep (i, 1, N) if (a[i] == 1) print(cnt[0] & 1, p);
    if (cnt[0] & 1) print(1, p);
    else if (cnt[1] > 1) print(0, p);
    rep (i, 1, N) if (a[i] != 1 && (a[i] & 1)) a[i]--;
    int d = a[1];
    rep (i, 2, N) d = std::__gcd(d, a[i]);
    rep (i, 1, N) a[i] /= d;
    dfs(p ^ 1);
}

int main () {
#ifdef LOCAL
    FIN("in");
#endif
    read(N);
    rep (i, 1, N) read(a[i]);
    dfs(0);
    return 0;
}