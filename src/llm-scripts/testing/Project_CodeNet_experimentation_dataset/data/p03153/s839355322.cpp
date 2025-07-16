#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

struct UnionFind{
   vector<int> par;
   UnionFind(int n):par(n,-1){}
   int find(int x){
       if(par[x]<0)return x;
       return par[x]=find(par[x]);
   }
   bool unite(int x,int y){
       x=find(x);
       y=find(y);
       if(x==y)return false;
       if(par[x]>par[y]){
           par[y]+=par[x];
           par[x]=y;
       }
       else{
           par[x]+=par[y];
           par[y]=x;
       }
       return true;
   }

   bool same(int x,int y){
       return find(x)==find(y);
   }
};

vector<pair<ll,pint>> edges;
ll a[202020],d;

ll dist(int x,int y){
    return d*abs(x-y)+a[x]+a[y];
}
void dfs(int l,int r){
    if(l+1>=r)return;
    ll mini=longinf,idx=-1;
    int m=(l+r)/2;
    for(int i=l;i<m;++i){
        if(dist(i,m)<mini)mini=dist(i,m),idx=i;
    }
    for(int i=m;i<r;++i){
        edges.push_back({dist(idx,i),{idx,i}});
    }
    mini=longinf;idx=-1;
    for(int i=m;i<r;++i){
        if(dist(i,l)<mini)mini=dist(i,l),idx=i;
    }
    for(int i=l;i<m;++i){
        edges.push_back({dist(idx,i),{idx,i}});
    }
    dfs(l,m);
    dfs(m,r);
}
int main(){
    int n;cin>>n>>d;
    rep(i,n)cin>>a[i];
    dfs(0,n);
    sort(edges.begin(),edges.end());
    UnionFind uf(n);
    ll ans=0;
    for(auto e:edges){
        if(uf.unite(e.second.first,e.second.second))ans+=e.first;
    }
    cout<<ans<<endl;
    return 0;
}