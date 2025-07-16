#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int N, K, a[100001], d[100001], c[100001];
vector<int> G[100001];

void dfs(int u) {
    for (int v : G[u]) {
        dfs(v);
        d[u] = max(d[v]+1, d[u]);
        c[u] += c[v];
    }
    if (u > 1 && a[u] > 1 && d[u] == K-1) {
        d[u] = -1;
        ++c[u];
    }
}

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;
    for (int u = 1; u <= N; ++u) {
        cin >> a[u];
        if (u > 1) G[a[u]].push_back(u);
    }
    dfs(1);
    cout << (a[1] > 1) + c[1];
}