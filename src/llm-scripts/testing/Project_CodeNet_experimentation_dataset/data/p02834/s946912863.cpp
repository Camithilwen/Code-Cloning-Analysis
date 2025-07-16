#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1001001001;
const ll mod = 1000000007;

int main(){
    int n, u, v; cin >> n >> u >> v;
    --u; --v;
    if(u == v){
        cout << 0 << endl;
        return 0;
    }
    vector<int> dist_u(n, -1), dist_v(n, -1);
    vector<vector<int>> G(n);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> que;
    que.push(u);
    dist_u[u] = 0;
    dist_v[v] = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv : G[v]){
            if(dist_u[nv] != -1) continue;
            dist_u[nv] = dist_u[v] + 1;
            que.push(nv);
        }
    }
    que.push(v);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv : G[v]){
            if(dist_v[nv] != -1) continue;
            dist_v[nv] = dist_v[v] + 1;
            que.push(nv);
        }
    }
    set<int> st;
    for(int i = 0; i < n; i++){
        if(dist_u[i] < dist_v[i]) st.insert(dist_v[i]);
    }
    sort(dist_v.begin(), dist_v.end(), greater<int>());
    for(int i = 0; i < n; i++){
        if(st.count(dist_v[i])){
            cout << dist_v[i] - 1 << endl;
            return 0;
        }
    }
    
}