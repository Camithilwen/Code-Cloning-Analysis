#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define ld long double
#define pb push_back
#define pll pair<ll, ll> 
#define vl vector<ll> 
#define vvl vector< vector<ll> > 
#define vlp vector< pair<ll, ll> >
#define vllp vector<pair<pll, ll> > 
#define mll map<ll, ll> 
#define rep(i,a)  for(ll i=0; i< a; i++)
#define rep1(i,a)   for(ll i = 1; i< a; i++)
#define foi(i, a, b)    for(ll i = a; i<b ; i++)
#define fod(i, a, b)    for(ll i = a; i>=b ; i--)
#define mp make_pair
#define all(v)  (v).begin(), (v).end()
#define fst first
#define sec second
#define ff first.first
#define fs first.second
#define max3(a, b, c)   max(max(a, b), c)
#define min3(a, b, c)   min(min(a, b), c)
#define MAX 1000001
#define MOD 1000000007
// #define MOD 998244353
#define endl "\n"
#define INF (ll)1e18
#define s(v) (ll)v.size()
#define e(v) v.empty()
#define bscount(x) __builtin_popcountll(x)
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
// using namespace __gnu_pbds;

ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
ll fexp(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%MOD; b/=2;a=a*a%MOD;}return ans;}
ll inverse(ll a, ll p){return fexp(a, p-2);} 
void ingraph(vvl& graph, ll m){ll x, y;rep(i, m){cin>>x>>y;x--, y--;graph[x].pb(y);graph[y].pb(x);}}
ll modify(ll n){ll res = n;res%=MOD;res+=MOD;res%=MOD;return res;}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        ll n, m, v, p;
        cin>>n>>m>>v>>p;
        vl vec(n);
        rep(i, n)   cin>>vec[i];
        sort(all(vec));
        vl pref(n);
        ll cur = 0;
        rep(i, n){
            cur += vec[i];
            pref[i] = cur;
        }
        ll ans = 0;
        rep(i, n){
            ll nv = v;
            nv -= (i+1);
            bool poss = false;
            ll j = upper_bound(all(vec), vec[i] + m) - vec.begin();
            if(n - j >= p)  continue;
            else{
                nv -= (n - j);
                if(v <= 0)  {ans++;poss = true;}
                else{
                    ll np = p - (n - j) - 1;
                    if(j - i - 1 <= np) ans++;
                    else{
                        nv -= np;
                        ll del = (j - np - 1 - i)*(vec[i] + m) - (pref[j-np-1] - pref[i]);
                        if(del >= nv*m) ans++;
                    }
                }
            }
        }
        cout<<ans;
    }
}