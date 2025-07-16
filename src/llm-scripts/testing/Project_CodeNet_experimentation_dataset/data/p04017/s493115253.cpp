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
    ll n;cin >> n;
    vl a(n);rep(i,n)cin >> a[i];
    ll l;cin >> l;
    vvl v(21,vl(n));
    rep(i,n){
        auto itr=upper_bound(all(a),a[i]+l);
        itr--;
        v[0][i]=itr-a.begin();
        if(i==n-1)v[0][i]=inf;
    }
    rep(j,20){
        rep(i,n){
            if(v[j][i]==inf)v[j+1][i]=inf;
            else v[j+1][i]=v[j][v[j][i]];
        }
    }
    /*rep(j,20){
        rep(i,n){
            cout << v[j][i] <<" ";
        }
        cout << endl;
    }*/
    //exit(0);
    ll q;cin >> q;
    while(q--){
        ll a,b;cin >> a >> b;a--;b--;
        if(a>b)swap(a,b);
        ll ng=0,ok=100000;
        while(abs(ok-ng)>1){
            ll mid=(ok+ng)/2;
            ll t=a;
            rep(i,20){
                if(t==inf)break;
                if(mid&(1<<i)){
                    t=v[i][t];
                }
            }
            if(t>=b)ok=mid;
            else ng=mid;
        }
        cout << ok <<endl;
    }
}