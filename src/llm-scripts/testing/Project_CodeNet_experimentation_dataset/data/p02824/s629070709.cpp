#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pdd> vdd;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mem(a,b) memset(a, b, sizeof(a) )
#define all(x) (x).begin(),(x).end()
#define INF 1000000000000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    ll n,m,v,p;cin>>n>>m>>v>>p;
    ll t=m*v;
    vl a(n);
    rep(i,n)cin>>a[i];
    sort(all(a));
    int r=n-1,l=0;
    while(r-l>1){
        int mid=(r+l)/2;
        ll sum=(mid+1)*m,now=a[mid]+m;
        if(now<a[n-p]){
            l=mid;
            continue;
        }
        for(int i=mid+1;i<=n-p;++i){
            sum+=now-a[i];
        }
        if(sum+(p-1)*m<t){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    ll ans=r;
    ll sum=(l+1)*m,now=a[l]+m;
    if(now>=a[n-p]){
    for(int i=l+1;i<=n-p;++i){
        sum+=now-a[i];
    }
    if(sum+(p-1)*m>=t){
        ans=l;
    }        
    }
    cout<<n-ans<<endl;
}
