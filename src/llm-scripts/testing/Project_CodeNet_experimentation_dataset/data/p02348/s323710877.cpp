#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define PB push_back
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
const ll INF = (1ll << 60);
typedef pair<ll,ll> pii;

struct RUQ{
  ll size;
  ll *tree;
  vi history;
  RUQ(ll sz){
    ll logsize; for(logsize=0;(1ll<<logsize)<=sz;logsize++);
    size=(1ll<<logsize);
    tree=new ll[size*2-1]; REP(i, size*2-1) tree[i]=0;
  }
  void update(ll s,ll t,ll x){
    ll id=history.size();
    updatesub(s,t,0,size,0,id);
    history.push_back(x);
  }
  void updatesub(ll s,ll t,ll l,ll r,ll k,ll id){
    if(r<=s||t<=l||l>=r) return;
    if(l+1==r) {tree[k]=id; return;}
    if(s<=l&&r<=t) {tree[k]=id; return;}
    ll mid=(l+r+1)/2;
    updatesub(s,t,l,mid,k*2+1,id);
    updatesub(s,t,mid,r,k*2+2,id);
  }
  ll find(ll i){
    ll k=size+i-1;
    ll recent=tree[k];
    while(k>0){
      k=(k-1)/2;
      recent=max(recent,tree[k]);
    }
    return history[recent];
  }
};

int main(){
  ll n,q; cin>>n>>q;
  RUQ ruq(n);
  ruq.update(0,n,(1ll<<31)-1);
  REP(i,q){
    ll com;cin>>com;
    if(com==0) {ll s,t,x; cin>>s>>t>>x; ruq.update(s,t+1,x);}
    else {ll i; cin>>i; cout<<ruq.find(i)<<endl;}
  }
}