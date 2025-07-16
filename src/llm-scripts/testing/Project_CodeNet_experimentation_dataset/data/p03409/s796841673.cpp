#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
} 

 
struct Dinic {
  struct edge {
    int to, cap, rever;
    edge(int to, int cap, int rever):to(to), cap(cap), rever(rever){}
  };
  vector< vector<edge> > graph;
  vector<int> level, iter;
  Dinic(int V):graph(V), level(V), iter(V){}
  void add_edge(int from, int to, int cap) {
    graph[from].emplace_back(to, cap, graph[to].size());
    graph[to].emplace_back(from, 0, graph[from].size()-1);
  }
  void bfs(int s) {
    fill(all(level), -1);
    queue<int> que;
    level[s] = 0;
    que.push(0);
    while(que.size()) {
      int v = que.front(); que.pop();
      for(edge& e : graph[v]) {
        if(e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }
  int dfs(int v, int t, int f) {
    if(v == t) return f;
    for(int& i = iter[v]; i < graph[v].size(); i++) {
      edge& e = graph[v][i];
      if(e.cap > 0 && level[v] < level[e.to]) {
        int d = dfs(e.to, t, min(e.cap, f));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rever].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  int max_flow(int s, int t) {
    int flow = 0;
    while(true) {
      bfs(s);
      if(level[t] < 0) return flow;
      fill(all(iter), 0);
      int f; while((f = dfs(s, t, inf)) > 0) flow += f;
    }
  }
}; 

int main(){
    ll n;cin >> n;
    Dinic dn(2*n+2);
    ll s=0,t=2*n+1;
    vpl a(n),b(n);
    rep(i,n){
        cin  >> a[i].fi >> a[i].se;
    }
    rep(i,n){
        cin  >> b[i].fi >> b[i].se;
    }
    rep(i,n){
        dn.add_edge(s,i+1,1);
        dn.add_edge(i+1+n,t,1);
    }
    rep(i,n){
        rep(j,n){
            if(a[i].fi<b[j].fi&&a[i].se<b[j].se){
                dn.add_edge(i+1,n+1+j,1);
            }
        }
    }
    cout << dn.max_flow(s,t) <<endl;
}