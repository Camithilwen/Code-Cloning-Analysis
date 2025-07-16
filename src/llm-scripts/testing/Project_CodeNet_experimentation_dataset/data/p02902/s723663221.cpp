#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

vector<int> edges[2100];

struct UnionFind {  
  vector<int> par,sizes;                     // par[i]:iの親の番号(ex)par[3]=2 : 3の親が2
  UnionFind(int n) : par(n),sizes(n,1)  {    //最初は全てが根であるとして初期化
    for(int i=0; i<n; i++){ par[i]=i; }  
  }
  int root(int x) {                       //xが属する木の根を再帰で得る:root(x)={xの木の根}
    if(par[x]==x){ return x; }
    return par[x] = root(par[x]);
  }
  void unite(int x, int y) {                 // xとyの木を併合
    int rx = root(x);                        //xの根をrx
    int ry = root(y);                        //yの根をry
    if(rx == ry){ return; }                  //xとyの根が同じ(=同じ木にある)時はそのまま
    if(sizes[rx]<sizes[ry]){ swap(rx, ry); } //xの木をおおきくする
    par[ry] = rx; 
    sizes[rx] += sizes[ry];                  //sizes[ry]はもう使わない
  }
 
  bool check(int x, int y) {                 // x,yが属する木が同じならtrueを返す
    return root(x) == root(y);
  }
  
  int size(int x){                           //xが含まれる木の大きさを返す
    return sizes[root(x)];
  }
};

bool dfs(int p, set<int> &a){
  for(auto to:edges[p]){
    if(a.find(to)!=a.end()){ return true; }
    a.insert(to);
    if(dfs(to,a)){ return true; } else { a.erase(to); }
  }
  return false;
}
 
int main(){
  int n,m;
  cin >> n >> m;
  UnionFind uf(n);
  vector<P> aded;
  
  for(int i=0; i<m; i++){
    int x,y; cin >> x >> y; x--; y--;
    if(uf.check(x,y)){
      aded.emplace_back(x,y);
    } else {
      uf.unite(x,y);
      edges[x].emplace_back(y);
    }
  }
  set<int> shortest;
  int cnt=inf;
  for(auto tmp:aded){
    set<int> ans;
    ans.insert(tmp.F);
    ans.insert(tmp.S);
    if(dfs(tmp.S,ans)){
      if(ans.size()<cnt){
        cnt=ans.size();
        shortest = ans;
      }
    }
  }
  if(cnt!=inf){
      cout << shortest.size() << endl;
      for(auto anno:shortest){cout << anno+1 << endl;}
      return 0;
  }
  cout << -1 << endl;
  return 0;
}
