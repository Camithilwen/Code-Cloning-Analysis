#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<v<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

vector<vector<ll>> G(100007, vector<ll>(0));

void dfs(ll x,vl &d,ll dist){
    d[x]=dist;
    for(auto p: G[x]){
        if(d[p]==INF)dfs(p,d,dist+1);
    }
}

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll u;
    cin >> u;u--;
    ll v;
    cin >> v;v--;
    vector<ll> A(N-1,0);
    vector<ll> B(N-1,0);
    for(ll i=0;i<N-1;++i){
        cin>>A[i]>>B[i];
        A[i]--;B[i]--;
        G[A[i]].emplace_back(B[i]);
        G[B[i]].emplace_back(A[i]);
    }
    vector<ll> du(N,INF);
    vector<ll> dv(N,INF);
    dfs(u,du,0);
    dfs(v,dv,0);
    ll mark;
    ll ou=-INF;
    for(ll i=0;i<N;++i){
        if(du[i]<dv[i]&&chmax(ou,dv[i]))mark=i;
    }
    ll nige=du[mark];
    ll ans=nige;
    ll S=ou-nige;//Sは1以上
    if(S==1)ans+=0;
    else if(S==2)ans++;
    else {
        ans+=((S-2)/2)*2;
        S-=((S-2)/2)*2;
        if(S==3)ans+=2;
        else ans++;
    }
    prt(ans)



    return 0;
}
