#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, dep[maxn];
bool vis[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    long long s1 = 0, s2 = 0, s3 = 0;
    vector<int> V1, V2;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        dep[i] = 1;
        int sz = 0, flag = 0;
        function<void(int)> dfs = [&](int v) {
            vis[v] = 1, sz++;
            for (int u : G[v]) {
                if (!vis[u]) dep[u] = dep[v] + 1, dfs(u);
                else if (!(dep[v] - dep[u] & 1)) flag = 1;
            }
        };
        dfs(i);
        if (sz == 1) { s3++; continue; }
        if (!flag) s1++;
        else s2++;
    }
    long long ans = 0;
    ans += 2 * s3 * n - s3 * s3;
    ans += 2 * s1 * s1 + s1 * s2;
    ans += s2 * (s1 + s2);
    printf("%lld\n", ans);
    return 0;
}