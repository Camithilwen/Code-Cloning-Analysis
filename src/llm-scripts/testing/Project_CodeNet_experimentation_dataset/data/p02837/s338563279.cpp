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
const int INF = 1e9, MOD = 1e9 + 7; /// think
const ll LINF = 1e18;


const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
inline bool inside (int x, int y, int n, int m) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

template<class T> bool umin (T &a, T b) {return a > b ? (a = b, true) : false; }
template<class T> bool umax (T &a, T b) {return a < b ? (a = b, true) : false; }

main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <vector<pii> > b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i].resize(a[i]);
        for (auto &j : b[i]) {
            cin >> j.y >> j.x;
            --j.y;
        }
    }
    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        int res = 0;
        vector <int> used(n);
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                ++res;
                used[j] = 1;
            }
        }
        if (ans >= res) continue;
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (!used[j]) continue;
            for (auto &k : b[j]) {
                if (k.x) {
                    if (!used[k.y]) {
                        ok = false;
                    }
                }
                else {
                    if (used[k.y]) {
                        ok = false;
                    }
                }
            }
        }
        if (ok) ans = res;
    }
    cout << ans << '\n';
}
