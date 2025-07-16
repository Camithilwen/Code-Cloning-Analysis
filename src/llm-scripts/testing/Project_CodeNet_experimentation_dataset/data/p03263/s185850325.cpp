#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll h,w;cin >> h >>w;
    vvl g(h,vl(w));
    rep(i,h){
        rep(j,w){
            cin >> g[i][j];
            g[i][j]%=2;
        }
    }
    vector<pair<pl,pl>> ans;
    rep(i,h){
        if(i%2==0){
            rep(j,w-1){
                if(g[i][j]){
                    ans.pb({{i,j},{i,j+1}});
                    g[i][j+1]++;
                    g[i][j+1]%=2;
                }
            }
            if(g[i][w-1]){
                if(i+1<h){
                    ans.pb({{i,w-1},{i+1,w-1}});
                    g[i+1][w-1]++;
                    g[i+1][w-1]%=2;
                }
            }
        }
        else{
            per(j,w-1){
                if(g[i][j+1]){
                    ans.pb({{i,j+1},{i,j}});
                    g[i][j]++;
                    g[i][j]%=2;
                }
            }
            if(g[i][0]){
                if(i+1<h){
                    ans.pb({{i,0},{i+1,0}});
                    g[i+1][0]++;
                    g[i+1][0]%=2;
                }
            }
        }
    }
    cout << ans.size() <<endl;
    for(auto p:ans){
        cout << p.fi.fi+1 <<" " << p.fi.se+1 <<" "<<p.se.fi+1 << " " << p.se.se+1 <<endl;
    }
}