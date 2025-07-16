/*

強連結成分アルゴリズムアルゴリズム

input:有向グラフG
output:各店の属する強連結成分を表す関数comp:V(G)->N

*/

#include <vector>
#include <functional>
using namespace std;

vector<int> scc(const vector<vector<int>>& G){
    vector<int> comp(G.size(),-1);
    vector<int> R(G.size(),0);
    int N = 0;
    vector<int> psi(G.size(),-1);
    vector<int> psi_inv(G.size(),-1);

    function<void(int)> visit1 = [&](int v){
        R[v] = 1;
        for(int w : G[v]){
            if(R[w] == 0) visit1(w);
        }
        psi[v] = N;
        psi_inv[N] = v;
        N = N + 1;
    };

    for(int i = 0;i < G.size();i++){
        if(R[i] == 0) visit1(i);
    }

    R.assign(G.size(),0);
    int K = 0;

    vector<vector<int>> rev_G(G.size());

    for(int v = 0;v < G.size();v++){
        for(int to : G[v]) rev_G[to].push_back(v);
    }

    function<void(int)> visit2 = [&](int v){
        R[v] = 1;
        for(int w : rev_G[v]){
            if(R[w] == 0) visit2(w);
        }
        comp[v] = K;
    };

    for(int i = G.size() - 1;i >= 0;i--){
        if(R[psi_inv[i]] == 0){
            visit2(psi_inv[i]);
            K = K + 1;
        }
    }
    return comp;
}

#include <iostream>

int main(){
    int v;
    int e;
    cin >> v >> e;
    vector<vector<int>> G(v);
    for(int i = 0;i < e;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
    
    }

    auto res = scc(G);

    int q;
    cin >> q;

    for(int i = 0;i < q;i++){
        int x,y;
        cin >> x >> y;
        cout << (res[x] == res[y]) << endl;
    }
}
