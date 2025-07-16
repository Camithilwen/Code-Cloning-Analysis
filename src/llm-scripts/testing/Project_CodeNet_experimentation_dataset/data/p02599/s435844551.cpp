#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define int long long
#define pb push_back
#define x first
#define ld long double
#define y second
#define mk(a,b) make_pair(a,b)
#define rr return 0
#define sqr(a) ((a)*(a))
#define all(a) a.begin(),a.end()

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template<class value, class cmp = less<value> >
using ordered_set = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class value, class cmp = less_equal<value> >
using ordered_multiset = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = less<key> >
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

/// find_by_order()
/// order_of_key()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int randll(int l = INT_MIN, int r = INT_MAX) {
    return uniform_int_distribution<int>(l, r)(rng);
}
vector <int> t;
inline void upd (int i, int x) {
    for (; i < (int)t.size(); i = i | (i + 1)) t[i] += x;
}
inline int sum (int r) {
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ans += t[r];
    return ans;
}
inline int sum (int l, int r) {
    return sum(r) - sum(l - 1);
}
main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (auto &i : a) cin >> i;
    vector <vector <pair<int, int> > > Q(n);
    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        --l, --r;
        Q[r].pb({l, i});
    }
    t.resize(n);
    map <int, int> have;
    vector <int> ans(q);
    for (int i = 0; i < n; i++) {
        if (have.count(a[i])) {
            upd(have[a[i]], -1);
        }
        have[a[i]] = i;
        upd(i, 1);
        for (auto &j : Q[i]) {
            ans[j.y] = sum(j.x, i);
        }
    }
    for (auto &i : ans) cout << i << '\n';
}
