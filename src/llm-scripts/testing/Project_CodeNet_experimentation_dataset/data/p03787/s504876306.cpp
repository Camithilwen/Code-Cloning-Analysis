#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/tag_and_trait.hpp>
// using namespace __gnu_pbds;
// #include<boost/multiprecision/cpp_int.hpp>
// namespace multiprecisioninteger = boost::multiprecision;
// using cint=multiprecisioninteger::cpp_int;
using namespace std;
using ll=long long;
#define double long double
using datas=pair<ll,ll>;
using ddatas=pair<double,double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
// using llset=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define For(i,a,b) for(i=a;i<(ll)b;++i)
#define bFor(i,b,a) for(i=b,--i;i>=(ll)a;--i)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N,0)
#define brep1(i,N) bFor(i,N,1)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define endl "\n"
#define eb emplace_back
#define print(v) cout<<v<<endl
#define printyes cout<<"Yes"<<endl
#define printno cout<<"No"<<endl
#define printYES cout<<"YES"<<endl
#define printNO cout<<"NO"<<endl
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
const ll mod=1000000007;
// const ll mod=998244353;
const ll inf=1LL<<60;
const double PI = acos(-1);
const double eps = 1e-9;
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;} 
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;} 

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}

struct unionfind{
  private:
  int maxN;
  vector<int> par,treesize;
  public:unionfind(int N) :maxN(N),par(N),treesize(N,1){
    for(int i=0;i<maxN;++i)par[i]=i;
  }
  int root(int x){
    while(par[x]!=x){
      x=par[x]=par[par[x]];
    }
    return x;
  }
  bool unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return false;
    if(treesize[x]>treesize[y])swap(x,y);
    par[x]=y;
    treesize[y]+=treesize[x];
    return true;
  }
  bool parcheck(int x,int y){
    return root(x)==root(y);
  }
  int size(int x){
    return treesize[root(x)];
  }
  void clear(){
    treesize.assign(maxN,1);
    for(int i=0;i<maxN;++i)par[i]=i;
  }
};

int main(){
  startupcpp();
  ll i,N,M,cnt=0,ans=0;
  cin>>N>>M;
  vector<int> a(M),b(M);
  map<int,int> mp;
  rep(i,M){
    cin>>a[i]>>b[i];
    mp[a[i]]+=mp[b[i]];
  }
  for(auto& x:mp)x.second=cnt++;
  ans=N*N-cnt*cnt;
  N=cnt;
  unionfind ut(N*2);
  rep(i,M){
    a[i]=mp[a[i]];
    b[i]=mp[b[i]];
    ut.unite(a[i],b[i]+N);
    ut.unite(a[i]+N,b[i]);
  }
  mp.clear();
  rep(i,N){
    mp[ut.root(i)]|=ut.parcheck(i,i+N);
  }
  cnt=0;
  for(auto& x:mp)cnt+=!x.second;
  print(ans+(mp.size()-cnt/2)*(mp.size()-cnt/2)+cnt*cnt/4);
}