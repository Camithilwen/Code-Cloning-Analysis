#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

int n;
vector<int> adj[N];

vector<int> bfs(int src){
    vector<int> vis(n + 2, 0);
    vector<int> dis(n + 1, 0);
    vis[src] = 1;
    dis[src] = 0;
    queue<int> q;
    q.push(src);
    while(q.size()){
        int node = q.front();
        q.pop();
        for(auto i: adj[node]){
            if(!vis[i]){
                vis[i] = 1;
                dis[i] = dis[node] + 1;
                q.push(i);
            }
        }
    }
    return dis;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int pos_a, pos_b;
    cin >> n >> pos_a >> pos_b;
    if(pos_a == pos_b) return cout << 0, 0;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dis_a = bfs(pos_a);
    auto dis_b = bfs(pos_b);
    int ans = 0;
    for(int i = 1; i <= n; i++){
      if(dis_a[i] < dis_b[i]) ans = max(ans, dis_b[i] - 1);
    }
    cout << ans;

    return 0;
}
