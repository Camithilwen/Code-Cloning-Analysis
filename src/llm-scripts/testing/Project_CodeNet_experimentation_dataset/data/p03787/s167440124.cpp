#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct UnionFind{
  int num;
  vector<int> rs,ps;
  UnionFind(){}
  UnionFind(int n):num(n),rs(n,1),ps(n,0){iota(ps.begin(),ps.end(),0);}
  int find(int x){
    return (x==ps[x]?x:ps[x]=find(ps[x]));
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(rs[x]<rs[y]) swap(x,y);
    rs[x]+=rs[y];
    ps[y]=x;
    num--;
  }
  int size(int x){
    return rs[find(x)];
  }
  int count() const{
    return num;
  }
};

//INSERT ABOVE HERE
signed main(){
  int n,m;
  cin>>n>>m;
  UnionFind uf(n),bp(n*2);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    uf.unite(u,v);
    bp.unite(u+0,v+n);
    bp.unite(u+n,v+0);
  }
  using ll = long long;
  ll odd=0,eve=0,iso=0;
  for(int i=0;i<n;i++){
    if(uf.find(i)!=i) continue;
    if(uf.size(i)==1){
      iso++;
      continue;
    }
    if(bp.same(i,i+n)) odd++;
    else eve++;
  }
  ll ans=(ll)n*n-(n-iso)*(n-iso);
  ans+=(odd+eve)*(odd+eve);
  ans+=eve*eve;
  cout<<ans<<endl;
  return 0;
}
