#include <vector>
#include <functional>
#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int> > adj(n);
    while (m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long a = 0, b = 0, c = 0;
    int col[n];
    bool visited[n];
    fill(visited, visited+n, false);
    function <bool(int, int)> dfs = [&](int i, int c) {
        col[i] = c;
        visited[i] = true;
        bool ret = true;
        for (int j : adj[i]) {
            if (!visited[j]) { if (!dfs(j, -c)) ret = false; }
            else if (col[j] == c) ret = false;
        }
        return ret;
    };
    for (int i = 0; i < n; i++) {
        if (adj[i].empty()) a++;
        else if (visited[i]) continue;
        else if (dfs(i, 1)) b++;
        else c++;
    }
    cout << 2 * a * n - a * a + b * b + (b + c) * (b + c) << endl;
}
