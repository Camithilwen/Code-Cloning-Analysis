#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n-1); i >= 0; i--)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

template <class Monoid>
class SegmentTree
{
public:
  using Func = function<Monoid(Monoid, Monoid)>;
  const Func F;
  const Monoid M1;
  int sz;
  vector<Monoid> seg;

  SegmentTree(int n,const Func fu, const Monoid &m1): F(fu) , M1(m1) {init(n);}
  void init(int n)
  {
      sz= 1;
      while (sz < n) sz *= 2;
      seg.assign(sz * 2, M1);
  }
  void update(int k,const Monoid &x)
  {
    k+=sz;
    seg[k]=x;
    while(k>>=1)
    {
      seg[k]=F(seg[k*2],seg[k*2+1]);
    }
  }
  Monoid query(int l,int r)
  {
    Monoid L=M1,R=M1;
    l+=sz;r+=sz;
    for(;l<r;l>>=1,r>>=1)
    {
      if(l&1)L=F(L,seg[l++]);
      if(r&1)R=F(seg[--r],R);
    }
    return F(L,R);
  }
  Monoid &operator[](int n){
    return seg[n+sz];
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  ll m;cin>>m;

  SegmentTree<ll>st(n+1,[](ll a,ll b){return a+b;},0);
  vector<vector<ll>>g(n+1);
  rep(i,n)g[0].push_back(n-i);
  n++;
  rep(i,m){
    ll a,b;cin>>a>>b;
    g[a].push_back(b);
  }
  vector<ll>visited(n),ls(n);
  ll id=0,cn=0;
  ll mi=1e9,tcnt=0;
  function<void(ll,ll&,ll&)>dfs=[&](ll v,ll& idx,ll&cnt){
    ls[v]=idx++;
    st.update(ls[v],1);
    visited[v]=1;
    for(auto nv:g[v]){
      cnt++;
      if(ls[nv]!=0&&st[ls[nv]]){
        //cout<<"test"<<nv<<" "<<v<<" "<<ls[nv]<<" "<<ls[v]<<endl;
        if(chmin(mi,st.query(ls[nv],ls[v]+1))){
          tcnt=cnt;
        }
      }
      if(visited[nv])continue;
      dfs(nv,idx,cnt);
      cnt++;
    }
    st.update(ls[v],0);
  };
  vector<ll>et;
  function<void(ll,ll&)>dfs2=[&](ll v,ll&cnt){
  //  cout<<"cnt"<<cnt<<endl;
    st.update(ls[v],v);
    visited[v]=1;
    et.push_back(v);
    for(auto nv:g[v]){
      cnt++;

      if(ls[nv]!=0&&st[ls[nv]]){
        if(cnt==tcnt){
          cout<<mi<<"\n";
          //cout<<ls[nv]<<" "<<ls[v]<<endl;
          repi(i,ls[nv],ls[v]+1){
            if(st[i]>0)cout<<st[i]<<"\n";
          }
          cout<<flush;
        }
      }
      if(visited[nv])continue;
      dfs2(nv,cnt);
      cnt++;
    //  et.push_back(v);
    }
    st.update(ls[v],0);
  };
  dfs(0,id,cn);
  cn=0;
  visited.assign(n,0);
  dfs2(0,cn);
  cout<<endl;
  if(mi==1e9){
    cout<<-1<<endl;
  }
  return 0;

}
