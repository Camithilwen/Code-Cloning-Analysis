#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

//snukeさんのコードをほぼ写した

int N;

vector<int> G[100010];

vector<int> dist;

void dfs(int v, int d=0, int p=-1) {
    dist[v] = d;
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u,d+1,v);
    }
}

vector<int> calcDist(int s) {
    dist.resize(N);
    dfs(s);
    return dist;
}



int main(){ 
    int u, v, ans = 0;
    cin >> N >> u >> v;
    u--;
    v--;

    rep(i,N-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> distU = calcDist(u);
    vector<int> distV = calcDist(v);
    
    rep(i,N) {
        if (distU[i] < distV[i]) {
            ans = max(ans, distV[i]);
        }
    }

    ans--;
    cout << ans << endl;
}