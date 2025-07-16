#include <bits/stdc++.h>
using namespace std;

// DAG
vector<bool> visited;
vector<int> dp;

int DFS(const vector<vector<int>> &graph, int v){
    if(visited[v] == true) return dp[v];
    
    visited[v] = true;
    for(auto next_v : graph[v]){
        if(DFS(graph, next_v) == -1) return -1;

        dp[v] = max(dp[v], DFS(graph, next_v) + 1);
    }
    return dp[v] = max(0, dp[v]);// if no next_v (i.e. source) dp[v] = 0
}

int main(){
    int n;
    cin >> n;
    int V = n * (n-1) / 2;
    visited.assign(V,false);
    dp.assign(V,-1);

    vector<vector<int>> a(n, vector<int>(n-1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            cin >> a[i][j];
            a[i][j] -= 1;
        }
    }

    vector<vector<int>> matchID(n, vector<int>(n));
    int id = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            matchID[i][j] = id;
            matchID[j][i] = id;
            id += 1;
        }
    }

    vector<vector<int>> graph(V);
    for(int i=0; i<n; i++){
        for(int j=1; j<n-1; j++){
            int s = matchID[i][a[i][j-1]];
            int t = matchID[i][a[i][j]];
            //cout << s << " " << t << endl;
            graph[t].push_back(s);// arrow inversed
        }
    }

    int ans = 0;
    for(int i=0; i<V; i++){
        int depth = DFS(graph, i);
        if(depth == -1){
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, depth);
    }
    cout << ans + 1 << endl;
    return 0;
}