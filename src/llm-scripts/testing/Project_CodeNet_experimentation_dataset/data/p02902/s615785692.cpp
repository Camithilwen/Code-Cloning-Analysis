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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].emplace_back(b);
    }
    for (int t = 0; t < n; t++) {
        queue<int> que;
        vector<bool> was(n);
        vector<int> depth(n);
        vector<set<int>> p(n);
        vector<int> q(n);
        que.push(t);
        was[t] = true;
        while (!que.empty()) {
            for (int i = que.size(); i > 0; i--) {
                int v = que.front();
                que.pop();
                set<int> st;
                for (int to : g[v]) {
                    if (was[to]) {
                        st.emplace(to);
                        continue;
                    }
                    was[to] = true;
                    que.push(to);
                    depth[to] = depth[v] + 1;
                    p[to] = p[v];
                    q[to] = v;
                    p[to].emplace(v);
                }
                if (!st.empty()) {
                    int mx = -1, id = -1;
                    for (int to : st) {
                        if (p[v].count(to)) {
                            if (mx < depth[to]) {
                                id = to;
                                mx = depth[to];
                            }
                        }
                    }
                    if (id != -1) {
                        cout << depth[v] - mx + 1 << '\n';
                        cout << v + 1 << '\n';
                        while (id != v) {
                            v = q[v];
                            cout << v + 1 << '\n';
                        }
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}
