#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb emplace_back
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
#define dupli(a) erase(unique(all(a)),a.end())
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
vi parent,rankk,sz;
void init(ll n){
    parent=vi(n);
    rankk=vi(n);
    sz=vi(n,1);
    rep(i,n)parent[i]=i;
}
ll root(ll i){if(parent[i]==i)return i;return root(parent[i]);}
ll getsize(ll i){return sz[root(i)];}
bool same(ll a,ll b){return root(a)==root(b);}
bool heigou(ll x,ll y){
    x=root(x);y=root(y);
    if(x==y)return false;
    if(rankk[x]<rankk[y]){parent[x]=y;sz[y]+=sz[x];}
    else{parent[y]=x;sz[x]+=sz[y];}
    if(rankk[x]==rankk[y])rankk[x]++;
    return true;
}
int main(){
    ll n,k,m;cin>>n>>k>>m;
    init(n);
    rep(i,k){
        ll a,b;cin>>a>>b;a--;b--;
        heigou(a,b);
    }
    vvi g(n);
    rep(i,m){
        ll a,b;cin>>a>>b;a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vi ans(n);
    vb used(n,false);
    rep(i,n)if(!used[i]){
        queue<ll> q;
        q.push(i);
        used[i]=true;
        vp v;
        while(!q.empty()){
            ll t=q.front();q.pop();
            v.pb(root(t),t);
            for(ll x:g[t])if(!used[x]){
                used[x]=true;
                q.push(x);
            }
        }
        sort(all(v));
        int w=0,k=0;
        while(w<v.size()){
            k=w;
            while(w<v.size()){
                if(v[w].fi!=v[k].fi)break;
                w++;
            }
            REP(j,k,w)ans[v[j].se]=w-k;
        }
    }
    outv(ans);
}