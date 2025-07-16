#include <bits/stdc++.h>

#define reg register
#define pr std::pair<int, int>
#define fi first
#define se second
#define FIN(s) freopen(s, "r", stdin)
#define FOUT(s) freopen(s, "w", stdout)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define lep(i, l, r) for (int i = l; i < r; ++i)
#define irep(i, r, l) for (int i = r; i >= l; --i)
#define ilep(i, r, l) for (int i = r; i > l; --i)
#define Rep(i, n) rep(i, 1, n)
#define Lep(i, n) lep(i, 1, n)
#define IRep(i, n) irep(i, n, 1)
#define ILep(i, n) ilep(i, n, 1)
typedef long long ll;
typedef long double ld;

namespace modular {
    const int MOD = 1000000007;
    inline int add(int x, int y) { return (x += y) >= MOD ? x -= MOD : x; }
    inline void inc(int &x, int y) { (x += y) >= MOD ? x -= MOD : 0; }
    inline int mul(int x, int y) { return 1LL * x * y % MOD; }
    inline int qpow(int x, int y) {
        int ans = 1;
        for (; y; y >>= 1, x = mul(x, x))
            if (y & 1) ans = mul(ans, x);
        return ans;
    }
};  // namespace modular

namespace Base {
    template <typename Tp>
    inline Tp input() {
        Tp x = 0, y = 1;
        char c = getchar();
        while ((c < '0' || '9' < c) && c != EOF) {
            if (c == '-') y = -1;
            c = getchar();
        }
        if (c == EOF) return 0;
        while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
        return x *= y;
    }
    template <typename Tp>
    inline void read(Tp &x) {
        x = input<Tp>();
    }
    template <typename Tp>
    inline void chmax(Tp &x, Tp y) {
        x < y ? x = y : 0;
    }
    template <typename Tp>
    inline void chmin(Tp &x, Tp y) {
        x > y ? x = y : 0;
    }
};  // namespace Base
using namespace Base;
/*----------------------------------------------------------------------------*/

#define MAX_N 507
#define MAX_M 1000007

int pri[MAX_M], tot;
bool check[MAX_M];

void sieve() {
    int MX = 1000000;
    rep(i, 2, MX) {
        if (!check[i]) pri[++tot] = i;
        if (tot > 1000) break;
        rep(j, 1, tot) {
            if (i * pri[j] > MX) break;
            check[i * pri[j]] = true;
            if (i % pri[j] == 0) break;
        }
    }
}

int N;
ll ans[MAX_N * 2][MAX_N * 2], num1[MAX_N * 2], num2[MAX_N * 2];
void solve() {
    if (N == 2) {
        puts("4 7");
        puts("23 10");
        return;
    }
    int cur = 0;
    Rep(i, N) if (i + 1 & 1) num1[1 - i + N] = pri[++cur];
    rep(i, 2, N) if (i + 1 & 1) num1[i - 1 + N] = pri[++cur];
    rep(i, 2, N + N) if (i & 1) num2[i] = pri[++cur];
    // rep(i, 1, N * 2 - 1) printf("%d ", num1[i]);
    // puts("");
    rep(i, 0, N + 1) {
        rep(j, 0, N + 1) if (i + j & 1) {
            ans[i][j] =
                std::max(1LL, num1[i - j + N]) * std::max(1LL, num2[i + j]);
        }
    }
    Rep(i, N) {
        Rep(j, N) if (!(i + j & 1)) {
            ans[i][j] = ans[i - 1][j] * ans[i + 1][j] + 1;
        }
    }
    Rep(i, N) {
        Rep(j, N) {
            if (ans[i][j] > 1e15) exit(1);
            printf("%lld ", ans[i][j]);
        }
        puts("");
    }
}

int main() {
    sieve();
    read(N);
    solve();
    return 0;
}
