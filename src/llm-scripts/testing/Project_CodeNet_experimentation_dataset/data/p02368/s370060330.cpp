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
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <numeric>
//#include <tuple>

constexpr long long mod = static_cast<long long>(1e9 + 7);

using Edges = std::vector<std::vector<int>>;

void dfs1(int i, const Edges& edges, std::vector<int>& ans, std::vector<bool>& memo) {
    memo[i] = true;
    for(auto v: edges[i]) {
        if(!memo[v]) dfs1(v, edges, ans, memo);
    }
    ans.push_back(i);
}

void dfs2(int i, const Edges& redges, std::vector<int>& ans, int cnt) {
    ans[i] = cnt;
    for(auto v: redges[i]) {
        if(ans[v] < 0) dfs2(v, redges, ans, cnt);
    }
}

int main() {
    int V, E;
    std::cin >> V >> E;
    Edges edges(V);
    Edges redges(V);
    while(E--){
        int s, t;
        std::cin >> s >> t;
        edges[s].push_back(t);
        redges[t].push_back(s);
    }
    std::vector<bool> memo(V, false);
    std::vector<int> topoSorted;
    topoSorted.reserve(V);
    for(int i = 0; i < V; ++i) {
        if(!memo[i])dfs1(i, edges, topoSorted, memo);
    }

    std::vector<int> ans(V, -1);
    int cnt = 0;
    for(auto itr = rbegin(topoSorted); itr != rend(topoSorted); ++itr) {
        if(ans[*itr] < 0) dfs2(*itr, redges, ans, cnt++);
    }

    int Q;
    std::cin >> Q;
    while(Q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << (ans[u] == ans[v]) << '\n';
    }
    std::cout << std::flush;

    return 0;
}

