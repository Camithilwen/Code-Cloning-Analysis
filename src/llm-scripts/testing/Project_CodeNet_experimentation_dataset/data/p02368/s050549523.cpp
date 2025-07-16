#include <bits/stdc++.h>
#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define numa(x,a) for(auto x: a)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define pf push_front
#define sec second
#define sz(x) ((int)(x).size())
#define ALL( c ) (c).begin(), (c).end()
#define gcd(a,b) __gcd(a,b)
#define endl "\n"
using namespace std;
template <int POS, class TUPLE> void deploy(std::ostream &os, const TUPLE &tuple){}
template <int POS, class TUPLE, class H, class ...Ts> void deploy(std::ostream &os, const TUPLE &t){ os << (POS == 0 ? "" : ", ") << get<POS>(t); deploy<POS + 1, TUPLE, Ts...>(os, t); }
template <class T> std::ostream& operator<<(std::ostream &os, std::vector<T> &v){ int remain = v.size(); os << "{"; for(auto e: v) os << e << (--remain == 0 ? "}" : ", "); return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::set<T> &v){ int remain = v.size(); os << "{"; for(auto e: v) os << e << (--remain == 0 ? "}" : ", "); return os; }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::map<T, K> &mp){ int remain = mp.size(); os << "{"; for(auto e: mp) os << "(" << e.first << " -> " << e.second << ")" << (--remain == 0 ? "}" : ", "); return os; }
#define DEBUG1(var0) { std::cerr << (#var0) << "=" << (var0) << endl; }
#define DEBUG2(var0, var1) { std::cerr << (#var0) << "=" << (var0) << ", ";DEBUG1(var1); }
#define DEBUG3(var0, var1, var2) { std::cerr << (#var0) << "=" << (var0) << ", ";DEBUG2(var1,var2); }
#define DEBUG4(var0, var1, var2, var3) { std::cerr << (#var0) << "=" << (var0) << ", ";DEBUG3(var1,var2,var3); }
#define DEBUG5(var0, var1, var2, var3, var4) { std::cerr << (#var0) << "=" << (var0) << ", ";DEBUG4(var1,var2,var3,var4); }
#define DEBUG6(var0, var1, var2, var3, var4, var5) { std::cerr << (#var0) << "=" << (var0) << ", ";DEBUG5(var1,var2,var3,var4,var5);}
typedef long long ll;

#define MAX_V 100100
int V;
vector <pair <int,ll> > edge[MAX_V];
vector <pair <int,ll> > Redge[MAX_V];
vector <int> vs;
bool used[MAX_V];
int cmp[MAX_V];
void reverse_edge(){
  rep2(i,1,V+1){//1-indexedにしてます
    rep(j,sz(edge[i])){
      Redge[edge[i][j].fir].pb(mp(i,edge[i][j].sec));
    }
  }
}

void dfs(int now){
  used[now] = true;
  rep(i,sz(edge[now])){
    if(!used[edge[now][i].fir]){
      dfs(edge[now][i].fir);
    }
  }
  vs.pb(now);
}

void rdfs(int now,int k){
  used[now] = true;
  cmp[now] = k;
  rep(i,sz(Redge[now])){
    if(!used[Redge[now][i].fir]){
      rdfs(Redge[now][i].fir,k);
    }
  }
}
int scc(){
  memset(used,0,sizeof(used));
  vs.clear();
  rep2(v,1,V+1){//1-indexed
    if(!used[v]){
      dfs(v);
    }
  }
  memset(used,0,sizeof(used));
  reverse_edge();
  int k = 0;
  for(int i = sz(vs)-1;i >= 0;i--){
    if(!used[vs[i]]){
      k += 1;
      rdfs(vs[i],k);
    }
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> V;
  int E;
  cin >> E;
  rep(i,E){
    int x,y;
    cin >> x >> y;
    x += 1;
    y += 1;
    edge[x].pb(mp(y,1));
  }
  scc();
  int Q;
  cin >> Q;
  rep(i,Q){
    int x,y;
    cin >>  x >> y;
    x += 1;
    y += 1;
    if(cmp[x] == cmp[y]){
      cout << 1 << endl;
    }else{
      cout << 0 << endl;
    }
  }
  
  return 0;
}