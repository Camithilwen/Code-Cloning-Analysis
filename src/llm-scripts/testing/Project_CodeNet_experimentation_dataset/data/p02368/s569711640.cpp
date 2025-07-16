#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define vi vector<int>
#define pb push_back
#define INF 999999999
//#define INF (1LL<<59)


#define MAX_V 100000
vector<int> G[MAX_V];   //???
vector<int> rG[MAX_V];  //??????

void add_edge(int from, int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v, bool used[MAX_V], vector<int> &vs){
    used[v] = true;
    rep(i,G[v].size()){
        if(!used[G[v][i]])dfs(G[v][i],used,vs);
    }
    vs.push_back(v);
}

void rdfs(int v,int k,vector<int> &sccs, vector<int> &cmp, bool used[MAX_V]){
    used[v] = true;
    sccs.push_back(v);
    cmp[v] = k;
    rep(i,rG[v].size()){
        if(!used[rG[v][i]])rdfs(rG[v][i],k,sccs,cmp,used);
    }
}

int scc(int V, vector< vector<int> > &each_scc, vector<int> &cmp){
    vector<int> vs;
    bool used[MAX_V];
    rep(i,MAX_V)used[i] = false;
    vs.clear();
    rep(v,V){
        if(!used[v]) dfs(v, used, vs);
    }
    
    rep(i,MAX_V) used[i] = false;
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        vector<int> sccs;
        if(!used[vs[i]]){
            rdfs(vs[i], k++, sccs, cmp, used);
            each_scc.push_back(sccs);
        }
    }
    return k;
}
/*
 vector<vector<int>> each_scc;  //????????????????????£?????????????????????
 vector<int> cmp(MAX_V);        //???????????????????±??????????????????£??????????????????( ??????each_scc????????????????????? )
 int k = scc(v,each_scc,cmp);   //?????£??????????????°???
*/


int main(){
    int V,E;
    cin>>V>>E;
    rep(i,E){
        int s,t;
        cin>>s>>t;
        add_edge(s,t);
    }
    vector<vector<int>> each_scc;
    vector<int> cmp(MAX_V);
    int k = scc(V,each_scc,cmp);
    
    int q;
    cin>>q;
    rep(i,q){
        int u,v;
        cin>>u>>v;
        if(cmp[u]==cmp[v])cout<<1<<endl;
        else cout<<0<<endl;
    }
}