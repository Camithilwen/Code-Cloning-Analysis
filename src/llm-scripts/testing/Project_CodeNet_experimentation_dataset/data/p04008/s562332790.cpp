#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int ans = 0;
    vector<vector<int>> graph(N);
    for(int i = 0; i < N; ++i) {
        int a; cin >> a;
        a--;
        if(i) graph[a].emplace_back(i);
        else if(a) ans++;
    }
    auto dfs = [&](auto &&dfs, int cur, int pre) -> int {
        int n = 1;
        for(auto &to : graph[cur]) {
            if(to == pre) continue;
            n = max(n, dfs(dfs, to, cur) + 1);
        }
        if(pre && n == K) ans++, n = 0;
        return n;
    };
    dfs(dfs, 0, 0);
    cout << ans << '\n';
    return 0;
}
