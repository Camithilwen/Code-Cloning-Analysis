#include <bits/stdc++.h>
using namespace std;

vector<int> FordFulkerson_dfs_sub(
    const vector<map<int, int>>& graph, // source, (target, capacity)
    int source, int target, set<int>& prev)
{
    if(source==target) return vector<int>{source};
    for(auto v : graph.at(source)){
        if(v.second == 0) continue; 
        if(prev.count(v.first) > 0) continue;
        prev.insert(source);
        auto ret = FordFulkerson_dfs_sub(graph, v.first, target, prev);
        if(ret.size() != 0){
            ret.push_back(source);
            return ret;
        }
    }
    return vector<int>();
}

vector<int> FordFulkerson_dfs(
    const vector<map<int, int>>& graph, // source, (target, capacity)
    int source, int target)
{
    auto s = set<int>();
    auto ret = FordFulkerson_dfs_sub(graph, source, target, s);
    reverse(ret.begin(), ret.end());
    return ret;
}

// Graph: Directed, no loop
// Complexity: E * (max flow)
vector<map<int, int>> FordFulkerson(
    vector<map<int, int>> graph, // source, (target, capacity)
    int s, int t)
{
    const int N = graph.size();
    auto res = graph;

    // Add inverted edges
    for(int i=0; i<N; i++){
        for(auto e : res[i]){
            auto v = e.first;
            graph[v][i] = -0;
        }
    }

    while(true){
        auto path = FordFulkerson_dfs(graph, s, t);
        if(path.size()==0) break;
        int c_min = numeric_limits<int>::max();
        for(int i=0; i<path.size()-1; i++){
            auto u = path[i];
            auto v = path[i+1];
            c_min = min(c_min, graph[u][v]);
        }
        if(c_min == 0) break;
        for(int i=0; i<path.size()-1; i++){
            auto u = path[i];
            auto v = path[i+1];
            graph[u][v] -= c_min;
            graph[v][u] += c_min;
        }
    }
    for(int i=0; i<res.size(); i++){
        for(auto v : res[i]){
            res[i][v.first] = graph[v.first][i];
        }
    }
    return res;
}

vector<array<int, 2>> MaximumMatching(
    vector<vector<int>> graph // source, target
){
    const int N = graph.size();
    vector<map<int, int>> graph2(2 + 2 * N);
    for(int i=0;i<N;i++){
        graph2[2*N][i] = 1;
        graph2[N+i][2*N+1] = 1;
        for(auto v : graph[i]){
            graph2[i][v + N] = 1;
        }
    }
    auto ret = FordFulkerson(graph2, 2*N, 2*N+1);
    vector<array<int, 2>> res;
    for(int i=0;i<N;i++){
        for(auto m : ret[i]){
            if(m.second == 0) continue;
            res.push_back(array<int, 2>{i, m.first});
        }
    }

    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    vector<int> D(N);
    for(int i=0;i<N;i++) cin >> A[i] >> B[i];
    for(int i=0;i<N;i++) cin >> C[i] >> D[i];
    vector<vector<int>> graph(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(A[i] < C[j] && B[i] < D[j]){
                graph[i].push_back(j);
            }
        }
    }
    auto ret = MaximumMatching(graph);
    cout << ret.size() << endl;

    return 0;
}
