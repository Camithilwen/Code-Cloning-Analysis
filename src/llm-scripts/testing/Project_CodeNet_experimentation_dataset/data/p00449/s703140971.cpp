#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef tuple<int, int> duo;

#define TT template<typename T>
#define TTF template<typename T, typename F>
#define ET(T) typename T::value_type
TT inline T sq(T x){return x*x;}
TT inline T In(){T x;cin>>x;return x;}
TT inline void Out(T&x){cout<<x;}
TT inline void sort(T&v){sort(begin(v),end(v));}
TT inline void revs(T&v){reverse(begin(v),end(v));}
TT inline void uniq(T&v){sort(v);v.erase(unique(begin(v),end(v)),end(v));}
TT inline int ubnd(T&v,ET(T)&x){return upper_bound(begin(v),end(v),x)-begin(v);}
TT inline int lbnd(T&v,ET(T)&x){return lower_bound(begin(v),end(v),x)-begin(v);}
TTF inline void inpt(T&v,int n,F f){for(v.reserve(n);n--;v.emplace_back(f()));}
TTF inline void show(T&v,F f,string d=" ",string e="\n"){int i=0;for(auto&x:v)i++&&(cout<<d),f(x);cout<<e;}
#undef TT
#undef TTF
#undef ET

inline void fast_io(){ios::sync_with_stdio(0);cin.tie(0);}
inline int in(){int x;scanf("%d",&x);return x;}
inline ll pow_mod(ll a,ll k,ll m){ll r=1;for(;k>0;a=a*a%m,k>>=1)if(k&1)r=r*a%m;return r;}
inline ll mod_inv(ll a,ll p){return pow_mod(a,p-2,p);}

const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int Mod = 1000000000;

struct Edge {
  int f, t, c;
  Edge(int f, int t, int c) : f(f), t(t), c(c) {}
  bool operator<(const Edge& e) const { return c != e.c ? c > e.c : (f != e.f ? f < e.f : t < e.t); }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int dijkstra(const Graph& g, int s, int t){
  int vis[128];
  fill(begin(vis), end(vis), 0);
  priority_queue<Edge> pq;
  for (pq.push(Edge(-2, s, 0)); !pq.empty(); pq.pop()){
    Edge e = pq.top();
    if (vis[e.t]++) continue;
    if (e.t == t) return e.c;
    for (const auto& ee : g[e.t]){
      pq.push(Edge(e.f, ee.t, e.c + ee.c));
    }
  }
  return -1;
}

int main()
{
  int n, k;
  while (cin >> n >> k, n || k){
  Graph g(n + 1);
  for (int i = 0; i < k; i++){
    int t = in();
    if (t){
      int a, b, c;
      cin >> a >> b >> c;
      g[a].push_back(Edge(a, b, c));
      g[b].push_back(Edge(b, a, c));
    }
    else {
      int a, b;
      cin >> a >> b;
      cout << dijkstra(g, a, b) << endl;
    }
  }
  }
  return (0);
}

// priority_queue queue deque front stringstream max_element min_element insert count make_tuple