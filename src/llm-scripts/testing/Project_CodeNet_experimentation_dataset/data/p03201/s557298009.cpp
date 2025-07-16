#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    set<ll> st;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        st.emplace(a[i]);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = a.size();
    vector<ll> c(m);
    for (int i = 0; i < m; i++) {
        c[i] = mp[a[i]];
    }
    vector<vector<int>> g(m);
    for (int i = 0; i < m; i++) {
        for (ll x = 2; x < 2e9; x <<= 1) {
            int j = lower_bound(a.begin(), a.end(), x - a[i]) - a.begin();
            if (j < i && a[i] + a[j] == x) {
                g[i].emplace_back(j);
                g[j].emplace_back(i);
            }
        }
    }
    debug(a);
    debug(c);
    debug(g);
    ll ans = 0;
    vector<bool> was(m);
    function<void(int)> dfs = [&](int v) {
        ll t = 0;
        for (int to : g[v]) {
            if (was[to]) {
                continue;
            }
            was[to] = true;
            dfs(to);
            t += c[to];
        }
        if (t >= c[v]) {
            ans += c[v];
            c[v] = 0;
        } else {
            ans += t;
            c[v] -= t;
        }
    };
    for (int i = 0; i < m; i++) {
        if (!was[i] && __builtin_popcount(a[i]) == 1) {
            was[i] = true;
            dfs(i);
            ans += c[i] / 2;
        }
    }
    for (int i = 0; i < m; i++) {
        if (!was[i]) {
            was[i] = true;
            dfs(i);
        }
    }
    cout << ans << '\n';
    return 0;
}