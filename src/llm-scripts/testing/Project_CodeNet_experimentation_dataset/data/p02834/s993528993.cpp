#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N;
ll u,v;
ll ans;
vector<ll> vec[100005];
ll parent[100005];
bool leaf[100005]; //falseなら葉
void tree(ll par,ll n){
    if(parent[n]!=0)  return;
    parent[n]=par;
    for(auto &i:vec[n]) tree(n,i);
    return;
}
ll Adis[100005];
ll Tdis[100005];
void Adfs(ll n,ll dis){
    if(Adis[n]!=-1) return;
    Adis[n]=dis;
    for(auto&i:vec[n]) Adfs(i,dis+1);
    return;
}
void Tdfs(ll n,ll dis){
    if(Tdis[n]!=-1) return;
    Tdis[n]=dis;
    for(auto&i:vec[n]) Tdfs(i,dis+1);
    return;
}
int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>u>>v;
rep(i,N-1){
    ll a,b;
    cin>>a>>b;
    vec[a].pb(b);
    vec[b].pb(a);
}
tree(-1,v);
rep1(i,N+1){
    ll n=parent[i];
    if(n!=-1) leaf[n]=true;
}
fill(Adis+1,Adis+N+1,-1);
fill(Tdis+1,Tdis+N+1,-1);
Adfs(v,0);
Tdfs(u,0);
rep1(i,N+1){
    if(!leaf[i]){
        if(Tdis[i]<Adis[i]) ans=max(ans,Adis[i]);
    }
}
cout<<ans-1<<endl;

}
    
