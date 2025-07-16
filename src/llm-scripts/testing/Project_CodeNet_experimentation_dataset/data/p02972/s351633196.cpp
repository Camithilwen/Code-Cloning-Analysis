#include <bits/stdc++.h>
using namespace std;
#define X ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FIXED_FLOAT(x) std::fixed <<std::setprecision(2)<<(x)
 
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
 
// long long p = 1e9+7;
 
typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<int> VI;
typedef vector<pair<ll,ll>> VP;
typedef vector<ll> VL;
typedef vector<bool> VB;
 
// typedef pair<ll, ll> PL;
typedef unordered_map<ll, ll> UMP;
#define FOR(i,b) for(i=0;i<b;i++)
#define pb push_back
#define mp make_pair
 
// typedef  unordered_set<ll>;
 
 
void printa(VI &x,ll n){
    ll i;
    FOR(i, n){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
 
 
/////GLOABLS VARS
ll MOD = 1e9+7;
ll gmx = 1e6+7; 

VL fact(gmx, 1);
//////FUNCTIONS
ll powp(ll val, ll deg)
{
    // debug(val, deg);
    if (!deg)
        return 1;
    if (deg & 1)
        return (powp(val, deg - 1) * val) % MOD;
    ll res = powp(val, deg >> 1);
    // debug(res);
    return (res * res) % MOD;
}





//It is not easy but it can be fun, if you think!!!

//
// ll mx = 2*1e5+7;


int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
        // #ifndef ONLINE_JUDGE
        //     freopen("input.txt", "r", stdin);
        //     freopen("output.txt", "w", stdout);
        //     #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
        // #endif
    ll n,i,j;
    cin>>n;
    // priority_queue<ll> l;
    VL l(n+1);
    FOR(i,n){
        ll u;
        cin>>u;
        l[i+1] = u;
    }
    VL arr(n+1);
    ll m = sqrt(n)+1;
    VL ans;
    for(i=n;i>=1;i--){
        // debug(arr,l);
        if(l[i]!=arr[i]){
            // debug(i);
            ans.pb(i);
            unordered_set<ll> seen; 
            for(j = 1;j<m;j++){
                if(i%j==0){
                    ll p =i/j;
                    // debug(p,j);
                    if(p==j){
                        if(seen.find(p)==seen.end()){
                        arr[p]  =1-arr[p];
                        seen.insert(p);
                    }
                        // ans.pb(p);

                    }
                    else{
                        if(seen.find(p)==seen.end()){
                        arr[p]  =1-arr[p];seen.insert(p);
                    }
                        if(seen.find(j)==seen.end()){
                        arr[j]  =1-arr[j];seen.insert(j);
                    }
                        // ans.pb(p);
                        // ans.pb(j);
                    }
                }
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(auto k:ans){
        cout<<k<<'\n';
    }

    

    // }    
    
}