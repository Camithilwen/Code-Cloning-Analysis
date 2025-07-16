// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, r) for (int i = (l); i < (r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <class T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <class T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Union-Find
struct UnionFind {
    vector<int> par;
    UnionFind(int N) : par(N, -1) { }
    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (par[rx] > par[ry]) swap(rx, ry);
        par[rx] += par[ry];
        par[ry] = rx;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        return -par[root(x)];
    }
};

// Main Code
int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(2 * n);
    vector<int> cnt(n, 0);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        uf.unite(a, b + n); uf.unite(a + n, b);
        ++cnt[a]; ++cnt[b];
    }
    
    vector<int> siz(2 * n, 0);
    rep(i, n, 2 * n) ++siz[uf.root(i)];
    ll ans = 0;
    rep(i, n) {
        ans += (siz[uf.root(i)] - cnt[i]);
        if (uf.same(i, n + i)) --ans;
    }
    cout << ans / 2 << "\n";
    return 0;
}
