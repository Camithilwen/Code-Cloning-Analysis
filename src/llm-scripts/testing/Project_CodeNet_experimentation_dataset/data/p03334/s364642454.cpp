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

#define MAX_N 607

int N, D1, D2;

struct Graph {
    std::vector<pr> dir;
    std::queue<pr> q;
    int col[MAX_N][MAX_N];
    Graph() { memset(col, -1, sizeof(col)); }

    void build(int D) {
        lep(i, 0, N * 2) {
            if (i * i > D) break;
            lep(j, 0, N * 2) {
                if (j * j > D) break;
                if (i * i + j * j == D) {
                    dir.push_back(pr(i, j));
                    dir.push_back(pr(i, -j));
                    dir.push_back(pr(-i, j));
                    dir.push_back(pr(-i, -j));
                }
            }
        }
    }
    bool in(int x, int y) { return 0 <= x && x < N * 2 && 0 <= y && y < N * 2; }
    void bfs(int x, int y) {
        q.push(pr(x, y));
        col[x][y] = 0;
        while (!q.empty()) {
            pr k = q.front();
            q.pop();
            for (pr t : dir) {
                pr nk = pr(k.fi + t.fi, k.se + t.se);
                if (in(nk.fi, nk.se) && col[nk.fi][nk.se] == -1) {
                    col[nk.fi][nk.se] = col[k.fi][k.se] ^ 1, q.push(nk);
                }
            }
        }
    }
    void color() {
        // for (auto t : dir) printf("%d %d\n", t.fi, t.se);
        // puts("--------");
        // return;
        lep(i, 0, N * 2) lep(j, 0, N * 2) if (col[i][j] == -1) bfs(i, j);
    }
} G1, G2;

void init() {
    G1.build(D1), G2.build(D2);
    G1.color(), G2.color();
}

std::vector<pr> ans[2][2];
void solve() {
    lep(i, 0, N * 2) {
        lep(j, 0, N * 2) {
            ans[G1.col[i][j]][G2.col[i][j]].push_back(pr(i, j));
        }
    }
    lep(i, 0, 2) {
        lep(j, 0, 2) if (ans[i][j].size() >= N * N) {
            while (ans[i][j].size() > N * N) ans[i][j].pop_back();
            for (pr k : ans[i][j]) printf("%d %d\n", k.fi, k.se);
            return;
        }
    }
}

int main() {
    read(N), read(D1), read(D2);
    init();
    solve();
    return 0;
}
