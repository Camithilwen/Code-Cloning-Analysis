//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
typedef pair<dd,dd> d_d;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define endl "\n"
///////////////////////////

ll po(ll i,ll p){
    if(p==0)return 1;
    else{
        i=mod(i);
        if(p==1)return i;
        if(p%2==0)return po(mod(i*i),p/2);
        return mod(i*po(i,p-1));
    }
}
ll bunbo(ll n){
    return po(n,i_5);
}
#define N 300
int main(){fastio
    ll bun[N];
    rep(i,1,N-1)bun[i]=bunbo(i);
    ll n,x;cin>>n>>x;
    ll s[n];rep(i,0,n-1)cin>>s[i];
    sort(s,s+n);
    reverse(s,s+n);
    ll dp[x+1][n+1];memset(dp,0,sizeof(dp));
    ll kai=1;rep(i,1,n)kai=mod(kai*i);
    dp[x][0]=kai;
    rep(i,0,n-1){
        rep(j,0,x){
            ll c=mod(dp[j][i]*bun[n-i]);
            if(c==0)continue;
            Add(dp[j][i+1],c*(n-i-1));
            Add(dp[j%s[i]][i+1],c);
        }
    }
    /*
    rep(i,0,x){
        rep(j,0,n){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }*/
    ll ans=0;
    rep(i,0,x){
        Add(ans,i*dp[i][n]);
    }
    cout<<ans<<endl;
    
    return 0;
}
