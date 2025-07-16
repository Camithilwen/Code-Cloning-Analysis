#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
  ll n;cin >> n;
  vvl g(n,vl(n));rep(i,n)rep(j,n)cin >> g[i][j];
  vl sum(1<<n);
  rep(bit,1<<n){
    ll ret=0;
    rep(i,n)repl(j,i+1,n)if((bit&(1<<i))&&(bit&(1<<j)))ret+=g[i][j];
    sum[bit]=ret;
  }
  //rep(i,1<<n)cout << sum[i] <<" ";cout << endl;
  rep(bit,1<<n){
    vl z;rep(i,n)if(bit&(1<<i))z.pb(i);
    rep(cit,1<<z.size()){
      ll d=0,e=0;
      rep(j,z.size()){
        if(cit&(1<<j))d+=1<<z[j];
        else e+=1<<z[j];
      }
      if(d>e)break;
      //cout << bit <<" " << d << " " << e <<endl;
      chmax(sum[bit],sum[d]+sum[e]);
    }
  }
  //rep(i,1<<n)cout << sum[i] <<" ";cout << endl;
  cout << sum[(1<<n)-1] <<endl;
}