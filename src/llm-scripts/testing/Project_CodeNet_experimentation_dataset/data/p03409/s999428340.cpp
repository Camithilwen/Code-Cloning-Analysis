#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<bool> > vvb;
typedef vector<vector<double> > vvd;
typedef vector<vector<string> > vvs;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct BipartiteMatching {
  vector< vector< int > > graph;
  vector< int > match, alive, used;
  int timestamp;

  BipartiteMatching(int n) : graph(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}

  void add_edge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  bool dfs(int idx) {
    used[idx] = timestamp;
    for(auto &to : graph[idx]) {
      int to_match = match[to];
      if(alive[to] == 0) continue;
      if(to_match == -1 || (used[to_match] != timestamp && dfs(to_match))) {
        match[idx] = to;
        match[to] = idx;
        return true;
      }
    }
    return false;
  }

  int bipartite_matching() {
    int ret = 0;
    for(int i = 0; i < graph.size(); i++) {
      if(alive[i] == 0) continue;
      if(match[i] == -1) {
        ++timestamp;
        ret += dfs(i);
      }
    }
    return ret;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      if(i < match[i]) {
        cout << i << "-" << match[i] << endl;
      }
    }
  }
};


signed main()
{
  gearup;
  int n; cin >> n;
  vpii r,b;
  rep(i,n){
    int x,y; cin >> x >> y;
    x--;y--;
    r.push_back({x,y});
  }
  rep(i,n){
    int x,y; cin >> x >> y;
    x--;y--;
    b.push_back({x,y});
  }
  //sort(all(r));
  //sort(all(b));
  
  BipartiteMatching bm(n + n);
  rep(i,n){
    rep(j,n){
      if(r[i].first < b[j].first && r[i].second < b[j].second) bm.add_edge(i,n+j);
    }
  }
  
  out(bm.bipartite_matching());
}