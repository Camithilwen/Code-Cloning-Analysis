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
const ll match[10]={inf,2,5,5,4,5,6,3,7,6};
void update(string &a,string b){
    if(a=="x")a=b;
    else if(a.size()<b.size())a=b;
    else if(a.size()==b.size()){
        if(a<b)a=b;
    }
}
int main(){
    ll n,m;cin >> n >> m;
    vl a(m);rep(i,m)cin >> a[i];
    string dp[10100];
    rep(i,10100){
        dp[i]="x";
    }
    dp[0]="";
    rep(i,n+1){
        if(dp[i]=="x")continue;
        for(auto p:a){
            update(dp[i+match[p]],dp[i]+to_string(p));
        }
    }
    cout << dp[n] <<endl;
}