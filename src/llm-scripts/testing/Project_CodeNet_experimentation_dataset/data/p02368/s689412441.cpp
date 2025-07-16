#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;
int V;
vector<int> G[MAX],rG[MAX],vs;
bool used[MAX];
int cmp[MAX];

void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void DFS(int v){
    used[v]=1;
    for(int i=0;i<G[v].size();i++){
        if(used[G[v][i]]==0) DFS(G[v][i]);
    }
    vs.push_back(v);
}

void rDFS(int v,int k){
    used[v]=1;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++){
        if(used[rG[v][i]]==0) rDFS(rG[v][i],k);
    }
}

int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++){
        if(used[v]==0) DFS(v);
    }
    
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        if(used[vs[i]]==0) rDFS(vs[i],k++);
    }
    return k;
}

int main(){

    int E;cin>>V>>E;
    for(int i=0;i<E;i++){
        int a,b;cin>>a>>b;
        add_edge(a,b);
    }
    
    scc();
    
    int Q;cin>>Q;
    for(int i=0;i<Q;i++){
        int a,b;cin>>a>>b;
        if(cmp[a]==cmp[b]) cout<<1<<endl;
        else cout<<0<<endl;
    }
    
}


