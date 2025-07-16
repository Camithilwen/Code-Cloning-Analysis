#include<bits/stdc++.h>

using namespace std;
using ll = long long;

//constructor: LCA(graph);
template<class T> 
class LCA_weight {
private:
    int n;
    int D = 30;                        //hight
    vector<int> depth;                 //depth from root
    vector<vector<pair<int,T>>> hen;   //tree
    vector<vector<int>> par;           //doubling array
    vector<T> dista;                    //distance form root

    void dfs(int v, int p, int dep, T dep_dist) {
        par[v][0] = p;
        depth[v] = dep;
        dista[v] = dep_dist;
        for(auto i : hen[v]) {
            if(i.first == p)continue;
            dfs(i.first, v, dep + 1, dep_dist + i.second);
        }
    }

public:

    LCA_weight(const vector<vector<pair<int,T>>>& hen):hen(hen) {
        n = hen.size();
        par.resize(n, vector<int>(D + 1));
        depth.resize(n);
        dista.resize(n);

        dfs(0, -1, 0, 0);
        for(int i = 0; i < D; i++) {
            for(int j = 0; j < n; j++) {
                if(par[j][i] == -1)par[j][i + 1] = -1;
                else par[j][i + 1] = par[par[j][i]][i];
            }
        }
    }

    //go back to root
    int back(int v, int dist) {
        for(int i = 0; i < D; i++)if((1 << i) & dist) {
            if(v == -1)return v;
            v = par[v][i];
        }
        return v;
    }



    //get LCA
    int get(int u, int v) {
        int ret = 0;
        if(depth[u] > depth[v])swap(u, v);
        ret = depth[v] - depth[u];
        v = back(v, ret);
        if(u == v)return v;

        for(int i = D; i >= 0; i--) {
            if(par[u][i] != par[v][i]) {
                u = par[u][i];
                v = par[v][i];
            }
        }
        return par[u][0];
    }

    //u-v path distance
    T dist(int u, int v) {
        int lca = get(u, v);
        return (dista[u] + dista[v]) - dista[lca] * 2;
    }

    //print parents
    void print(int i) {
        cerr << "[";
        for(int j = 0; j < n; j++)cerr << par[j][i] << (j == n - 1 ? "" : ",");
        cerr << "]";
    }

};

int main()
{
    int n; cin >> n;
    vector<vector<pair<int,ll>>> hen(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        hen[a].emplace_back(b, c);
        hen[b].emplace_back(a, c);
    }
    LCA_weight<ll> lca(hen);
    int q, k; cin >> q >> k;
    k--;
    while(q--) {
        int s, t; cin >> s >> t; s--, t--;
        cout << lca.dist(s, k) + lca.dist(t, k) << endl;
    }
}