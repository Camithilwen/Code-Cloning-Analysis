
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
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
////////////////////////////

#define N 100004
ll d[N+1];
ll a[N+1];
vector<ll>c[N+1];
void dfs(ll k){
    for(auto x:c[k]){
        d[x]=d[k]+1;
        dfs(x);
    }
}
int main(){fastio
    ll n,k;cin>>n>>k;
    
    rep(i,1,n){
        cin>>a[i];
        if(i!=1)c[a[i]].pb(i);
    }
    ll ans=0;
    if(k==1){
        rep(i,1,n)if(a[i]!=1)ans++;
        cout<<ans<<endl;
        return 0;
    }
    if(a[1]!=1)ans++;
    dfs(1);d[1]=0;
    vector<ll>dep[N];
    rep(i,1,n)dep[d[i]].pb(i);
    l_l dp[n+1];
    for(ll i=N-1;i>=0;i--){
        if(i==0){
            for(auto x:c[1]){
                ans+=dp[x].first;
            }
        }
        for(auto x:dep[i]){
            ll ma=0,sum=0;
            for(auto y:c[x]){
                sum+=dp[y].first;
                if(dp[y].second==k){
                    sum++;
                }else{
                    Max(ma,dp[y].second);
                }
            }
            dp[x]=l_l(sum,ma+1);
        }
    }
    //rep(i,1,n)cout<<dp[i].first<<" "<<dp[i].second<<endl;
    cout<<ans<<endl;

    return 0;
}
