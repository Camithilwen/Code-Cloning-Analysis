#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
using vs = vector<string> ;
#define all(v) v.begin(),v.end()
const int MAX_V = 210;
const int INF = 1e5;
 
int V;
vll G[MAX_V];
int match[MAX_V];
bool used[MAX_V];
 
void add_edge(int u,int v){
  G[u].push_back(v);
  G[v].push_back(u);
}
 
bool dfs(int v){
  used[v]=true;
  rep(i,G[v].size()){
    int u = G[v][i], w = match[u];
    if(w<0 || !used[w] && dfs(w)){
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}
 
int bipartite_matching(){
  int res = 0;
  memset(match, -1, sizeof(match));
  rep(v,V){
    if(match[v]<0){
      memset(used, 0, sizeof(used));
      if(dfs(v)) res++;
    }
  }
  return res;
}
 
int main(){
  cin>>V;
  vector<pair<int,int>> red,blue;
  rep(i,V){
    int a,b;cin>>a>>b;red.push_back(make_pair(a,b));
  }
  rep(i,V){
    int c,d;cin>>c>>d;blue.push_back(make_pair(c,d));
  }
  rep(i,V){
    rep(j,V){
      pair<int,int> r,b;
      r = red[i],b=blue[j];
      if(r.first<b.first && r.second<b.second) add_edge(i,j+V);
    }
  }
  //cout << "グラフ" << endl;
  //rep(i,V)rep(j,G[i].size()) cout<< i << " " << G[i][j]<<endl;
  cout << bipartite_matching() << endl;
}