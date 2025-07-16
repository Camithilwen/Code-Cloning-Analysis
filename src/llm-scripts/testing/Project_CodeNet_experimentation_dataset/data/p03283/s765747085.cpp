#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 10000;
ll fac[MAX], finv[MAX], inv[MAX];


int main (){
  ll n,m,q;cin>>n>>m>>q;
  vvll a(509,vll(509,0));
  rep(i,0,m){
    ll l,r;cin>>l>>r;
    a[l][r]++;
  }
  rep(i,1,n+1){
    rep(j,1,n+1){
      a[i][j]+=a[i][j-1];
    }
  }
  rep(i,1,n+1){
    rep(j,1,n+1){
      a[i][j]+=a[i-1][j];
    }
  }
  rep(i,0,q){
    ll p,q;cin>>p>>q;
    cout<<a[q][q]+a[p-1][p-1]-a[p-1][q]-a[q][p-1]<<endl;
  }
  
}