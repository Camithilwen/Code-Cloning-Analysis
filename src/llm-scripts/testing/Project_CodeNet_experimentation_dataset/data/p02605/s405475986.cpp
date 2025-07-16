#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
signed main(){
    ll n;cin>>n;
    map<ll,vector<pll> >x,y;
    map<ll,vector<pll> >xpy;
    map<ll,vector<pll> >ymx;
    rep(i,n){
        ll a,b;cin>>a>>b;
        char c;cin>>c;
        ll d=0;
        if(c=='R')d=0;
        if(c=='U')d=1;
        if(c=='L')d=2;
        if(c=='D')d=3;

        x[a].pb(mp(b,d));
        y[b].pb(mp(a,d));
        xpy[a+b].pb(mp(a,d));
        ymx[b-a+200000].pb(mp(a,d));
    }
    ll ans=inf*inf;
    for(auto s:x){
        ll u=-1,d=-1;
        ll i=s.first;
        sort(all(x[i]));
        for(auto e:x[i]){
            if(e.second==1)d=e.first;
            if(e.second==3)u=e.first;
            if(u>=0&&d>=0&&u-d>=0){
                ans=min(ans,(u-d)*5);
            }
        }
    }
    for(auto s:y){
        ll l=-1,r=-1;
        ll i=s.first;
        sort(all(y[i]));
        for(auto e:y[i]){
            if(e.second==0)l=e.first;
            if(e.second==2)r=e.first;
            if(l>=0&&r>=0&&r-l>=0){
                ans=min(ans,(r-l)*5);
            }
        }
    }
    for(auto s:xpy){
        ll l=-1,r=-1,u=-1,d=-1;
        ll i=s.first;
        sort(all(xpy[i]));
        for(auto e:xpy[i]){
            if(e.second==0)l=e.first;
            if(e.second==2)r=e.first;
            if(e.second==1)d=e.first;
            if(e.second==3)u=e.first;
            if(l>=0&&d>=0&&d>=l)ans=min(ans,(d-l)*10);
            if(r>=0&&u>=0&&r>=u)ans=min(ans,(r-u)*10);
        }
    }
    for(auto s:ymx){
        ll l=-1,r=-1,u=-1,d=-1;
        ll i=s.first;
        sort(all(ymx[i]));
        for(auto e:ymx[i]){
            if(e.second==0)l=e.first;
            if(e.second==2)r=e.first;
            if(e.second==1)d=e.first;
            if(e.second==3)u=e.first;
            if(l>=0&&u>=0&&u>=l)ans=min(ans,(u-l)*10);
            if(r>=0&&d>=0&&r>=d)ans=min(ans,(r-d)*10);
        }
    }
    if(ans==inf*inf){
        cout<<"SAFE"<<endl;
    }else{
        cout<<ans<<endl;
    }
}