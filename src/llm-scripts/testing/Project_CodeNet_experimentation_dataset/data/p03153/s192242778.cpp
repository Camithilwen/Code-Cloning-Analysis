#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr double eps = 1e-9;
constexpr ll MOD = 1000000007LL;
template <typename T>
bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
};
template <typename T>
bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
};
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for(int i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 == v.size() ? "\n" : " ");
    }
    return os;
}
template <typename T>
vector<T> make_v(size_t a) {
    return vector<T>(a);
}
template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T& t, const V& v) {
    t = v;
}
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T& t, const V& v) {
    for(auto& e : t) {
        fill_v(e, v);
    }
};
struct UnionFind {
    vector<int> par, siz;
    UnionFind(int n) {
        par.resize(n);
        siz.resize(n, 1);
        for(int i = 0; i < n; i++)
            par[i] = i;
    }
    int find(int x) {
        if(par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if(u == v)
            return false;
        if(siz[u] < siz[v])
            swap(u, v);
        par[v] = u;
        siz[u] += siz[v];
        return true;
    }
    bool same(int u, int v) { return find(u) == find(v); }
};
struct edge {
    ll u, v, cost;
    bool operator<(const edge& e) { return cost < e.cost; }
};
ll d;
vector<ll> a;
vector<edge> es;
void calc(int l, int r) {
    if(r - l <= 1) {
        return;
    }
    int m = (l + r) / 2;
    ll mi = LINF, s, t;
    for(ll i = l; i < m; i++) {
        ll k = -i * d + a[i];
        if(mi > k) {
            mi = k;
            s = i;
        }
    }
    mi = LINF;
    for(ll i = m; i < r; i++) {
        ll k = i * d + a[i];
        if(mi > k) {
            mi = k;
            t = i;
        }
    }
    for(ll i = l; i < m; i++) {
        es.push_back({i, t, (t - i) * d + a[t] + a[i]});
    }
    for(ll i = m; i < r; i++) {
        es.push_back({s, i, (i - s) * d + a[i] + a[s]});
    }
    calc(l, m);
    calc(m, r);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n >> d;
    a.resize(n + 1);
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    calc(1, n + 1);
    UnionFind uf(n + 1);
    sort(all(es));
    ll ans = 0;
    for(auto e : es) {
        if(uf.unite(e.u, e.v)) {
            ans += e.cost;
        }
    }
    cout << ans << endl;
}
