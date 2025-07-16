#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;


void dfs(vector<vector<pair<int,ll>>> &graph,
 int now, int past,ll sum, vector<ll> &dist){
    dist[now]=sum;
    for(auto next:graph[now]){
       if(next.first==past)continue;
       dfs(graph, next.first, now, sum+next.second, dist);
    }
}
int main(){
   int n;
   cin >> n;
   vector<vector<pair<int,ll>>> graph(n);
   vector<ll> dist(n);
   rep(i, 0, n-1){
      int a, b;
      ll c;
      cin >> a >> b >> c;
      a--, b--;
      graph[a].push_back({b, c});
      graph[b].push_back({a, c});
   }
   int q, k;
   cin >> q >> k;
   k--;
   dfs(graph, k, -1, 0, dist);
   vector<ll>ans(q);
   rep(i, 0, q){
      int x, y;
      cin >> x >> y;
      ans[i] = dist[x-1]+dist[y-1];
   }
   rep(i, 0, q)cout<< ans[i] << endl;
   return 0;
}