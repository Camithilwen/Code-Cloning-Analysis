#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f(a, b) for (ll i = a; i <= b; i++)
#define pb push_back
#define pf push_front
#define mp make_pair
using namespace std;
#define N 200005
const ll INF = 1000000000000000001;
const ll MOD = 1000000000;

//vector< vector<ll> > g(N);
//vector< pair<ll, pair< ll, ll > > > g(N);
//ll vis[N] = {0}, par[N] = {0}, child[N] = {0},cnt = 0;


void solve(){
    ll n; cin >> n;
    ll ans =0;
    ll a[n] ;
    f(0, n-1) cin >> a[i];
    f(1, n-1){
        if(a[i] < a[i-1]) ans += a[i-1]-a[i], a[i] += (a[i-1]-a[i]);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    //ll t;cin >> t;for(ll index=1; index<=t; index++){
        //cout << "Case #" << index << ": " ;
        solve();
    //}
    return 0;
}