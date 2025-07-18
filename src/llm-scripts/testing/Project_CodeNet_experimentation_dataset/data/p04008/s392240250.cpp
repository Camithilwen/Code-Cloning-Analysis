#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
#define dame(a) {out(a);return 0;}
#define decimal cout<<fixed<<setprecision(15);
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
typedef multiset<ll> S;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001001;
const int INF=1001001001;
const int mod=1000000007;
const double eps=1e-10;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void noyes(T b){if(b)out("no");else out("yes");}
template<class T> void NoYes(T b){if(b)out("No");else out("Yes");}
template<class T> void NOYES(T b){if(b)out("NO");else out("YES");}
void outs(ll a,ll b){if(a>=inf-100)out(b);else out(a);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){a%=mod;if(b==0)return 1;if(b&1)return a*modpow(a,b-1)%mod;ll k=modpow(a,b/2);return k*k%mod;}
ll ans=0;
const int l=20;
vi dep;
vvi table;
vvi g;
void dfs0(int i,int p,int d){
    table[i][0]=p;
    dep[i]=d;
    for(ll x:g[i])if(x!=p)dfs0(x,i,d+1);
}
void init(ll n){
    g=vvi(n);
    dep=vi(n);
    table=vvi(n,vi(l,-1));
    rep(i,n-1){
        ll a;cin>>a;a--;
        g[a].pb(i+1);
        g[i+1].pb(a);
    }
    dfs0(0,-1,0);
}
vb done;
void dfs(int i){
    done[i]=true;
    for(ll x:g[i])if(x!=table[i][0]){
        if(!done[x])dfs(x);
    }
}
int main(){
    ll n,k,t;cin>>n>>k>>t;
    if(t!=1)ans++;
    if(k==1){
        rep(i,n-1){
            ll a;cin>>a;if(a!=1)ans++;
        }
        dame(ans);
    }
    init(n);
    REP(i,1,l){
        rep(j,n){
            ll id=table[j][i-1];
            if(id!=-1)table[j][i]=table[id][i-1];
        }
    }
    k--;
    vp v(n);
    rep(i,n)v[i]=P(dep[i],i);
    sort(all(v));reverse(all(v));
    done=vb(n,false);
    rep(tt,n){
        ll i=v[tt].se;
        if(dep[i]<=k+1)break;
        if(done[i])continue;
        ll w=i;
        rep(j,l)if(k>>j&1)w=table[w][j];
        ans++;
        dfs(w);
    }
    out(ans);
}