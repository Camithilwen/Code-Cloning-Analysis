#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

int main() {
  int N,u,v;cin>>N>>u>>v;
  u--;v--;
  vector<vector<int>> tree(N,vector<int>());
  rep(i,N-1) {
    int a,b;cin>>a>>b;
    a--;b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  vector<bool> u_done(N,false),v_done(N,false);
  vector<int> u_dis(N,0),v_dis(N,0);
  u_done[u] = true;
  v_done[v] = true;
  queue<int> uq,vq;
  uq.push(u);
  vq.push(v);
  while(!uq.empty()) {
    int now = uq.front();
    uq.pop();
    for(auto nxt : tree[now]) {
      if(!u_done[nxt]) {
	u_done[nxt]= true;
	u_dis[nxt] = u_dis[now] + 1;
	uq.push(nxt);
      }
    }
  }
  // rep(i,N) {
  //   cout<<u_dis[i]<<endl;
  // }
  vector<int> leaf;
  while(!vq.empty()) {
    int now = vq.front();
    vq.pop();
    int chi_siz = 0;
    for(auto nxt : tree[now]) {
      if(!v_done[nxt]) {
	chi_siz++;
	v_done[nxt]= true;
	v_dis[nxt] = v_dis[now] + 1;
	vq.push(nxt);
      }
    }
    // cout<<now<<" "<<chi_siz<<endl;
    if(chi_siz == 0) leaf.push_back(now);
  }
  int ans = 0;
  for(auto lf : leaf) {
    // cout<<lf<<endl;
    if(u_dis[lf] < v_dis[lf]) {
      ans = max(ans,v_dis[lf]-1);
    }
  }
  cout<<ans<<endl;
}
 
