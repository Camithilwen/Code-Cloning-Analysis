#include <iostream>
#include <climits>
#include <vector>
#include <cstring>
using namespace std;

#define V_MAX 10040
int N,E;
int INF = INT_MAX/4;

struct edge {
    int to,cap,rev;
    edge(int _to, int _cap, int _rev) {to = _to; cap=_cap; rev=_rev;}
};

vector<edge> G[V_MAX];
bool used[V_MAX];


void add_edge(int from, int to, int cap){
    G[from].push_back(edge(to,cap,G[to].size()));
    G[to].push_back(edge(from,0,G[from].size()-1));
}

int dfs(int v, int t, int f){
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<G[v].size();i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap>0){
            int d = dfs(e.to, t, min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0;
    for(;;){
        memset(used,0,sizeof(used));
        int f = dfs(s,t,INF);
        if(f==0) return flow;
        flow += f;
    }
}

int main(){
    
    cin>>N;
    
    int s, t;
    s = 2 * N;
    t = s + 1;
    
    vector<pair<int,int>> r(N);
    for(int i=0; i<N; i++){
     cin >> r[i].first >> r[i].second;
     add_edge(s, i, 1);
    }
    
    vector<pair<int,int>> b(N);
    for(int i=0; i<N; i++){
      cin >> b[i].first >> b[i].second;
      add_edge(N+i, t, 1);
    }
    
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if (r[i].first < b[j].first && r[i].second < b[j].second){
          add_edge(i, N+j, 1);
        }
      }
    }
    
    cout << max_flow(s, t) << endl;
    return 0;
}
