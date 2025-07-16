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
////////////////////////////

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
ll p1=1009;

int main(){fastio
    ll n;cin>>n;
    ll a[n+1],b[2*n];
    rep(i,0,n-1)cin>>a[i];
    a[n]=a[0];
    rep(i,0,n-1)cin>>b[i];
    rep(i,n,2*n-1)b[i]=b[i%n];
    ll c[n],d[2*n-1];
    rep(i,0,n-1)c[i]=a[i+1]^a[i];
    rep(i,0,2*n-2)d[i]=b[i+1]^b[i];
    ll sc[n+1],sd[2*n];
    sc[0]=0;sd[0]=0;
    rep(i,0,n-1){
        sc[i+1]=c[i]*po(p1,i);
        Add(sc[i+1],sc[i]);
    }
    vector<l_l>ans;
    rep(i,0,2*n-2){
        sd[i+1]=d[i]*po(p1,i);
        Add(sd[i+1],sd[i]);
    }
  //  rep(i,0,n)cout<<sc[i]<<" ";cout<<endl;
  //  rep(i,0,2*n-1)cout<<sd[i]<<" ";cout<<endl;
    rep(i,n,2*n-1){
        ll sum=mod(sd[i]-sd[i-n])*bunbo(po(p1,i-n));
        ll y=b[i]^a[0];
        if(mod(sum-sc[n])==0){
            if(i==n)ans.pb(l_l(0,y));
            else ans.pb(l_l(2*n-i,y));
        }
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x.fi<<" "<<x.se<<endl;
    }
    
    return 0;
}
