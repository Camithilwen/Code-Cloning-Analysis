#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define ub upper_bound
#define lb lower_bound
#define all(v) ((v).begin()),((v).end())
#define allr(v) ((v).rbegin()),((v).rend())
#define ff first
#define ss second
#define mp make_pair
#define pll pair<ll,ll> 
#define fo(i,n) for(ll i=0;i<n;i++)
#define foa(i,s,e) for(ll i=(s);i<e;i++)
#define fod(i,s,e) for(ll i= (s);i>=(e);i--)
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define deb(x) cerr<<#x<<' '<<'='<<' '<<x<<'\n'
#define sz(x) (ll)(x.size())
#define ANS cout<<ans<<'\n'
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define Yes cout<<"Yes\n"
#define No cout<<"No\n"
const ld pi = 3.14159265358979323846;
ll MOD = 1e9 + 7;
//ll MOD = 998244353;
const char nl = '\n';
const ll inf = 1e15;
#define fill(a,b) memset(a, b, sizeof(a))
#define setbits(x) __builtin_popcountll(x)
#define print2d(dp,n,m) fo(i, n){fo(j, m)cout<<dp[i][j]<<" ";cout<<"\n";}
ll nxt(){ll x; cin >> x; return x;}
ll mul(ll x,ll y){
    return (1ll* (x%MOD)*(y%MOD));
}
ll modpow(ll x,ll y){ll z=1;while(y>0){if(y%2)z=mul(z,x);x =mul(x,x) ;y/=2;}return z;}
ll power(ll x,ll y){ll z=1;while(y>0){if(y%2)z=z*x;x =x*x ;y/=2;}return z;}
ll gcd(ll a,ll b){if(a<b) return gcd(b,a);if(b==0) return a;return gcd(b,a%b);} 
ll min(ll a,ll b){if(a<b)return a;return b;}
ll max(ll a,ll b){if(a>b)return a;return b;}
ll sq(ll a){
    ll ans = (1ll*a*a);
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    ll mn = inf;
    ll ans = 0;
    fo(i, n){
        ll x;
        cin >> x;
        mn = min(mn ,x);
        if(mn >= x)ans++;
    }
    ANS;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt" , "r" , stdin) ;
    freopen("outputf.txt" , "w" , stdout) ;
    freopen("error.txt" , "w" , stderr) ;
    #endif
    ll TC = 1;
    //cin>>TC;
    while(TC--){
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
