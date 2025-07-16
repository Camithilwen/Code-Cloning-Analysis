#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

#define MAX_V 200005
int V;
vector<int> nG[MAX_V], rG[MAX_V], G[MAX_V], vs; // 新しいグラフはG
bool used[MAX_V];
int cmp[MAX_V]; // ここに入る.

void add_edge(int from, int to){
    nG[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v){
    used[v] = 1;
    for(int i = 0; i < nG[v].size(); i++) if(!used[nG[v][i]]) dfs(nG[v][i]);
    vs.push_back(v);
}

void rdfs(int v, int k){
    used[v] = 1;
    cmp[v] = k;
    for(int i = 0; i < rG[v].size(); i++) if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}

int scc(){ // 新しい頂点数を返す
    memset(used, 0, sizeof(used));
    vs.clear();
    for(int v = 0; v < V; v++) if(!used[v]) dfs(v);
    memset(used, 0, sizeof(used));
    int k = 0;
    for(int i = vs.size() - 1; i >= 0; i--) if(!used[vs[i]]) rdfs(vs[i], k++);

    rep(i,V){
        int x = cmp[i];
        rep(j,nG[i].size()){
            int y = cmp[nG[i][j]];
            if(x == y)continue;
            G[x].push_back(y);
        }
    }
    
    rep(i,k){
        set<int> se;
        rep(j,G[i].size()) se.insert(G[i][j]);
        G[i].clear();
        for(auto x : se) G[i].push_back(x);
    }

    return k;
}

int main(){
    int n, m;
    cin >> n >> m;
    V = n;
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        // a--; b--;
        add_edge(a, b);
    }

    int nn = scc();
    /*
    cout << nn << endl;
    rep(i,n) cout << cmp[i] << ' ';
    cout << endl;

    rep(i,nn){
        rep(j,G[i].size()) cout << G[i][j] << ' ';
        cout << endl;
    }
    */
    int q;
    cin >> q;
    rep(i,q){
        int a, b;
        cin >> a >> b;
        if(cmp[a] == cmp[b]){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
    
    return 0;

}

