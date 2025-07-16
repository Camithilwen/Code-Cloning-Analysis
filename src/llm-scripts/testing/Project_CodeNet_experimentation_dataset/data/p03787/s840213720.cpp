#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
bool flg;
vector<ll> adj[N],col(N);
void dfs(ll node,ll clr){
    if(col[node]!=0){
        if(col[node]!=clr)flg=0;
        return;
    }
    col[node]=clr;
    for(auto &v:adj[node])dfs(v,-clr);
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,m;cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll c1=0,c2=0,c3=0;
    for(ll i=1;i<=n;i++){
        if(col[i]!=0)continue;

        if(adj[i].size()==0)c1++;
        else{
            flg=1;
            dfs(i,1);
            if(flg)c2++;
            else c3++;
        }
    }
    ll ans = 2*n*c1 - c1*c1 + c3*c3 + 2*c3*c2 + 2*c2*c2;
    cout<<ans;
}