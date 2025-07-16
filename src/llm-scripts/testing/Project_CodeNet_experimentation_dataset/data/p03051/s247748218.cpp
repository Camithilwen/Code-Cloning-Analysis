#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll inf=1000000000000000000;
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n,m) for(int i=n;i>=m;i--)
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gya[200010];
ll kai[200010];
ll beki(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k%2==1){
            ret*=now;
            ret%=mod;
        }
        now*=now;
        now%=mod;
        k/=2;
    }
    return ret;
}
ll gyaku(ll n){
    return beki(n,mod-2);
}
void nckinit(ll n){
    gya[0]=1;
    gya[1]=1;
    for(int i=2;i<=n;i++){
        gya[i]=gya[i-1]*gyaku(i);
        gya[i]%=mod;
    }
    kai[0]=1;
    kai[1]=1;
    for(int i=2;i<=n;i++){
        kai[i]=kai[i-1]*i;
        kai[i]%=mod;
    }
}
ll nck(ll n,ll k){
    if(k<0)return 0;
    if(k==0||n==k)return 1;
    ll ret=kai[n];
    ret*=gya[n-k];
    ret%=mod;
    ret*=gya[k];
    ret%=mod;
    return ret;
}
ll npk(ll n,ll k){
    if(k<0)return 0;
    if(k==0)return 1;
    ll ret=kai[n];
    ret*=gya[n-k];
    ret%=mod;
    return ret;
}
int main(){
    
    ll n;cin>>n;
    ll a[n];rep(i,0,n)cin>>a[i];
    ll b[n];
    b[0]=a[0];
    rep(i,1,n)b[i]=b[i-1]^a[i];
    vector<ll> w;
    rep(i,0,n)w.push_back(b[i]);
    sort(w.begin(),w.end());
    w.erase(unique(w.begin(),w.end()),w.end());
    unordered_map<ll,ll> mp;
    rep(i,0,w.size()){
        if(w[i]==0)mp[w[i]]=0;
        else mp[w[i]]=i+1;
    }
    rep(i,0,n)b[i]=mp[b[i]];
    ll m=w.size();
    vector<ll> v[m+2];
    rep(i,0,n){
        
        v[b[i]].push_back(i);
    }
    //rep(i,0,n)cout<<b[i]<<" ";
    bool used[m+2];
    ll ans=0;
    fill(used,used+m+2,false);
    rep(i,0,n-1){
        //cout<<ans<<" ";
        if(used[b[i]])continue;
        if(b[i]==0&&b[n-1]==0){
            ll y=beki(2,v[0].size()-1);
            y--;
            y=(y+mod)%mod;
            ans+=y;
            ans%=mod;
            used[0]=true;
            continue;
        }
        if(b[n-1]!=0&&b[i]!=b[n-1])continue;
        used[b[i]]=true;
            ll jou=1,ka=1;
            ll now=lower_bound(v[0].begin(),v[0].end(),i)-v[0].begin();
        //cout<<now<<endl;
            rep(j,1,v[b[i]].size()){
                ll ne=v[b[i]][j];
                ll r=lower_bound(v[0].begin(),v[0].end(),ne)-v[0].begin();
                jou+=ka*(r-now);
                jou%=mod;
                ka+=jou;
                ka%=mod;
                now=r;
            }
        if(b[n-1]==b[i]){
            ans=(ans+jou-1+mod)%mod;
            continue;
        }
        if(v[b[i]].size()==1){
            ans=(ans+1)%mod;
            continue;
        }
        ans=(ans+ka)%mod;
        
    }
    ans=(ans+1)%mod;
    cout<<ans<<endl;
}
