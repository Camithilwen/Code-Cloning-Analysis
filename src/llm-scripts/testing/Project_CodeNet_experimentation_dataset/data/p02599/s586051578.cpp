#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb push_back
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v) cerr << #v << ":"; rep(i, v.size()) cerr << " " << v[i]; cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

template<typename T>
struct BinaryIndexedTree {
    /* 0-indexed */
    vector<T> data;

    BinaryIndexedTree(int sz) {
        data.assign(++sz, 0);
    }

    T sum(int k) {
        T ret = 0;
        for (++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }

    void add(int k, T x) {
        for (++k; k < data.size(); k += k & -k) data[k] += x;
    }
};

vector<pii> Q[505050];

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> C(n);
    rep(i, n) {
        cin >> C[i];
        C[i]--;
    }
    vector<int> ans(q);
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        Q[r].pb({l, i});
    }
    BinaryIndexedTree<int> BIT(n);
    vector<int> R(n + 1, -1);
    rep(i, n) {
        if (R[C[i]] != -1) BIT.add(R[C[i]], -1);
        BIT.add(i, 1);
        R[C[i]] = i;
        for(auto query : Q[i]) {
            int l = query.fi, r = i;
            int idx = query.se;
            ans[idx] = BIT.sum(r) - BIT.sum(l - 1);
        }
    }
    rep(i, q) {
        cout << ans[i] << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
