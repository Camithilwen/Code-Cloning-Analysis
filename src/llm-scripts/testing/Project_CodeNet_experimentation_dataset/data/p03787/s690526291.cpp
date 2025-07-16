#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

ll N, M;
vector<int> to[100010];
int idx[100010];
int edge[100010];
int node[100010];
int oe[100010];
int judge[100010];
int es[200010];
ll ans = 0;

void dfs(int v, int id, int type){
    idx[v] = id;
    node[id]++;
    oe[v] = type;
    for(auto u : to[v]){
        if(idx[u] != 0){
            if(oe[u] == type) judge[id] = true;
        }else{
            dfs(u, id, (type + 1) & 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    ans = N * N;

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        es[i] = u;
        to[u].emplace_back(v);
        to[v].emplace_back(u);
    }

    int id = 1;
    for(int i = 1; i <= N; i++){
        if(idx[i] == 0) dfs(i, id++, 0);
    }
    for(int i = 0; i < M; i++){
        edge[idx[es[i]]]++;
    }
    ll nsum = 0, graph = 0, oc = 0;
    for(int i = 1; i < id; i++){
        if(node[i] == 1) continue;
        nsum += node[i];
        graph++;
        if(!judge[i]) oc++;
    }
    cout << ans - (nsum * nsum) + (graph * graph) + (oc * oc) << endl;
    return 0;
}