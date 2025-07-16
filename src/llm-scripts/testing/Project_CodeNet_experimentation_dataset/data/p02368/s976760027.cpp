#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SCC {
    int n;
    vector<vector<int>>& G;
    vector<vector<int>> G_rev;
    vector<int> comp, order;
    vector<bool> visited;

    SCC(vector<vector<int>>& G) : G(G), n(G.size()) {
        comp.resize(n, -1);
        visited.resize(n);
        G_rev.resize(n);
        for (int u = 0; u < n; u++) {
            for (int v : G[u]) {
                G_rev[v].push_back(u);
            }
        }

        for (int v = 0; v < n; v++) dfs(v);
        reverse(order.begin(), order.end());
        int c = 0;
        for (int v : order) if (comp[v] == -1) rdfs(v, c++);
    }

    int operator[](int k) {
        return comp[k];
    }

    void dfs(int u) {
        if (visited[u]) return;
        visited[u] = true;
        for (int v : G[u]) dfs(v);
        order.push_back(u);
    }

    void rdfs(int u, int c) {
        if (comp[u] != -1) return;
        comp[u] = c;
        for (int v : G_rev[u]) rdfs(v, c);
    }
};

struct UnionFind {
    vector<int> par, rank, size;

    UnionFind(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
        rank.resize(n);
        size.resize(n, 1);
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int get_size(int x) {
        return size[find(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }
    SCC scc(G);
    UnionFind uf(2 * V);
    for (int i = 0; i < V; i++) uf.unite(i, V + scc[i]);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        cout << (uf.same(u, v) ? 1 : 0) << '\n';
    }
}
