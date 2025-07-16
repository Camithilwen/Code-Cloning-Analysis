#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> to[100005];
vector<int> dist;
int n;

void dfs(int v, int d=0, int p=-1) {
    dist[v] = d;
    for (int u : to[v]) {
        if (u == p) continue;
        dfs(u,d+1,v);
    }
}

vector<int> calc(int x) {
    dist = vector<int>(n);
    dfs(x);
    return dist;
}

int main() {
    int u, v;
    cin >> n >> u >> v;
    u--; v--;
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    } 

    vector<int> distU = calc(u);
    vector<int> distV = calc(v);

    int ans = 0;
    rep(i,n) {
        if (distU[i] < distV[i]) {
            ans = max(ans, distV[i]-1);
        }
    }
    cout << ans << endl;
    return 0;
}