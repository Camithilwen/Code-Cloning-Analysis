#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define INF (1ll<<60)
#define mod 1000000007
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> sums,sumg;
void pre_process(vector<ll> &a,vector<ll> &s){//累積和のvector
    ll n=(ll)a.size();
    s.assign(n+1,0);
    for(ll i=0;i<n;i++){
        s[i+1]=s[i]+a[i];
    }
}

int main(){
    ll n,m,Q;cin>>n>>m>>Q;
    vector<P> pairs;

    rep(i,m){
        ll pf,ps;cin>>pf>>ps;
        pf--;ps--;
        pairs.push_back({pf,ps});
    }
    sort(pairs.begin(),pairs.end());

    vector<vector<ll>> list(510,vector<ll>(510)),sum(510);
    rep(i,m){
        list[pairs[i].fi+1][pairs[i].se]++;
    }
    rep(i,510){
        pre_process(list[i],sum[i]);
    }
/*
    rep(i,11){
        rep(j,11){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    rep(i,Q){
        ll p,q,ans=0;cin>>p>>q;
        for(ll i=p;i<=q;i++){
            ans+=sum[i][q];
        }
        cout<<ans<<endl;
    }
    return 0;
}