#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>
#include <stack>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;
using Graph = Vvec<int>;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

void inputGraph(Graph& graph, int num_edge, bool is_bidirectional, bool is_zero_indexed = false){
    int u, v;
    for(int i=0; i<num_edge; i++){
        cin >> u >> v;
        if(!is_zero_indexed){
            u--; v--;
        }
        graph[u].emplace_back(v);
        if(is_bidirectional) graph[v].emplace_back(u);
    }
}

bool isBipartite(Graph& graph, vector<int>& vis, int tmp, int from){
    if(vis[tmp] >= 0) return true;
    bool ret = true;
    vis[tmp] = (from == -1) ? 0 : 1 - vis[from];
    for(auto& to: graph[tmp]){
        if(to != from){
            ret &= isBipartite(graph, vis, to, tmp);
            ret &= (vis[tmp] == 1-vis[to]);
        }
    }
    return ret;
}

int main()
{
    int N, M;
    cin >> N >> M;
    Graph graph(N);
    inputGraph(graph, M, true);

    ll u = 0, v = 0, w = 0;
    vector<int> vis(N, -1);
    for(int i=0; i<N; i++){
        if(vis[i] >= 0) continue;
        if(graph[i].size()==0) w++;
        else if(isBipartite(graph, vis, i, -1)) u++;
        else v++;
    }

    cout << u*u + (u+v)*(u+v) + w*(2*N-w) << endl;
}