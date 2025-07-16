#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define mod 998244353
const ll N =30005 ;
ll dp[2*N] ;


int main ()
{
    ll n , t ;
    cin>> n >> t ;
    ll i ,j,x,y;
    dp[0] = 1 ;
    vector<pair<ll,ll> > v(n) ;
    for(i = 0 ; i< n ;i++) cin >> v[i].first >> v[i].second ;
    sort(v.begin(),v.end()) ;
    for(i = 1 ; i<= n ; i++) {
        x = v[i-1].first , y = v[i-1].second ;
        for (j = t-1 ; j>=0 ; j--) if (dp[j]) dp[j+x] = max(dp[j+x],dp[j]+y) ;

    }
    ll ans = 0 ;
    for (i = 0 ; i<2*N ; i++) ans = max(ans,dp[i]) ;
    cout << ans -1 << endl ;
    return 0 ;
}

