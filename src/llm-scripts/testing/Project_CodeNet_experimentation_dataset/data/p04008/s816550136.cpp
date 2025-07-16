#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100010];
bitset<100010> al;
vector<int> adj[100010];
int ans = 0;
int dist[100010];

void dfs(int u){
    al[u] = true;
    dist[u] = 1;

    for(auto v : adj[u]){
        if(!al[v]){
            dfs(v);
            dist[u] = max(dist[u], dist[v] + 1);
        }
    }

    if(u != 1 && dist[u] == k && a[u] != 1) dist[u] = 0, ans++;
}

int main(){
    scanf("%d%d", &n, &k);

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(i != 1) adj[a[i]].emplace_back(i);
    }

    if(a[1] != 1) ans++;

    dfs(1);

    printf("%d\n", ans);
    
    return 0;
}