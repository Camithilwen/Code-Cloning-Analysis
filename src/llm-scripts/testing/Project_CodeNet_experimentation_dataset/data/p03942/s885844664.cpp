#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

namespace IO {
    template <typename _T>
    inline bool read(_T& x) {
        x = 0;
        _T y = 1;
        char c = getchar();
        while ((c < '0' || '9' < c) && c != EOF) {
            if (c == '-')
                y = -1;
            c = getchar();
        }
        if (c == EOF)
            return false;
        while ('0' <= c && c <= '9')
            x = x * 10 + c - '0', c = getchar();
        x *= y;
        return true;
    }

    template <typename _T>
    inline _T input() {
        _T x = 0, y = 1;
        char c = getchar();
        while ((c < '0' || '9' < c) && c != EOF) {
            if (c == '-')
                y = -1;
            c = getchar();
        }
        if (c == EOF)
            return 0;
        while ('0' <= c && c <= '9')
            x = x * 10 + c - '0', c = getchar();
        x *= y;
        return x;
    }
};  // namespace IO
using namespace IO;

namespace modular {
    const int MOD = 1000000007;

    inline int add(int x, int y) { return (x += y) >= MOD ? x -= MOD : x; }

    inline void inc(int& x, int y) { (x += y) >= MOD ? x -= MOD : 0; }

    inline int mul(int x, int y) { return 1LL * x * y % MOD; }

    inline int qpow(int x, int y) {
        int ans = 1;
        for (; y; y >>= 1, x = mul(x, x))
            if (y & 1)
                ans = mul(ans, x);
        return ans;
    }
};  // namespace modular

#define MAX_N 2000007
#define reg register
#define FIN(s) freopen(s, "r", stdin)
#define FOUT(s) freopen(s, "w", stdout)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define lep(i, l, r) for (int i = l; i < r; ++i)
#define irep(i, r, l) for (int i = r; i >= l; --i)
#define ilep(i, r, l) for (int i = r; i > l; --i)
typedef long long ll;

int N;
char s[MAX_N], t[MAX_N];
std::queue<int> q;

inline void solve() {
    int j = N, tag = 0, ans = 0, las = N + 1;
    irep(i, N, 1) {
        while (j && (s[j] != t[i] || j > i))
            j--;
        if (!j)
            return puts("-1"), void();
        if (las == j) {
            while (!q.empty() && q.front() - tag >= i)
                q.pop();
        } else {
            tag++;
            if (i != j) {
                while (!q.empty() && q.front() - tag > i)
                    q.pop();
                q.push(j + tag);
                ans = std::max(ans, (int)q.size());
            }
        }
        las = j;
    }
    printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
    FIN("in");
#endif
    read(N);
    scanf("%s%s", s + 1, t + 1);
    rep(i, 1, N) if (s[i] != t[i]) {
        solve();
        return 0;
    }
    puts("0");
    return 0;
}