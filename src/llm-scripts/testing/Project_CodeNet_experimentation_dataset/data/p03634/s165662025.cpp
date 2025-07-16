#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define inf LLONG_MAX>>2
#define MAX 1000000
#define mod 1000000007
#define pb push_back
#define f(i,a,n,x) for ((i)=(a);(i)<(n);(i)+=(x))
#define fd(i,a,n,x) for ((i)=(a);(i)>=(n);(i)-=(x))
#define fi first
#define se second
#define mk make_pair
#define pi pair
#define vt vector
using namespace std;
void read(vt<ll> &a,ll n){ll i,temp;f(i,0,n,1){cin>>temp;a.pb(temp);}}
void dfs(ll k,vt<vt<pi<ll,ll>>> &adj,vt<bool> &visited,vt<ll> &dist){
    ll i;
    visited[k]=true;
    f(i,0,adj[k].size(),1)
        if (!visited[adj[k][i].fi]){
            dist[adj[k][i].fi]=dist[k]+adj[k][i].se;
            dfs(adj[k][i].fi,adj,visited,dist);
        }
}
void solve(){
    ll n,i,a,b,c,q,k;
    cin>>n;
    vt<vt<pi<ll,ll>>> adj(n+1);
    vt<ll> dist(n+1);
    vt<bool> visited(n+1,false);
    f(i,1,n,1){
        cin>>a>>b>>c;
        adj[a].pb(mk(b,c));
        adj[b].pb(mk(a,c));
    }
    cin>>q>>k;
    dist[k]=0;
    dfs(k,adj,visited,dist);
    f(i,0,q,1){
        cin>>a>>b;
        cout<<dist[a]+dist[b]<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}