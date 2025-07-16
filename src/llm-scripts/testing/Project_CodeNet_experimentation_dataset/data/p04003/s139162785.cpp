#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int N = (int)1e5 + 50, INF = (int)1e9;

int n, m;
map<int, vector<int> > G[N];
set<int> rem[N];
int dis[N];

deque<P> que;

void dfs(int v, int color, int d) {
//    printf("in %d , color: %d\n", v, color);
    rem[v].erase(color);
    if(d < dis[v]) {
        dis[v] = d;
        que.push_back({v, color});
    }
    for(int nxt : G[v][color]) {
        if(rem[nxt].find(color) != rem[nxt].end()) {
//            printf("from %d to %d\n", v, nxt);
            dfs(nxt, color, d);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    fill(dis, dis + n, INF);
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--, c--;
        G[a][c].push_back(b);
        G[b][c].push_back(a);
        rem[a].insert(c);
        rem[b].insert(c);
    }
    while(!rem[0].empty()) dfs(0, *rem[0].begin(), 1);
//    for(int i = 0; i < n; i++) {
//        printf("dis %d: %d\n", i + 1, dis[i]);
//    }
    while(!que.empty()) {
        P p = que.front();
        int v = p.first, c = p.second;
        que.pop_front();
        while(!rem[v].empty()) {
            dfs(v, *rem[v].begin(), dis[v] + 1);
        }
    }
    if(dis[n-1] == INF) dis[n-1] = -1;
    cout << dis[n - 1] << endl;
}