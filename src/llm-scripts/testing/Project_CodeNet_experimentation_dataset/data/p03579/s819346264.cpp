#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;

class Graph {
    vector<vector<int>> adj;
    vector<int> color;

public:
    Graph(int n) : adj(n), color(n, -1) {}

    void connect(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool dfs(int from = 0, int cur = 0) {
        color[from] = cur;
        for (auto to : adj[from]) {
            if (color[to] == cur) return false;
            if (color[to] == -1 && !dfs(to, 1 - cur)) return false;
        }
        return true;
    }

    vector<int> &getColor() {
        return color;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        graph.connect(--a, --b);
    }

    long long ans;
    if (graph.dfs()) {
        int cnt[2] = {0};
        for (auto i : graph.getColor()) cnt[i]++;
        ans = (long long)cnt[0] * cnt[1] - m;
    } else {
        ans = (long long)n * (n - 1) / 2 - m;
    }

    cout << ans << endl;
    
    return 0;
}