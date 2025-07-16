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
template <typename T> inline bool chmin(T& x, const T& y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T& x, const T& y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Segment Tree
template <typename Operator>
struct SegmentTree {
    Operator OP;
    using NodeType = decltype(OP.NodeE);
    int length;
    vector<NodeType> node;
    SegmentTree (int N) {
        length = 1;
        while (length < N) length <<= 1;
        node.assign(length << 1, OP.NodeE);
    }
    SegmentTree (vector<NodeType> &vec) {
        length = 1;
        while (length < sz(vec)) length <<= 1;
        node.assign(2 * length, OP.NodeE);
        rep(i, sz(vec)) node[i + length] = vec[i];
        for (int i = length - 1; i > 0; --i) node[i] = OP.func(node[(i << 1) + 0], node[(i << 1) + 1]);
    }
    void update(int idx, NodeType val) {
        idx += length;
        node[idx] = OP.change(node[idx], val);
        while (idx >>= 1) node[idx] = OP.func(node[(idx << 1) + 0], node[(idx << 1) + 1]);
    }
    NodeType get(int l, int r) {
        l += length;
        r += length;
        NodeType vl = OP.NodeE, vr = OP.NodeE;
        while (r > l) {
            if (l & 1) vl = OP.func(vl, node[l++]);
            if (r & 1) vr = OP.func(node[--r], vr);
            l >>= 1;
            r >>= 1;
        }
        return OP.func(vl, vr);
    }
};
struct RMQ {
    using NodeType = pair<int, int>;
    NodeType NodeE = pair<int, int>(-1, -1);
    NodeType change(NodeType x, NodeType y) {return y;}
    NodeType func(NodeType x, NodeType y) {return max(x, y);}
};

// Main
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) {cin >> a[i]; --a[i];}
    
    int ans = 0;
    if (a[0] != 0) {++ans; a[0] = 0;}
    
    vector<vector<int>> g(n);
    rep(i, 1, n) {g[a[i]].push_back(i);}
    vector<int> d(n, 0);
    auto dfs = [&](auto f, int v, int par) -> void {
        for (int u: g[v]) {
            if (u == par) continue;
            d[u] = d[v] + 1;
            f(f, u, v);
        }
    };
    dfs(dfs, 0, -1);
    SegmentTree<RMQ> st(n);
    rep(i, n) st.update(i, pair<int, int>(d[i], i));
    
    while (true) {
        pair<int, int> p = st.get(0, n);
        if (p.first <= k) break;
        int now = p.second;
        rep(i, k - 1) now = a[now];
        d[now] = 1;
        auto dfs2 = [&](auto f, int v, int par) -> void {
            st.update(v, pair<int, int>(d[v], v));
            for (int u: g[v]) {
                if (u == par || d[u] == 1) continue;
                d[u] = d[v] + 1;
                f(f, u, v);
            }
        };
        dfs2(dfs2, now, -1);
        ++ans;
    }
    cout << ans << "\n";
    return 0;
}
