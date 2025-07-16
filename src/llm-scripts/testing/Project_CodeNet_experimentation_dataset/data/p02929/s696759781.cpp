#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
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
string alp="abcdefghijklmnopqrstuvwxyz";
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int main(){fastio
    ll n;cin>>n;
    string s;cin>>s;
    ll a[2*n];a[0]=0;
    ll b[2];rep(i,0,1)b[i]=0;
    b[0]++;
    rep(i,1,2*n-1){
        if(s[i]==s[i-1]){
            a[i]=1-a[i-1];
        }else{
            a[i]=a[i-1];
        }
        b[a[i]]++;
    }
    
    if(b[0]!=n || s[0]=='W' || s[2*n-1]=='W'){
        cout<<0<<endl;
        return 0;
    }
    
    ll sum=0;
    ll ans=1;
    rep(i,1,n){
        ans=mod(ans*i);
    }
    rep(i,0,2*n-1){
        //cout<<a[i];
        if(a[i]==0){
            sum++;
        }else{
            ans=mod(ans*sum);
            sum--;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}


