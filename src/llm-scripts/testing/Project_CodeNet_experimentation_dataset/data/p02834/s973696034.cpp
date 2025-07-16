#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

void DFS(int v, int parent_v, vector<int> &depth, vector<int> &parent){
    for(int child_v : graph[v]){
        if(child_v == parent_v) continue;

        depth[child_v] = depth[v] + 1;
        parent[child_v] = v;
        DFS(child_v, v, depth, parent);
    }
}

int main(){
    int n, u, v;
    cin >> n >> u >> v;
    u -= 1;
    v -= 1;
    graph.resize(n);

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> depth(n), parent(n);
    DFS(v, -1, depth, parent);

    int init = depth[u];
    int start = u;
    for(int i=0; i<(init-1)/2; i++){
        start = parent[start];
    }
    int dist = depth[start] - (init-1)/2;

    vector<int> depth2(n), parent2(n);
    DFS(start, parent[start], depth2, parent2);

    sort(depth2.begin(),depth2.end());
    reverse(depth2.begin(),depth2.end());

    cout << (init-1)/2 + (depth2[0] + dist - 1) << endl;
    return 0;
}