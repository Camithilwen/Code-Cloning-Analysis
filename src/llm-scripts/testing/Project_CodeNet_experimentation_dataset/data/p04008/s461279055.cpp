#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
/// khodaya komak kon
/// ya navid navid
const int N=2e5+100;
ll seg[4*N];
void shift(ll nod){
    if (seg[nod]==1){
        seg[nod*2]=1;
        seg[nod*2+1]=1;
    }
}
void upd(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r){
        return ;
    }
    if (l>=L && r<=R){
        seg[nod]=1;
        return ;
    }
    shift(nod);
    ll mid=(r+l)/2;
    upd(nod*2,l,mid,L,R);
    upd(nod*2+1,mid,r,L,R);
}
ll get(ll nod,ll l,ll r,ll id){
    if (r-l==1){
        return seg[nod];
    }
    shift(nod);
    ll mid=(r+l)/2;
    if (mid>id){
        return get(nod*2,l,mid,id);
    }
    else{
        return get(nod*2+1,mid,r,id);
    }
}
ll k;
vector <pii> h;
ll st[N];
ll fn[N];
vector <int> g[N];
ll cnt=0;
ll par[N];
vector <int> t;
ll par1[N];
ll dfs(ll v,ll p,ll hi){
    par1[v]=p;
    t.pb(v);
    ll z=t.size();
    z-=k;
    z=max((ll)0,z);
    par[v]=t[z];
    h.pb({hi,v});
    st[v]=cnt;
    for (int i=0;i<g[v].size();i++){
        ll u=g[v][i];
        if (u==p){
            continue;
        }
        cnt++;
        dfs(u,v,hi+1);
    }
    t.pop_back();
    fn[v]=cnt;
}
int32_t main(){
    sync;
    ll n;
    cin >> n >> k;
    ll ans=0;
    ll x;
    cin >> x;
    if (x!=1){
        ans++;
    }
    for (int i=2;i<=n;i++){
        cin >> x;
        g[x].pb(i);
        g[i].pb(x);
    }
    upd(1,0,N,0,1);
    dfs(1,1,0);
    sort(h.begin(),h.end());
    reverse(h.begin(),h.end());
    for (int i=0;i<n-1;i++){
        ll v=h[i].S;
        ll u=par[v];
        //cout << v << " " << u << endl;
        ll z=get(1,0,N,st[v]);
        if (z==1 || par1[u]==1){
            continue;
        }
        ans++;
        upd(1,0,N,st[u],fn[u]+1);
    }
    cout << ans;
}
