#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define all(x) (x).begin() , (x).end()
#define f first
#define s second
#define pr(x) cout<<x<<endl;
#define pr2(x,y) cout<<x<<" "<<y<<endl;
#define pr3(x,y,z) cout<<x<<" "<<y<<endl;
#define prv(v) for(auto x:v) cout<<x<<" ";
using namespace std;
 
const ll N =(2e5+5);
const ll MOD = 1e9+7;
const ll INF = 1e16;
const ll LOG = 29;

long long binpow(long long a, long long b) {
     a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD ;
        a = (a * a)%MOD ;

        
        b >>= 1;
    }
    res%=MOD;
    return res;
}
vll adj[N];
vll adj2[N];
ll col[N];
ll col2[N];
bool vis[N];
bool vis2[N];
map<pll,ll> gg;
    void dfs(ll x,ll c)
        {
            vis[x]=true;    
            col[x]=c; 
            for(auto i : adj[x])
            {
                if(vis[i]==false)
                {
                    dfs(i,c);
                }
            }
        }    

    void dfs2(ll x,ll c)
        {
            vis2[x]=true;    
            col2[x]=c; 
            for(auto i : adj2[x])
            {
                if(vis2[i]==false)
                {
                    dfs2(i,c);
                }
            }
        }    

void solve(){
    ll n,k,l;
    cin>>n>>k>>l;
    for(int i =1;i<=k;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1;i<=l;i++){
        ll u,v;
        cin>>u>>v;
        adj2[u].pb(v);
        adj2[v].pb(u);
    }
    ll cur = 1;
    for(int i =1;i<=n;i++){
        if(!vis[i]){
            dfs(i,cur);
            cur++;
        }
    }
    cur =1;
    for(int i =1;i<=n;i++){
        if(!vis2[i]){
            dfs2(i,cur);
            cur++;
        }
    }

    for(int i =1;i<=n;i++){
        gg[mp(col[i],col2[i])]++;
    }
    for(int i =1;i<=n;i++){
        cout<<gg[mp(col[i],col2[i])]<<" ";
    }
    cout<<endl;

}






int main()
{
    ios_base::sync_with_stdio(0);
     cin.tie(NULL);
     
    ll t=1;
    while(t--){
        solve();
    }
     
 
 
    return 0;     
    
        
}