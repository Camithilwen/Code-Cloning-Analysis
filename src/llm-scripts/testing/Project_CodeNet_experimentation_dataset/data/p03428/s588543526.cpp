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
vi x,y,id;
ll dis(int i,int j){
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
double cross(int i,int j){
    if(x[i]==x[j]&&y[i]>y[j])return inf;
    if(x[i]==x[j]&&y[i]<y[j])return -inf;
    if(x[j]<x[i])return (y[i]-y[j])/(double)(x[i]-x[j]);
    if(x[j]>x[i])return (y[i]-y[j])/(double)(x[j]-x[i]);
}
vi Convex_Hull(){
    int n=x.size();
    if(n >= 3){
        vi ch;
        for(int i=0;i<n;i++){
            while(ch.size()>=2&&cross(ch.back(),ch[ch.size()-2])<cross(i,ch.back()))ch.pop_back();
            ch.eb(i);
        }
        ch.eb(n-2);
        for(int i=n-3,t=ch.size();i>=0;i--){
            while(ch.size()>=t&&cross(ch.back(),ch[ch.size()-2])>cross(i,ch.back()))ch.pop_back();
            ch.eb(i);
        }
        ch.pop_back();
        return ch;
    }
    vi res;
    rep(i,2)res.pb(i);
    return res;
}
int main(){
    ll n;cin>>n;
    if(n==2){
        rep(i,n)out(0.5);
        return 0;
    }
    vector<PP> v(n);
    x=vi(n);y=vi(n);id=vi(n);
    rep(i,n)cin>>get<0>(v[i])>>get<1>(v[i]);
    rep(i,n)get<2>(v[i])=i;
    sort(all(v));
    rep(i,n)tie(x[i],y[i],id[i])=v[i];
    vi t;
    t=Convex_Hull();
    // outv(t);
    vector<double> ans(n);
    rep(i,t.size()){
        ll j=i-1,k=i+1;
        if(j<0)j+=t.size();
        if(k==t.size())k=0;
        j=t[j];k=t[k];ll p=t[i];
        ll a=dis(k,j),b=dis(p,k),c=dis(p,j);
        double d=(b+c-a)/(2*sqrt(b)*sqrt(c));
        ans[id[p]]=(pi-acos(d))/(2*pi);
    }
    double sum=1;
    rep(i,t.size())sum-=ans[id[t[i]]];
    rep(i,t.size())ans[id[t[i]]]+=sum/t.size();
    decimal;
    for(double x:ans)out(x);
}