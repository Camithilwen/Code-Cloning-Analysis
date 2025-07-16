#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip> 
#include <algorithm>
#include <queue>
#include <list>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
 
using namespace std;
 
#define sz(a) int((a).size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define endl '\n'
#define watch(x) cout << #x << " : " << x << endl;
 
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef vector<ii> vii;
 
const int N = int(2e5)+10;
const int K = 10005;
// const int MOD = int(1e9)+7;
const int INF = int(1e9)+5;
const ll INF64 = 1e18;

const ll MOD = 998244353;
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }

ll inv[N],fact[N],ifact[N];

//! Modular Exponentiation.
ll modpow (ll x,ll n) {
    if (n == 0ll) return 1ll;
    ll u = modpow(x,n/2);
    u = mul(u,u,MOD);
    if (n % 2 == 1) u = mul(u,x,MOD);
    return u;
}

void pre () {
    inv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    for (int i=2;i<N;i++) {
        inv[i] = mul(MOD - MOD / i, inv[MOD % i], MOD);
        fact[i] = mul(i * 1ll, fact[i - 1], MOD);
        ifact[i] = mul(inv[i], ifact[i - 1], MOD);
    }
    return;
}

ll nCr (ll n,ll r) {
    if (n >= 0 && r >= 0 && n >= r) {
        return mul(fact[n],mul(ifact[r],ifact[n-r],MOD),MOD);
    }
    return 0;
}

void solve () {
    pre();
    ll n,m,k;cin>>n>>m>>k;
    ll ans = 0;
    // k1 are same as left.
    for (int k1=0;k1<=k;k1++) {
        // n-1Ck1 * m * (m-1) ^ (n-1-k1).
        ll temp = nCr(n-1,k1);
        temp = mul(temp,m,MOD);
        temp = mul(temp,modpow(m-1,n-1-k1),MOD);
        ans = add(ans,temp,MOD);
    }
    cout<<ans<<endl;
}

int main () {
    FastIO
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t;
    // cin>>t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}