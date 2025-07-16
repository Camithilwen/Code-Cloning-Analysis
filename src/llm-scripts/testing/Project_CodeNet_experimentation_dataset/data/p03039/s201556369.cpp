#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

ll s[200005],t[200005];

ll mod_pow(ll x,ll n,ll m){
    if(n==0) return 1;
    ll res=mod_pow(x*x%m,n/2,m);
    if(n&1) res=res*x%m;
    return res;
}

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll A=n*m;
    ll B=A-2;
    ll ans=0;
    ll cnt=1;
    ll c;
    ll ma=n+m-2;
    s[0]=t[0]=0;
    for(ll i=1;i<=ma+2;i++){
        s[i]=i*(i+1)/2;
        t[i]=i*(i+1)*(i+2)/6;
    }
    for(ll i=0;A-2-i>A-k;i++) cnt=(cnt*(A-2-i))%mod;
    for(ll i=2;i<=k-2;i++) cnt=(cnt*mod_pow(i,mod-2,mod))%mod;
    c=cnt;
    ll i=1,j=1;
    while(true){
        ll now=0;
        now=(now+s[m-j])%mod;
        if(j==1){
            now=(now+(t[m-j+n-i]-t[m-j]-t[n-i-1])%mod)%mod;
        }else if(j==m){
            now=(now+(t[j+n-i-1]-t[j-1]-t[n-i-1])%mod)%mod;
        }else{
            now=(now+(t[m-j+n-i]-t[m-j]-t[n-i-1])%mod)%mod;
            now=(now+(t[j+n-i-1]-t[j-1]-t[n-i-1])%mod)%mod;
            now-=s[n-i];
            while(now<0) now=now+mod;
        }
        ans=(ans+(now*cnt)%mod)%mod;
        if(j==m){
            i++;j=1;
        }else{
            j++;
        }
        if(i==n&&j==m) break;
    }
    cout<<ans<<endl;
}