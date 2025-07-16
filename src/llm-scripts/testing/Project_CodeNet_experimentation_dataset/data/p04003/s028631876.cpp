#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

#define INF 1000000009
#define MAX_V 500000

struct edge {
    int to;
    int cost;
    edge(int to,int cost):to(to),cost(cost){}
};



int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;

        for (int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

map<P,int> zip(vector<P> v){
  sort(all(v));
  map<P,int> res;
  int vsz=v.size();
  rep(i,vsz){
    res[v[i]]=i;
  }
  return res;
}

int main(){
  int n,m;cin>>n>>m;
  V=500000;
  int p[m],q[m],c[m];
  rep(i,m){
    cin>>p[i]>>q[i]>>c[i];
    --p[i];--q[i];--c[i];
  }
  vector<P> tozip;
  rep(i,m){
    tozip.push_back(P(p[i],c[i]));
    tozip.push_back(P(q[i],c[i]));
  }
  rep(i,n){
    tozip.push_back(P(i,-1));
  }
  auto index=zip(tozip);
  rep(i,m){
    G[index[P(p[i],c[i])]].push_back(edge(index[P(q[i],c[i])],0));
    G[index[P(q[i],c[i])]].push_back(edge(index[P(p[i],c[i])],0));
    G[index[P(p[i],c[i])]].push_back(edge(index[P(p[i],-1)],1));
    G[index[P(q[i],c[i])]].push_back(edge(index[P(q[i],-1)],1));
    G[index[P(p[i],-1)]].push_back(edge(index[P(p[i],c[i])],1));
    G[index[P(q[i],-1)]].push_back(edge(index[P(q[i],c[i])],1));
  }
  dijkstra(0);
  cout<<(d[index[P(n-1,-1)]]==INF?-1:d[index[P(n-1,-1)]]/2)<<endl;
}

    