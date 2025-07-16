#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};
struct edge2{ll from,to,cost;};

const ll MXN=100000;
vl G[MXN];
vvl d(2,vl(MXN,INF));

void dfs(ll x,ll v,ll z){
    d[x][v]=z;
    rep(i,G[v].size()){
        if(d[x][G[v][i]]==INF){
            dfs(x,G[v][i],z+1);
        }
    }
}

int main() {
    ll N,u,v;
    cin >> N >> u >> v;
    u--;v--;
    rep(i,N-1){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(0,u,0);
    dfs(1,v,0);
    ll D=0;
    rep(i,N){
        if(d[0][i]<d[1][i]){
            D=max(D,d[1][i]);
        }
    }
    cout << D-1 << endl;
}