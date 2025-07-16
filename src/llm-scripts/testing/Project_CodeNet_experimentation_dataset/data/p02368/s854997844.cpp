#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 120000000

using namespace std;

typedef pair<int, int> P;
typedef long long int LL;

int v, e;
vector<int> g[10010], rg[10010], vs, st;
vector<bool> vis;

void dfs(int x) {
    vis[x] = true;
    for (int i = 0; i < g[x].size(); i++) {
        if (!vis[g[x][i]]) dfs(g[x][i]);
    }
    vs.pb(x);
}

void rdfs(int x, int k) {
    vis[x] = true;
    st[x] = k;
    for (int i = 0; i < rg[x].size(); i++) {
        if (!vis[rg[x][i]]) rdfs(rg[x][i], k);
    }
}

bool isSame(int u, int v) {
    return (st[u] == st[v]);
}

int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        rg[b].pb(a);
    }
    st.resize(v);

    vis.resize(v, false);
    for (int i = 0; i < v; i++) {
        if (!vis[i]) dfs(i);
    }
    int k = 0;
    fill(vis.begin(), vis.end(), false);
    for (int i = vs.size() - 1; i >= 0; i--) {
        if (!vis[vs[i]]) rdfs(vs[i], k++);
    }

    int q;
    cin >> q;
    int u, v;
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        cout << isSame(u, v) << endl;
    }

    return 0;
}