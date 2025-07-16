#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    std::vector<std::tuple<int, int, int>> es;
    std::vector<std::pair<int, int>> w;
    for (int i = 0; i < m; i++) {
        int p, q, c;
      	scanf("%d%d%d", &p, &q, &c);
        --p; --q;
        es.emplace_back(p, q, c);
        w.emplace_back(p, c);
        w.emplace_back(q, c);
    }

    std::sort(w.begin(), w.end());
    w.erase(std::unique(w.begin(), w.end()), w.end());

    auto get = [&](int v, int c) {
        return n + std::lower_bound(w.begin(), w.end(), std::make_pair(v, c)) - w.begin();
    };

    std::vector<std::vector<std::pair<int, int>>> g(w.size() + n);
    for (const auto &e : w) {
        int v = get(e.first, e.second);
        g[e.first].emplace_back(v, 1);
        g[v].emplace_back(e.first, 0);
    }
    for (const auto &e : es) {
        auto p = std::get<0>(e), q = std::get<1>(e), c = std::get<2>(e);
        int pv = get(p, c), qv = get(q, c);
        g[pv].emplace_back(qv, 0);
        g[qv].emplace_back(pv, 0);
    }

    constexpr int inf = std::numeric_limits<int>::max() / 2;
    std::vector<int> dist(g.size(), inf);
    std::deque<int> q { 0 };
    dist[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto to : g[v]) {
            if (dist[to.first] <= dist[v] + to.second) continue;
            dist[to.first] = dist[v] + to.second;
            if (to.second) q.push_back(to.first);
            else q.push_front(to.first);
        }
    }

	printf("%d\n", dist[n - 1] == inf ? -1 : dist[n - 1]);
  
    return 0;
}
