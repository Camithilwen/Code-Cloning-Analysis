#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Graph= vector<vector<ll>>;
struct edge{ll to ; ll cost ;} ;
using graph =vector<vector<edge>> ;
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
#define fi first
#define se second 
#define set20 cout<<fixed<<setprecision(20) ;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
double pi=acos(-1) ;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
 

 int main(){
ll n ; cin>> n ;
vector<string> A(n) ;
rep(i,n) cin>>A[i] ;
vector<ll> sum(n) ,sa(n) ;
rep(i,n){
  ll k= A[i].size() ;
  ll now=0 ;
  ll ans=0 ;
  rep(j,k){
   if(A[i][j]==')') now-- ;
   else now++ ;
   chmin(ans,now)  ;
  }
  sum[i]= now ;
  sa[i]= ans ;
}
 vector<P> B, D ;
 ll zero =0 ;

  rep(i,n){
   if(sum[i]>0){
   P xx= mpa(sa[i],sum[i]) ;
   B.pb(xx) ;
   }
   if(sum[i]==0) chmin(zero,sa[i]) ;
   if(sum[i]<0){
     P yy= mpa(sum[i]-sa[i],sum[i]) ;
     D.pb(yy) ;
   }

  }

  sort(B.rbegin(),B.rend()) ;
  sort(D.begin(),D.end()) ;
  ll ok= B.size() ;
  ll ko= D.size() ; 
  ll start= 0 ;
  bool flag= 0;

  rep(i,ok){
  if(start+ B[i].fi<0) flag=1;
  start+= B[i].se ;
  }

  if(start+zero<0) flag=1 ;
  ll goal =0 ;
  rep(i,ko){
    if(goal-D[i].fi<0) flag=1 ;
     goal -= D[i].se ;
  }
  if(start!=goal) flag=1 ;
 
  if(flag) cout<<"No"<<endl ;
  else cout<<"Yes"<<endl ;
   return 0 ;
}

