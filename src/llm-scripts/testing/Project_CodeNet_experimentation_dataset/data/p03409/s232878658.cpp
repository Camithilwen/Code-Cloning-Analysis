#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define ppll pair<ll,pll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (ll) (x).size()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
#define int ll
// #define ll int
using namespace std;
const ll INF = 1 << 29;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const int MAX_V = 500;
// const ll mod = 998244353;
const ll MAX = 2100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[8] ={1,0,-1,0,1,-1,1,-1};
ll dy[8] ={0,1,0,-1,1,-1,-1,1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



template< class flow_type >
struct Dinic {
    const flow_type inf;
    struct edge {
        int to;
        flow_type cap;
        int rev;
        edge(int to, flow_type cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    vector < vector < edge > > graph;
    vector < int > level, iter;

    Dinic(int V) : inf(numeric_limits< flow_type >::max()/2), graph(V) {}

    void add_edge(int from, int to, flow_type cap) {

        graph[from].emplace_back(to, cap, (int)graph[to].size());
        graph[to].emplace_back(from, 0, (int)graph[from].size() - 1);
    }

    void bfs(int source) {
        level.assign(graph.size(), -1);
        queue<int> que;
        que.push(source);
        level[source] = 0;
        while(!que.empty()) {
            int v = que.front(); que.pop();
            for(int i = 0; i < (int)graph[v].size(); i++) {
                edge &e = graph[v][i];
                if(e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    flow_type dfs(int v, int  sink, flow_type f) {
        if(v == sink) return f;
        for(int &i = iter[v]; i < (int)graph[v].size(); i++){
            edge &e = graph[v][i];
            if(e.cap > 0 && level[v] < level[e.to]) {
                flow_type d = dfs(e.to, sink, min(e.cap, f));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_type max_flow(int source, int sink) {
        flow_type flow = 0;
        while(true) {
            bfs(source);
            if(level[sink] < 0) return flow;
            iter.assign(graph.size(), 0);
            flow_type f;
            while((f = dfs(source, sink, inf)) > 0) flow += f;
        }
    }

    
};


void solve() {
    int n;
    cin>>n;
    Dinic<int> din(n*2+2);
    int a[110],b[110],c[110],d[110];
    rep(i,n) cin>>a[i]>>b[i];
    rep(i,n) cin>>c[i]>>d[i];
    rep(i,n) din.add_edge(0,i+1,1);
    rep(j,n) din.add_edge(n+j+1,2*n+1,1);
    rep(i,n){
        rep(j,n){
            if(a[i]<c[j]&&b[i]<d[j]){
                din.add_edge(i+1,n+j+1,1);
            }
        }
    }
    cout<<din.max_flow(0,2*n+1)<<endl;
    
}




signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);


    solve(); 


    return 0;
}
