#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <stack>
#include <limits>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <numeric>
#include <tuple>

constexpr long long mod = static_cast<long long>(1e9 + 7);

void dfs1(int i, const std::vector<std::vector<int>>& edges, std::vector<std::pair<int, int>>& memo, int& cnt) {
    memo[i] = {i, 0};
    for(auto v: edges[i]) {
        if(memo[v].second < 0) dfs1(v, edges, memo, cnt);
    }
    memo[i].second = cnt++;
}

void dfs2(int i, const std::vector<std::vector<int>>& edges, std::vector<int>& memo, int cnt) {
    memo[i] = cnt;
    for(auto v: edges[i]) {
        if(memo[v] < 0) dfs2(v, edges, memo, cnt);
    }
}

int main() {
    int V, E;
    std::cin >> V >> E;
    std::vector<std::vector<int>> edges(V);
    std::vector<std::vector<int>> redges(V);
    while(E--) {
        int s, t;
        std::cin >> s >> t;
        edges[s].push_back(t);
        redges[t].push_back(s);
    }
    int cnt = 0;
    std::vector<std::pair<int, int>> memo(V, {-1, -1});
    for(int i = 0; i < V; ++i) {
        if(memo[i].second < 0) dfs1(i, edges, memo, cnt);
    }
    std::sort(begin(memo), end(memo), [](auto x, auto y){return x.second > y.second;});
    std::vector<int> ans(V, -1);
    cnt = 0;
    for(auto val: memo) {
        if(ans[val.first] < 0) {
            dfs2(val.first, redges, ans, cnt++);
        }
    }

    int Q;
    std::cin >> Q;
    while(Q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << (ans[u] == ans[v] ? 1 : 0) << "\n";
    }
    std::cout << std::flush;

    return 0;
}

