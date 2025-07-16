#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph= vector<vector<int>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

 
int main(){
   int n ; cin>>n ;
   cout<< 0 <<endl ;
   string s ; cin >>s ;
   if(s=="Vacant") return 0 ;
   int l =0 ; int r= n ;
   while(1){
     int m = (r+l) /2 ;
     cout<< m<< endl ;
     string ss ;cin>>ss ;
     if(ss=="Vacant" ) break ;
     bool ok= (s==ss) ;
     int a = m%2 ;
     if(ok==a) r=m ;
    else l= m+1 ;

   }
 return 0 ;
}
