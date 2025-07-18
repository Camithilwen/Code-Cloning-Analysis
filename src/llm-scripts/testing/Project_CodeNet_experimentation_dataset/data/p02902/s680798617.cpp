#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
using namespace std;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-10;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)


//ここから編集

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> g(N);
  REP(i,M){
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
  }

  int mi = N+1;
  vector<int> res;
  for(int s = 0; s<N; s++){
    vector<int> dist(N, -1);
    vector<int> prev(N, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(q.size()){
      auto v = q.front();
      q.pop();
      for(auto u: g[v]){
        if(dist[u] == -1){
          dist[u] = dist[v] + 1;
          prev[u] = v;
          q.push(u);
        }
      }
    }

    for(int t = 0; t<N; t++){
      if(t == s || dist[t] == -1) continue;
      for(auto v: g[t]){
        if(v == s){
          vector<int> tmp({s});
          int cur = t;
          while(cur != s) tmp.push_back(cur), cur = prev[cur];
          if(mi > tmp.size()){
            mi = tmp.size();
            res = tmp;
          }
        }
      }
    }
  }

  if(mi == N+1){
    cout << -1 << endl;
  }else{
    cout << res.size() << endl;
    for(auto e: res) cout << e+1 << endl;
  }
  return 0;
}
