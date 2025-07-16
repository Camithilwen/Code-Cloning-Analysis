#include<iostream>
#include<vector>
using namespace std;

vector<int> v[10000], rev[10000], order, group(10000, 0);
vector<bool> vis(10000);

void dfs(int x){
    vis[x] = true;
    for(int j : v[x]){
        if(!vis[j]) dfs(j);
    }
    order.push_back(x);
}

void rdfs(int x, int k){
    group[x] = k;
    vis[x] = true;
    for(int j : rev[x]){
        if(!vis[j]) rdfs(j, k);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int s, t;
        cin >> s >> t;
        v[s].push_back(t);
        rev[t].push_back(s);
    }
    fill(vis.begin(),vis.end(),0);
    for(int i = 0; i < n; i++){
        if(!vis[i]) dfs(i);
    }
    fill(vis.begin(),vis.end(),0);
    int k = 0;
    for(int i = order.size()-1; i >= 0; i--){
        if(!vis[order[i]]) rdfs(order[i], k++);
    }
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << (group[u]==group[v]) << endl;
    }
    return 0;
}
