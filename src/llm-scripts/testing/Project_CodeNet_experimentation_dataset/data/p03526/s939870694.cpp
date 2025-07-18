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
#define dupli(a) a.erase(unique(all(a)),a.end())
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
typedef multiset<ll> S;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vvvvi=vector<vvvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001001;
const ll INF=1001001001;
const ll mod=1000000007;
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
vp seg;
ll N=1;
void init(vi v){
    while(N<v.size())N*=2;
    seg=vp(N*2-1,P(-inf,-1));
    rep(i,v.size())seg[i+N-1]=P(v[i],i);
    for(int i=N-2;i>=0;i--)seg[i]=max(seg[i*2+1],seg[i*2+2]);
}
void add(ll i,ll x){
    i=N+i-1;
    seg[i].first+=x;
    while(i>0){
        i=(i-1)/2;
        seg[i]=max(seg[i*2+1],seg[i*2+2]);
    }
}
P getma(ll a,ll b,ll k,ll l,ll r){
    if(r<=a||b<=l)return P(-inf,-1);
    if(a<=l&&r<=b)return seg[k];
    P c1=getma(a,b,k*2+1,l,(l+r)/2);
    P c2=getma(a,b,k*2+2,(l+r)/2,r);
    return max(c1,c2);
}
int main(){
    ll n;cin>>n;
    vi a(n),b(n);
    rep(i,n)cin>>a[i]>>b[i];
    vp v(n);
    rep(i,n)v[i]=P(a[i]+b[i],i);
    sort(all(v));
    vi dp(n+1,inf);
    dp[0]=0;
    rep(i,n){
        for(int j=i;j>=0;j--){
            if(dp[j]<=a[v[i].se])chmin(dp[j+1],dp[j]+b[v[i].se]);
        }
    }
    for(int i=n;i>=0;i--)if(dp[i]!=inf)dame(i);
}