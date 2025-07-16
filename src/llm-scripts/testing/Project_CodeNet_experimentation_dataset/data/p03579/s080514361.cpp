#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

bool dfs(int now, int pre, vector<int> &d, vector<vector<int>> &g) {
    if (now) d[now] = d[pre] + 1;

    bool ret = false;
    for (int nxt : g[now]) {
        if (d[nxt] != -1) {
            if (d[nxt] % 2 != d[now] % 2)
                continue;
            else
                return true;
        }
        ret |= dfs(nxt, now, d, g);
    }
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> d(n, -1);
    d[0] = 0;
    if (dfs(0, -1, d, g)) {
        cout << (ll)n * (n - 1) / 2 - (ll)m << endl;
        return 0;
    }

    ll odd = 0, even = 0;
    rep(i, n) {
        (d[i] % 2 == 0 ? even : odd)++;
    }
    cout << odd * even - (ll)m << endl;
}
