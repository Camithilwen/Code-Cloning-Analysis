#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
ll n;
vector< pair<ll,ll> > adj[N];
vector< pair< pair<ll,ll> , ll > >wt;
bool cmp( pair< pair<ll,ll> , ll > a,pair< pair<ll,ll> ,ll >b){
    return a.second<b.second;
}
ll par[N],sz[N];
void init(){
    for(ll i=0;i<N;i++)par[i]=i,sz[i]=1;
}
ll dsu_parent(ll node){
    if(node==par[node])return node;
    return par[node]=dsu_parent(par[node]);
}
void dsu_union(ll a,ll b){
    a=dsu_parent(a);
    b=dsu_parent(b);
    if(a==b)return;
    if(sz[a]<sz[b])swap(a,b);
    sz[a]+=sz[b];
    par[b]=a;
}
ll func(){
    ll ans = 0;
    for(ll i=1;i<=n;i++)for(auto &ele:adj[i])wt.push_back( { {i,ele.second} , ele.first} );
    sort(wt.begin(),wt.end(),cmp);
    init();
    for(auto &edges:wt){
       // cout<<edges.first.first<<" "<<edges.first.second<<" "<<edges.second<<endl;
        ll u=edges.first.first,v=edges.first.second,w=edges.second;
        if(dsu_parent(u)==dsu_parent(v))continue;
        ans+=w;
        dsu_union(u,v);
    }
    return ans;
}
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    cin>>n;
    pair<ll,ll> x[n],y[n];
    for(ll i=0;i<n;i++)cin>>x[i].first>>y[i].first,x[i].second=y[i].second=i+1;
    sort(x,x+n);
    sort(y,y+n);
    for(ll i=1;i<n;i++){
        adj[x[i].second].push_back({x[i].first-x[i-1].first , x[i-1].second});
        adj[x[i-1].second].push_back({x[i].first-x[i-1].first , x[i].second});

        adj[y[i].second].push_back({y[i].first-y[i-1].first , y[i-1].second});
        adj[y[i-1].second].push_back({y[i].first-y[i-1].first , y[i].second});
    }
    cout<<func();
}


