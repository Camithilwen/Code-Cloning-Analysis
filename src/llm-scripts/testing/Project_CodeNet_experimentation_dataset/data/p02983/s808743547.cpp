/*
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/
#include <bits/stdc++.h>
#define LL              long long
#define ll              long long
#define SL(n)           scanf("%lld",&n)
#define LF              double
#define SF(n)           scanf("%lf",&n)
 
#define pb              push_back
#define mp              make_pair
 
#define ON(n,i)         (n|(1LL<<i))
#define OFF(n,i)        (n&(~(1LL<<i)))
#define CHK(n,i)        (n&(1LL<<i))
 
#define ff              first
#define ss              second
 
#define SET(arr)        memset( arr , -1 , sizeof arr)
#define RESET(arr)      memset( arr,0,sizeof arr)
 
#define srt(v)          sort(v.begin(),v.end())
#define uniq(v)			v.resize(distance(v.begin(),unique(v.begin(),v.end())))
#define found( s,d )    (s.find(d) != s.end())
 
#define FOR(i,s,e)      for( LL i = s ; i<=e ; i++ )
#define RFOR(i,e,s)     for( LL i = e ; i>=s ; i-- )
         
 
#define FILEIN          freopen("in.txt","r",stdin)
#define FILEOUT         freopen("WA.txt","w",stdout)
 
#define DEBUG(x)        cerr<<#x<<" = "<<x<<endl
#define PRINTALL(v)     {cerr<<endl<<"Printing: "<<#v<<endl;for(LL i = 0 ; i<v.size(); i++) DEBUG(v[i]); cerr<<endl;}
 
using namespace std;

LL f[2019];

int main(){


    LL L,R;
    SL(L); SL(R);

    for( LL i = L ; i<= min(R,L+2019-1) ;i++ ) f[ i % 2019 ]++;

    LL mn = 1e18;
    for( LL i = 0 ; i<2019 ; i++ ){
        for( LL j = i+1 ; j<2019 ; j++ ){
            if( f[i] && f[j] ) mn = min(mn,(i*j)%2019);
        }
    }
    cout<<mn<<endl;
    
return 0;}