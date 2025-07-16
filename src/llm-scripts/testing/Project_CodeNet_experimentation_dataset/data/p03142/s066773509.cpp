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
const ll dy[9]={1,0,-1,0,1,1,-1,-1,0};
const ll dx[9]={0,-1,0,1,1,-1,1,-1,0};
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
void dfs(ll v,ll par,set<ll> &st,vl &ans, vvl &g){
    for(auto nv:g[v]){
        if(par==nv)continue;
        if(ans[nv]==-1){
            ans[nv]=v;
            st.ins(v);dfs(nv,v,st,ans,g);st.erase(v);
        }
        else{
            if(st.count(ans[nv]))ans[nv]=v;
        }
    }
}
int main(){
    ll n,m;cin >>n >>m;
    vvl g(n);
    vl ans(n,-1);
    set<ll> st;rep(i,n)st.ins(i);
    rep(i,n-1+m){
        ll a,b;cin >> a >> b;a--;b--;
        g[a].pb(b);
        st.erase(b);
    }
    ll s=*st.begin();st.clear();
    dfs(s,-1,st,ans,g);
    for(auto p:ans)cout << p+1 <<endl;
} 