#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (ll) (x).size()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
#define int ll
// #define ll int
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 2100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[8] ={1,0,-1,0,1,-1,1,-1};
ll dy[8] ={0,1,0,-1,1,-1,-1,1};
 
template<class T> 
inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> 
inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


void solve(){
    ll n;
    ll x[200010],y[200010];
    char u[200010];
    set<ll> v[200010],w[200010];
    ll ans=LLINF;
    cin>>n;
    rep(i,n){
        cin>>x[i]>>y[i]>>u[i];
    }
    rep(i,n){
        if(u[i]=='D') v[x[i]].insert(y[i]);
        else if(u[i]=='L') w[y[i]].insert(x[i]);
    }
    rep(i,n){
        if(u[i]=='U'){
            if(v[x[i]].lower_bound(y[i])==v[x[i]].end()) continue;
            ll z=*v[x[i]].lower_bound(y[i]);
            chmin(ans,(z-y[i])*5);
        }
        else if(u[i]=='R'){
            if(w[y[i]].lower_bound(x[i])==w[y[i]].end()) continue;
            ll z=*w[y[i]].lower_bound(x[i]);
            chmin(ans,(z-x[i])*5);
        }
    }

    set<pll> a[400010],b[400010];
    set<pll> c[400010],d[400010];
    rep(i,n){
        ll X=x[i]+y[i],Y=x[i]-y[i]+200000;
        if(u[i]=='U'){
            a[X].insert({x[i],y[i]});
            
        }
        else if(u[i]=='D'){
            c[Y].insert({x[i],y[i]});
            
        }
        else if(u[i]=='L'){
            b[X].insert({x[i],y[i]});
            d[Y].insert({x[i],y[i]});

        }
    }
    rep(i,n){
        ll X=x[i]+y[i],Y=x[i]-y[i]+200000;
        if(u[i]=='R'){
            if(a[X].lower_bound({x[i],y[i]})==a[X].end()){}
            else {
                pll z=*a[X].lower_bound({x[i],y[i]});
                chmin(ans,(y[i]-z.sc+z.fi-x[i])*5);
            }

            if(c[Y].lower_bound({x[i],y[i]})==c[Y].end()){}
            else {
                pll z=*c[Y].lower_bound({x[i],y[i]});
                chmin(ans,(z.sc-y[i]+z.fi-x[i])*5);
            }
        }
        else if(u[i]=='U'){
            if(d[Y].lower_bound({x[i],y[i]})==d[Y].end()){}
            else{
                pll z=*d[Y].lower_bound({x[i],y[i]});
                chmin(ans,(z.fi-x[i]+z.sc-y[i])*5);
            }
        }
        else if(u[i]=='D'){
            if(b[X].lower_bound({x[i],y[i]})==b[X].end()){}
            else {
                pll z=*b[X].lower_bound({x[i],y[i]});
                chmin(ans,(z.fi-x[i]+y[i]-z.sc)*5);
            }
        }

    }

   

    if(ans==LLINF) cout<<"SAFE"<<endl;
    else cout<<ans<<endl;





}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    
     

    solve(); 


    return 0;
}
