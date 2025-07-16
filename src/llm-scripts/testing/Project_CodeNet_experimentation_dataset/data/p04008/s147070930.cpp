#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int n, k, a[MAXN], dep[MAXN], sum[MAXN], adv[MAXN], fa[MAXN], ans;
vector<int> g[MAXN];

int read() {
    char c = getchar();
    int x = 0;
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c)) {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x;
}

int DFS(int u) {
    int maxi = dep[u];
    for (int i = 0; i < (int)g[u].size(); ++i) {
        int v = g[u][i];
        if (v == 1)
            continue;
        dep[v] = dep[u] + 1;
        maxi = max(DFS(v), maxi);
    }
    if (maxi - dep[u] == k - 1) {
        if (maxi > k)
            ++ans;
        return dep[u] - 1;
    }
    return maxi;
}

int main() {
    n = read();
    k = read();
    for (int i = 1; i <= n; ++i) {
        fa[i] = read();
        g[fa[i]].push_back(i);
    }
    DFS(1);
    ans += fa[1] != 1;
    printf("%d\n", ans);
}
