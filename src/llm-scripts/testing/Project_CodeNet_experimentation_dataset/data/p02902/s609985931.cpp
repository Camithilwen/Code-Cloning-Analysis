#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#define int long long
#define pb push_back
#define x first
#define y second
#define mk(a,b) make_pair(a,b)
#define rr return 0
#define sqr(a) ((a)*(a))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class value, class cmp = less<value> >
using ordered_set = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class value, class cmp = less_equal<value> >
using ordered_multiset = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = less<key> >
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

/// find_by_order()
/// order_of_key()
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int randll(int l = INT_MIN, int r = INT_MAX) {
    return uniform_int_distribution<int>(l, r)(rng);
}

const int INF = 1e9, MOD = 998244353; /// think
const ll LINF = 1e15;

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
inline bool inside (int x, int y, int n, int m) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

template<class T> bool umin (T &a, T b) {return a > b ? (a = b, true) : false; }
template<class T> bool umax (T &a, T b) {return a < b ? (a = b, true) : false; }

vector <vector <int> > edge;
main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    edge.resize(n);
    vector <pii> e(m);
    vector <int> res;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        --a, --b;
        e[i] = {a, b};
        edge[a].pb(b);
    }
    auto solve = [&] (int v) {
        vector <int> d(n, INF), pr(n);
        queue <int> q;
        for (int to : edge[v]) {
            d[to] = 1;
            pr[to] = v;
            q.push(to);
        }
        while (!q.empty()) {
            int V = q.front();
            q.pop();
            for (int to : edge[V]) {
                if (d[to] == INF) {
                    d[to] = d[V] + 1;
                    pr[to] = V;
                    q.push(to);
                }
            }
        }
        if (d[v] != INF) {
            vector <int> ans;
            int from = v;
            while (d[from] != 1) {
                ans.pb(from);
                from = pr[from];
            }
            ans.pb(from);
            if (sz(ans) < sz(res) || res.empty()) {
                res = ans;
            }
        }
    };
    for (int i = 0; i < n; i++) {
        solve(i);
    }
    bool ok = !res.empty();
    vector <int> tin(n), tout(n);
    for (int i = 0; i < m; i++) {
        int f = 0;
        for (auto &j : res) {
            if (e[i].x == j) {
                ++f;
                break;
            }
        }
        for (auto &j : res) {
            if (e[i].y == j) {
                ++f;
                break;
            }
        }
        if (f == 2) {
            ++tin[e[i].x];
            ++tout[e[i].y];
        }
    }
    for (int i : res) {
        if (tin[i] != 1 || tout[i] != 1) {
            ok = false;
        }
    }
    if (ok) {
        cout << sz(res) << '\n';
        for (auto &i : res) {
            cout << i + 1 << '\n';
        }
    }
    else cout << "-1\n";
}
