#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    vector<pll>p(n);
    rep(i,n){
        cin>>p[i].first>>p[i].second;
    }
    sort(all(p));
    reverse(all(p));
    ll mal=p[0].first;
    ll r=p[0].second;
    rep(i,n){
        swap(p[i].first,p[i].second);
    }
    sort(all(p));
    ll ans=0;
    ll mir=p[0].first;
    ll L=p[0].second;
    ll ma=0;
    rep(i,n){
        if(i>0)ma=max(p[i].first-p[i].second+1,ma);
    }
    ans=ma+max(0LL,mir-mal+1);
    L=p[0].second;
    REP(i,1,n){
        ans=max(mir-L+1+max(0LL,p[i].first-mal+1),ans);
        L=max(L,p[i].second);
    }
    cout<<ans<<endl;
}