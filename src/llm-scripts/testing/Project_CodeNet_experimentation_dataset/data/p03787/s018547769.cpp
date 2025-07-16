#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()
// #define DEBUGGING

template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;
template <typename T, typename U> using P = pair<T, U>;
using ll = int64_t;
using PLL = P<ll, ll>;

template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename Head, typename... Tail> const Head& var_min(const Head &head, const Tail&... tail) { return min(head, var_min(tail...)); }
template <typename Head, typename... Tail> const Head& var_max(const Head &head, const Tail&... tail) { return max(head, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }

namespace __init {

struct InitIO {
    InitIO() {
        cin.tie(0);
        ios_base::sync_with_stdio(false);
        cout << fixed << setprecision(30);
    }
} init_io;

}

#ifdef DEBUGGING
#include "../debug.cpp"
#else
#define DEBUG(...) 0
#endif

template <typename T>
T make_v(T init) { return init; }

template <typename T, typename... Tail>
auto make_v(T init, size_t s, Tail... tail) {
#define rec make_v(init, tail...)
    return V<decltype(rec)>(s, rec);
#undef rec
}

VV<ll> edges;

pair<ll, bool> dfs(ll now, V<ll> &depth, ll d) {
    PLL ret(1, true);
    depth[now] = d;
    for(ll nxt : edges[now]) {
        if(depth[nxt] != -1) {
            ll d1 = depth[nxt];
            ll d2 = depth[now];
            if((d1 % 2) == (d2 % 2)) ret.second = false;
        } else {
            auto tmp = dfs(nxt, depth, d + 1);
            ll t1;
            bool t2;
            tie(t1, t2) = tmp;
            ret.first += t1;
            ret.second &= t2;
        }
    }
    return ret;
}

int main() {
    ll N, M;
    cin >> N >> M;

    edges.resize(N);
    for(ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    V<ll> depth(N, -1);
    V<pair<ll, bool>> subg;
    ll tcnt = 0, lcnt = 0, ocnt = 0;
    for(ll i = 0; i < N; i++) {
        if(depth[i] != -1) continue;
        auto ret = dfs(i, depth, 0);
        ll s;
        bool tree;
        tie(s, tree) = ret;
        if(s == 1) {
            ocnt++;
        } else {
            subg.emplace_back(s, tree);
            (tree ? tcnt : lcnt)++;
        }
    }

    ll ans = 0;
    for(const auto &ele : subg) {
        ll n;
        bool t;
        tie(n, t) = ele;
        ans += tcnt + lcnt;
        ans += (ll)(t) * tcnt;
        ans += n * ocnt;
    }

    DEBUG(ans);

    ans += N * ocnt;

    cout << ans << endl;
    return 0;
}
