#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> parent;
vector<int> visited;
vector<pair<int,int>> depth;

void DFS(int v, int parent_v, int d){
    parent[v] = parent_v;
    depth[v] = {d, v};

    for(int child_v : graph[v]){
        DFS(child_v, v, d+1);
    }
}

int main(){
    int s = 0;// starting point
    int n, k;
    cin >> n >> k;

    graph.resize(n);
    parent.resize(n);
    visited.resize(n);
    depth.resize(n);

    int ans = 0;
    int a0;
    cin >> a0;
    if(a0 != 1) ans = 1;

    for(int i=1; i<n; i++){
        int a;
        cin >> a;
        a -= 1;

        graph[a].push_back(i);
    }

    DFS(0,-1,0);
    sort(depth.begin(),depth.end());
    reverse(depth.begin(),depth.end());

    for(int i=0; i<n; i++){
        if(depth[i].first <= k) break;

        int current = depth[i].second;
        for(int j=0; j<k; j++){
            if(visited[current] == true) break;
            visited[current] = true;
            current = parent[current];
            if(j == k-1) ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}