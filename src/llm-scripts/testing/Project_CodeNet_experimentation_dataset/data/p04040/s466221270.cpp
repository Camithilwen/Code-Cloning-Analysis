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

ll hpow(ll x,ll y){
    ll ans=1;
    ll i=x;
    if(y==0)return 1;
    while(y>0){
        if(y%2==1){
            ans=(ans*i)%i_7;
        }
        i=(i*i)%i_7;
        y=y/2;
        
    }
    return ans;
}

ll memop[2000000];
ll mkai(ll i){
    if(i==0){
        return 1;
    }
    if(memop[i]!=0){
        return memop[i];
    }else{
        ll ans=(mkai(i-1)*hpow(i,i_7-2))%i_7;
        memop[i]=ans;
        return ans;
    }
}

ll memok[2000000];
ll kai(ll i){
    if(i==0){
        return 1;
    }
    if(memok[i]!=0){
        return memok[i];
    }else{
        ll ans=(kai(i-1)*i)%i_7;
        memok[i]=ans;
        return ans;
    }
}

ll comb(ll n,ll k){
    ll ans=(kai(n)*mkai(k))%i_7;
    ans=(ans*mkai(n-k))%i_7;
    return ans;
}

int main(){
    ll h,w,a,b;cin>>h>>w>>a>>b;
    ll ans=0;
    rep(i,b,w-1){
        ans=(ans+(comb(h-a-1+i,h-a-1)*comb(a-1+w-1-i,a-1))%i_7)%i_7;
    }
    cout<<ans<<endl;
    return 0;
}
