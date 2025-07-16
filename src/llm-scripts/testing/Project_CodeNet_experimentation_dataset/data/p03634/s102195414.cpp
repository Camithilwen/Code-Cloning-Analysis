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
const ll INF=1LL<<62;
const ll MOD=1000000007;

ll N,Q,K;
vector<ll> a(100007,0);
vector<ll> b(100007,0);
vector<ll> c(100007,0);
vector<ll> x(100007,0);
vector<ll> y(100007,0);
vector<ll> d(100007,INF);
vector<vector<P>> G(100007, vector<P>(0));

void dfs(ll x){
    for(auto p: G[x]){
        ll s=p.first,t=p.second;
        if(d[s]==INF){d[s]=d[x]+t;dfs(s);}
    }
}

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    cin >> N;
    for(ll i=0;i<N-1;++i){cin>>a[i]>>b[i]>>c[i];a[i]--;b[i]--;}
    for(ll i=0;i<N-1;++i){
        G[a[i]].emplace_back(P(b[i],c[i]));
        G[b[i]].emplace_back(P(a[i],c[i]));
    }
    cin>>Q>>K;K--;
    for(ll i=0;i<Q;++i){cin>>x[i]>>y[i];x[i]--;y[i]--;}
    d[K]=0;
    dfs(K);

    for(ll i=0;i<Q;++i)prt(d[x[i]]+d[y[i]])
    

    return 0;
}
