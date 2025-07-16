#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
const long long INF = 1LL << 60;    // 1.15x10^18
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using edge = pair<int, long long>;
using Graph = vector<vector<edge>>;

vector<long long> dijkstra(const Graph &g, int s) {
    vector<long long> dist(g.size(), INF);
    using Pi = pair<long long, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    dist[s] = 0; que.emplace(dist[s], s);
    while (!que.empty()) {
        long long cost; int u; tie(cost, u) = que.top(); que.pop();
        if (dist[u] < cost) continue;
        for (auto &e: g[u]) {
            int v; long long nc; tie(v, nc) = e;
            if (chmin(dist[v], dist[u] + nc)) que.emplace(dist[v], v);
        }
    }
    return dist;
}

int main() {
    int n, k;
    while (cin >> n >> k, n) {
        Graph g(n);
        while (k--) {
            int com; cin >> com;
            if (com == 0) {
                int a, b; cin >> a >> b; a--, b--;
                auto res = dijkstra(g, a)[b];
                cout << (res == INF ? -1 : res) << endl;
            } else if (com == 1) {
                int c, d, e; cin >> c >> d >> e; c--, d--;
                g[c].emplace_back(d, e);
                g[d].emplace_back(c, e);
            }
        }
    }
    return 0;
}
