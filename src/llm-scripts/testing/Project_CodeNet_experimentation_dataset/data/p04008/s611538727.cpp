#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7, K = 18;
vector<int> cld[N];
int par[N], level[N], anc[N][K];
bool done[N];

int n, k;
priority_queue<pair<int, int>> pq;

void setup(int u) {
    if (par[u] != u) level[u] = level[par[u]]+1;
    pq.push({level[u], u});
    anc[u][0] = par[u];
    for (int k=1; k<K; k++)     anc[u][k] = anc[anc[u][k-1]][k-1];
    for (int v: cld[u])         setup(v);
}

int getanc(int u, int d) {
    if (d >= N) d = N-1;
    for (int k=0; k<K; k++)
        if (d & (1<<k))
            u = anc[u][k];
    return u;
}

void dfs(int u) {
    if (done[u])    return;
    done[u] = 1;
    for (int v: cld[u])
        dfs(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    cin>>par[1];
    int ans = 0;
    if (par[1] != 1)    ans++, par[1] = 1;

    for (int i=2; i<=n; i++) {
        cin>>par[i];
        cld[par[i]].push_back(i);
    }
    setup(1);

    while (pq.size()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
//        cout<<u<<" --> "<<d<<endl;
        if (d <= k)     continue;
        if (done[u])    continue;

        int g = getanc(u, k-1);
        ans++;
        dfs(g);
    }
    cout<<ans<<endl;
}

