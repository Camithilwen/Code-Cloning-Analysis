#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

vi to[100005];
// abc148 f

vi dist;
int n;

void dfs(int v, int d=0, int p=-1) {
  dist[v] = d;
  for (int u: to[v]) {
    if (u == p) continue;
    dfs(u,d+1,v);
  }
}

vi getDist(int v) {
  dist = vi(n);
  dfs(v);
  return dist;
}
int main() {
  int t, a; cin >> n >> t >> a;
  t--; a--;
  rep(i,n-1) {
    int a,b; cin >> a >> b; a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vi distA = getDist(a); 
  vi distT = getDist(t);

  int ans=0;
  rep(i,n) {
    if (distA[i] > distT[i]) {
      chmax(ans, distA[i]);
    }
  }
  ans--;
  cout << ans << endl;
  return 0;
}